FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y \

    wget \
    sudo \
    vim \
    clangd \
    usbutils \
    clang-format \
    git \
    file \
    libgtest-dev \

    cmake \
    ccache \
    gcc-avr \
    avr-libc \
    # binutils-avr \

    gdb-avr \
    libelf-dev \

    avrdude \
    python3 \
    python3-pip

RUN pip3 install pre-commit
RUN git config --global core.editor vim

#TODO add non-root user
RUN useradd -ms /bin/bash dev
RUN usermod -aG sudo dev && echo "dev ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/dev
RUN chmod 0440 /etc/sudoers.d/dev
RUN usermod -a -G dialout dev

RUN mkdir -p /home/dev/external-repos/simulavr
RUN git clone https://git.savannah.nongnu.org/git/simulavr.git /home/dev/external-repos/simulavr
WORKDIR /home/dev/external-repos/simulavr
    RUN git checkout 32985f745c237bf8dcd2718235d01c8b1fb0491d
    RUN mkdir -p /home/dev/external-repos/simulavr/build
WORKDIR /home/dev/external-repos/simulavr/build
    RUN cmake install ..
    RUN make


USER dev
