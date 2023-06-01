// #include <avr/signature.h>
#include "ISpiAdapter.h"
#include "IUartAdapter.h"
#include "RegisterAccessor.h"
#include "SpiAdapter.h"
#include "SpiHandler.h"
#include "UartAdapter.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

extern "C" {
// #include "../include/lcd.h"
#include <string.h>
}

ISR(INT1_vect)
{
   PORTB |= (1 << PB0); // LED ON
   _delay_ms(1000);
   PORTB &= ~(1 << PB0); // LED OFF ok
   _delay_ms(1000);
}

int main(void)
{
   RegisterAccessor registerAccessor;
   UartAdapter uartAdapter{&registerAccessor};
   IUartAdapter::UartConfig uartConf(IUartAdapter::UartBaudRate::br115200, PIND3);
   uartAdapter.configure(uartConf);
   SpiAdapter spiAdapter{&registerAccessor};
   ISpiAdapter::SpiConfig spiConf(ISpiAdapter::SpiFrequency::FOSC_8, PINB2, PINB3, PINB4, PINB5);
   spiAdapter.configure(spiConf);
   SpiHandler spiHandler{&spiAdapter};
   sei();
   while (1) {
      PORTB |= (1 << PB0); // LED ON
      _delay_ms(2000);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(2000);
   }
}
