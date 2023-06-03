#!/bin/bash

cd /workspaces/swing/build
cmake ..
make


if [ -e /workspaces/swing/build/src/swing_atmega328-eeprom.hex ]; then
#unittest
echo 'Building unittest'
cd ../test/build
make
cd ../../build/src
echo 'Running unittest'
./MY_TESTS
else
echo 'Error: stopping build.sh'
echo "Error: did not find \"workspaces/swing/build/src/swing_atmega328-eeprom.hex\""
fi
