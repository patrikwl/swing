# Simulavr notes

## main page
https://savannah.nongnu.org/projects/simulavr

## git repo
https://git.savannah.nongnu.org/cgit/simulavr.git

Note: unset CXX in order to compile

## Example

https://www.nongnu.org/simulavr/simple_ex.html


## start simulavr server
/home/dev/external-repos/simulavr/build/app/simulavr -d atmega328 -f /workspaces/swing/build/src/swing_atmega328.elf  -W 0x20,- -R 0x22,- -T exit -F 8000000 -g

## start gdb
avr-gdb -x /workspaces/swing/utils/simulavr/avr-gdb.conf

## Test
