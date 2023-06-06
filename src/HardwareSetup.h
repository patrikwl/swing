#include <avr/io.h>

#include "ISpiConfigGetter.h"
#include "IUartConfigGetter.h"

// SPI
#define SpiAdxlCsPinPort DDRD
#define SpiAdxlCsPin PINB2
#define SpiMosiPin PINB3
#define SpiMisoPin 0
#define SpiSckPin PINB5
#define SpiOscDevider ISpiConfigGetter::SpiFrequency::FOSC_2

// UART
#define UartTxPin PIND3
#define UartBaudrate IUartConfigGetter::UartBaudRate::br115200
#define UartFramesize IUartConfigGetter::UartFrameSize::EightBit

// Uncategorized
#define LedDataDirectionRegister DDRB
#define LedPinPort PORTB
#define LedPin PB0
