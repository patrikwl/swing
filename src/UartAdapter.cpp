#include "UartAdapter.h"
#include "IUartAdapter.h"
#include <avr/io.h>
#include <stdio.h>

UartAdapter::UartAdapter(IRegisterAccessor *theRegisterAccessor) : registerAccessor(theRegisterAccessor)
{
   // Enable UART receiver
   registerAccessor->setBit(UCSR0B, TXEN0);

   registerAccessor->setBit(UCSR0C, UCSZ01);
   registerAccessor->setBit(UCSR0C, UCSZ00);
   // registerAccessor->clearBit(UCSR0C, UCSZ02); 0 by default
}

void UartAdapter::configure(IUartAdapter::UartConfig &conf)
{

   DDRD |= (1 << PD1);  // Set PD1 as output
   PORTD |= (1 << PD1); // Set PD1 to high (idle state)

   switch (conf.baudRate) {
      case (IUartAdapter::UartBaudRate::br115200):
         registerAccessor->clearBit(UCSR0A, U2X0);
         uint16_t ubrrValue = F_CPU / (16UL * 115200) - 1;
         UBRR0H = (ubrrValue >> 8) & 0xFF;
         UBRR0L = (ubrrValue)&0xFF;
         break;
      defualt:
         break;
   };
}

void UartAdapter::waitForEmptyTransmitBuffer()
{
   while (!(UCSR0A & (1 << UDRE0))) {
   }
}
void UartAdapter::putChar(const char &data) { UDR0 = data; }
