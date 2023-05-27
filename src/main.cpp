#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "RegisterAccessor.h"
#include "ISpiAdapter.h"
#include "SpiAdapter.h"
#include "SpiHandler.h"


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
   SpiAdapter spiAdapter{&registerAccessor};
   ISpiAdapter::SpiConfig spiConf(ISpiAdapter::SpiFrequency::FOSC_8, PINB2, PINB3, PINB4, PINB5);
   spiAdapter.configure(spiConf);
   SpiHandler spiHandler{&spiAdapter};
   sei();
   while (1) {
      PORTB |= (1 << PB0); // LED ON
      _delay_ms(1000);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(1000);
   }
}
