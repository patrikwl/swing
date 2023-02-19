FROM ubuntu


RUN apt-get update \
    && apt-get install -y \

    wget \
    sudo \
    vim \
    clangd \
    clang-format \
    git \
    libgtest-dev \

    cmake \
    ccache \
    gcc-avr \
    avr-libc \
    # binutils-avr \

    gdb-avr \
    libelf-dev \

    avrdude \
    #libusb
    python3 \
    python3-pip

RUN pip3 install pre-commit
RUN git config --global core.editor vim

    #simavr
#TODO add non-root user
RUN useradd -ms /bin/bash dev
RUN usermod -aG sudo dev && echo "dev ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/dev
RUN chmod 0440 /etc/sudoers.d/dev

RUN mkdir /workspace
WORKDIR /workspace
USER dev
