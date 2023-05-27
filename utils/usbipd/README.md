## sources
https://github.com/dorssel/usbipd-win/releases
https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/


## Installation
unzip (usbipd-win_2.4.1.zip) and install in windows

## In wsl
sudo apt install linux-tools-5.4.0-77-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/5.4.0-77-generic/usbip 20

## in admin cmd windows:
usbipd wsl list

You should see
"3-3    16c0:05dc  USBasp    Not attached"
if your USBasp programmer is connected to your pc.

## prompt the USBasp interace <busid>:
usbipd wsl attach --busid <busid>

From above the <busid> would be 3-3.

## in wsl you should see the interace
dmesg | grep -i usb (or lsusb)

This would prompt:
...
[ 1484.542541] usb 1-1: new low-speed USB device number 2 using vhci_hcd
[ 1484.732429] usb 1-1: SetAddress Request (2) to port 0
[ 1484.775989] usb 1-1: New USB device found, idVendor=16c0, idProduct=05dc, bcdDevice= 1.04
[ 1484.775995] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[ 1484.775997] usb 1-1: Product: USBasp
[ 1484.775999] usb 1-1: Manufacturer: www.fischl.de

## Ping MCU
With the atmega328 connected to usbasp board (see /doc/labb_02.pdf) prompt in dev-container terminal:
sudo avrdude -B 5 -c usbasp -p m328

and you should see
"avrdude: AVR device initialized and ready to accept instructions"

Note:
Probably need to restart the container for effect after insall.

## To flash
Build project:

./build.sh

Cd to binary catalogue

cd /workspaces/swing/build/src

To flash

sudo avrdude -c usbasp -p m328 -B 5 -U flash:w:"swing_atmega328p.hex":a -U lfuse:w:0xE2:m -U hfuse:w:0xDA:m -U efuse:w:0xFD:m

Options, see
https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
