#!/usr/bin/env python3

# upload.py - Firmware updater for the bootloader in this repository

# Copyright (C) 2018 EmbeddedEnterprises
# Martin Koppehel <martin.koppehel@st.ovgu.de>

# This software may be modified and distributed under the terms
# of the MIT license.  See the LICENSE file for details.

import argparse
import binascii
import math
import serial
import struct
import sys

parser = argparse.ArgumentParser(description='Upload a hexfile using our bootloader')
parser.add_argument('--version', '-V', help='Display version which doesn\'t exist', action='store_true')
parser.add_argument('--verbose', '-v', help='Display unneccessary output you won\'t understand', action='store_true')
parser.add_argument('--bl-size', help='Bootloader Size (ensures that the memory area will not be overwritten)', default='0x400', type=str)
parser.add_argument('--fl-size', help='Flash Size (ensures that only existent flash will be written)', default='0x4000', type=str)
parser.add_argument('--bl-init', help='Sequence to reboot to the bootloader (hexstring)', type=str)
parser.add_argument('--strict', '-s', help='Exit in case a memory conflict is detected.', action='store_true')
parser.add_argument('--page-size', help='Flash page size, usualle 64 byte', default='64')
parser.add_argument('serial', metavar='PORT', type=str, nargs='?', help='The serial port to use', default='/dev/ttyUSB0')
parser.add_argument('hexfile', metavar='HEX', type=str, nargs='?', help='The hex file to upload', default='main.hex')
args = parser.parse_args()

print('UART-Bootloader Upload-Tool')
if args.version:
    print('(c) Martin Koppehel 2018')
    print('(c) EmbeddedEnterprises 2018')
    print('Version 0.1.0')
    sys.exit(0)

if args.verbose:
    print('You asked for unneccessary information. (-v)')
    if args.strict:
        print('Strict mode enabled, checking memory accesses.')

flashmin = int(args.bl_size, 0)
flashmax = int(args.fl_size, 0)
pagesize = int(args.page_size, 0)
if args.verbose:
    print(f'Valid flash range: {flashmin} to {flashmax}')

with open(args.hexfile, 'r') as hex_file:
    hex_content = hex_file.readlines()

if args.verbose:
    print(f'Read hexfile with {len(hex_content)} lines')

memory_view = bytearray(flashmax)
index = 0
global_offset = 0
last_addr = 0
for line in hex_content:
    line = line.strip()
    if line[0] != ':':
        print(f'Invalid hexfile: Expected \':\' at {index}:0')
        sys.exit(1)
    chksum = 0
    for i in range(1, len(line) - 2, 2):
        chksum += int(line[i:i+2], 16)
    chksum = (((~(chksum & 0xFF)) & 0xFF) + 1) & 0xFF
    if chksum != int(line[-2:], 16):
        print(f'Checksum failed on line: {index}, expected: {chksum}, got: {int(line[-2:], 16)}')
        sys.exit(3)

    payload_len = int(line[1:3], 16)
    payload_offset = int(line[3:7], 16)
    rectype = int(line[7:9], 16)
    if rectype == 1:
        if args.verbose:
            print('Hexfile end')
        break
    if rectype > 1:
        if args.verbose:
            print(f'unknown rectype: {rectype:02X}, ignoring.')
        continue
    for i in range(0, payload_len):
        addr = global_offset + payload_offset + i
        if args.strict and addr < flashmin and rectype == 0:
            print(f'Hexfile contains data within the bootloader section (line: {index})')
            sys.exit(2)
        if args.strict and addr >= flashmax and rectype == 0:
            print(f'Hexfile contains data after the end of the flash (line: {index})')
            sys.exit(2)
        start_idx = 9 + 2 * i
        end_idx = start_idx + 2
        cur_addr = payload_offset + global_offset + i
        memory_view[cur_addr] = int(line[start_idx:end_idx], 16)
        last_addr = max(last_addr, cur_addr)
    index += 1


if args.verbose:
    print(f'Got {last_addr - flashmin} bytes of data')
no_pages = math.ceil(last_addr / pagesize)
last_addr = no_pages * pagesize
no_pages -= math.floor(flashmin / pagesize)
if args.verbose:
    print(f'Padded data to {flashmin-last_addr:05} bytes ({no_pages} pages)')

print(f'Flashing your device.')
index = 1
cur_page = flashmin
with serial.Serial(args.serial, 57600, timeout=3) as port:
    if args.bl_init:
        init_seq = bytes.fromhex(args.bl_init)
        if args.verbose:
            print('Sending init sequence: {binascii.hexlify(init_seq)}')
        port.write(init_seq)
        resp = port.read()
        if resp != b'\x01':
            print('Failed to trigger bootloader, maybe your init sequence isn\'t matching?')
            sys.exit(4)
    elif args.verbose:
        print('Assuming bootloader is present.')

    while cur_page != last_addr:
        if args.verbose:
            print(f'SOF -> 0xa0')
        port.write(b'\xa0')
        if port.read() != b'\x55':
            print('No ACK for SOF. Exiting.')
            sys.exit(4)
        elif args.verbose:
            print(f'SOF <- ACK')

        if args.verbose:
            print(f'ADDR-> 0x{cur_page & 0xFF:02X}{(cur_page >> 8) & 0xFF:02X}{(cur_page >> 16) & 0xFF:02X}{(cur_page >> 24) & 0xFF:02X}')
        addr = struct.pack('<I', cur_page)
        port.write(addr)
        if port.read() != b'\x55':
            print('No ACK for ADDR. Exiting.')
            sys.exit(4)
        elif args.verbose:
            print(f'ADDR<- ACK')

        if args.verbose:
            print(f'DATA-> {binascii.hexlify(memory_view[cur_page:cur_page+pagesize])}')
        port.write(bytes(memory_view[cur_page:cur_page+pagesize]))
        if port.read() != b'\x55':
            print('No ACK for DATA. Exiting.')
            sys.exit(4)
        elif args.verbose:
            print(f'DATA<- ACK')

        chksum = binascii.crc32(memory_view[cur_page:cur_page+pagesize]) & 0xFFFFFFFF
        if args.verbose:
            print(f'CHK -> {chksum:08X}')
        port.write(struct.pack('<I', chksum))
        if port.read() != b'\x77':
            print('No ACK for CHK. Exiting.')
            sys.exit(4)
        elif args.verbose:
            print(f'CHK <- ACK')

        if port.read() != b'\x55':
            print('Flash failed. Exiting.')
            sys.exit(4)
        print(f'Page {index}/{no_pages} written.')
        elif args.verbose:
            print('-'*80)
        cur_page+=pagesize
        index += 1

    if args.verbose:
        print(f'Rebooting device.')
    port.write(b'\xa2')

print('Finished.')
