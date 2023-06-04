#include <avr/io.h>

#include "ISpiConfigGetter.h"
#include "IUartConfigGetter.h"

#define SpiCsPin PINB2
#define SpiMosiPin PINB3
#define SpiMisoPin 0
#define SpiSckPin PINB5
#define SpiOscDevider ISpiConfigGetter::SpiFrequency::FOSC_8

#define UartTxPin PIND3
#define UartBaudrate IUartConfigGetter::UartBaudRate::br115200
#define UartFramesize IUartConfigGetter::UartFrameSize::EightBit
