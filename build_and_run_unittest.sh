#!/bin/bash

mkdir -p /workspaces/swing/build/src
cd  /workspaces/swing/build

#unittest
echo 'Building unittest'

mkdir -p /workspaces/swing/test/build/
cd /workspaces/swing/test/build/
rm -r /workspaces/swing/test/build/*
cmake ..
make
if ! [ $? -eq 0 ]; then
    echo -e "\033[31mFailed to build gtest.\033[0m"
    exit 1
fi
cd ../../build/src
echo 'Running unittest'
./MY_TESTS

if ! [ $? -eq 0 ]; then
    echo -e "\033[31mUnit tests failed. \033[0m"
    exit 1
fi
