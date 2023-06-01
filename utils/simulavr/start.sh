#!/bin/bash
/home/dev/external-repos/simulavr/build/app/simulavr -d atmega328 -f /workspaces/swing/build/src/swing_atmega328.elf  -W 0x20,- -R 0x22,- -T exit -F 8000000 -g
exit 0
