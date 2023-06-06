#include "UartAdapter.h"
#include "IUartAdapter.h"
#include <avr/io.h>
#include <stdio.h>

UartAdapter::UartAdapter(IRegisterManager *theRegisterManager, IUartConfigGetter *theConfigGetter)
    : registerAccessor(theRegisterManager), configGetter(theConfigGetter)
{
   init();
}

void UartAdapter::init()
{
   // Enable UART receiver module
   registerAccessor->setBit(UCSR0B, TXEN0);
   setCharacterSize();
   setIOPorts();
   setBaudRate();
}

void UartAdapter::setBaudRate()
{
   switch (configGetter->getBaudRate()) {
      case (IUartConfigGetter::UartBaudRate::br115200):
         registerAccessor->clearBit(UCSR0A, U2X0);
         uint16_t ubrrValue = F_CPU / (16UL * 115200) - 1;
         UBRR0H = (ubrrValue >> 8) & 0xFF;
         UBRR0L = (ubrrValue)&0xFF;
         break;
      defualt:
         break;
   };
}

void UartAdapter::setIOPorts()
{
   // Set OI port(s)
   registerAccessor->setBit(DDRD, configGetter->getTxPin());
   registerAccessor->setBit(PORTD, configGetter->getTxPin());
}

void UartAdapter::setCharacterSize()
{
   switch (configGetter->getFrameSize()) {
      case (IUartConfigGetter::UartFrameSize::EightBit):
         registerAccessor->setBit(UCSR0C, UCSZ00);
         registerAccessor->setBit(UCSR0C, UCSZ01);
         registerAccessor->clearBit(UCSR0B, UCSZ02);
         break;
      default:
         // not implemented
         break;
   }
}

void UartAdapter::waitForEmptyTransmitBuffer()
{
   while (!(UCSR0A & (1 << UDRE0))) {
   }
}
void UartAdapter::putChar(const char &data) { UDR0 = data; }
