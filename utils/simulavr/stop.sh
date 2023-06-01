#!/bin/bash
ps -a | awk '/simulavr/ {print $1}' | xargs kill

exit 0
