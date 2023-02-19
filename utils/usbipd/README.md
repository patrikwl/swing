## sources
https://github.com/dorssel/usbipd-win/releases
https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/


## Installation
unzip and install in windows

## In wsl
sudo apt install linux-tools-5.4.0-77-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/5.4.0-77-generic/usbip 20

## in admin cmd windows:
usbipd wsl list

## prompt the USBasp interace <busid>:
usbipd wsl attach --busid <busid>

## in wsl you should see the interace
lsusb
