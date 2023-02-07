FROM ubuntu


RUN apt-get update \
    && apt-get install -y \
    git \
    cmake \
    gcc-avr \
    avr-libc \

    gdb-avr \ 
    libelf-dev \
    #binutils

    avrdude
    libusb

RUN mkdir /workspace
WORKDIR /workspace

