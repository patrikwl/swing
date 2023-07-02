## build

mkdir build && cd build
cmake ../
make


## Read UART log

For example with microcom

```
sudo microcom --port=/dev/ttyUSB0 --speed=115200
```
