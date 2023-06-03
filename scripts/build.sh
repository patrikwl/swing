#!/bin/bash

mkdir -p /workspaces/swing/build/src
sudo chmod -R 777 /workspaces/swing/build/

rm -r /workspaces/swing/build/*
cd  /workspaces/swing/build
cmake ..
make
if ! [ $? -eq 0 ]; then
    echo -e "\033[31mFailed to build target bin. Aborting flash.\033[0m"
    exit 1
fi

echo 'Building unittest'
mkdir -p /workspaces/swing/test/build/
sudo chmod -R 777 /workspaces/swing/test/build/
rm -r /workspaces/swing/test/build/*
cd /workspaces/swing/test/build/
cmake ..
make
if ! [ $? -eq 0 ]; then
    echo -e "\033[31mFailed to build gtest.\033[0m"
    exit 1
fi
echo 'Running unittest'
/workspaces/swing/build/src/MY_TESTS
if ! [ $? -eq 0 ]; then
    echo -e "\033[31mUnit tests failed. \033[0m"
    exit 1
fi
