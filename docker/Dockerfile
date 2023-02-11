FROM ubuntu


RUN apt-get update \
    && apt-get install -y \
    git \
    cmake \
    gcc-avr \
    avr-libc \

    gdb-avr \ 
    libelf-dev \

    avrdude\
    libusb\

    simavr

RUN mkdir /workspace
WORKDIR /workspace

