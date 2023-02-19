#!/bin/bash

cd /workspaces/swing/build
cmake ..
make


if [ -e /workspaces/swing/build/src/swing_atmega328p-eeprom.hex ]; then
#unittest
echo 'Building unittest'
cd ../test/build
make
cd ../../build/src
echo 'Running unittest'
./MY_TESTS
else
echo 'Error: stopping build.sh'
fi
