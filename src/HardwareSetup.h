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
#define UartTxDataDirectionRegister DDRD
#define UartTxPinPort PORTD
#define UartTxPin PIND3
#define UartControlAndStatusRegisterB UCSR0B
#define UartControlAndStatusRegisterC UCSR0C
#define UartControlAndStatusRegisterA UCSR0A
#define UartTransmitterEnable TXEN0
#define UartDoubleSpeed U2X0
#define UartBaudRateRegisterLow UBRR0L
#define UartBaudRateRegisterHigh UBRR0H

#define UartCharSizeZero UCSZ00
#define UartCharSizeOne UCSZ01
#define UartCharSizeTwo UCSZ02

#define UartDataRegisterEmpty UDRE0
#define UartDataRegister UDR0

#define UartBaudrate IUartConfigGetter::UartBaudRate::br115200
#define UartFramesize IUartConfigGetter::UartFrameSize::EightBit

// Uncategorized
#define LedDataDirectionRegister DDRB
#define LedPinPort PORTB
#define LedPin PB0
