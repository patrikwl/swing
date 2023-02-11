#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include "Isomething.h"

int main(void)
{
   while (1) {
      PORTB |= (1 << PB0); // LED ON
      _delay_ms(1000);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(1000);
      uint8_t asd = 6;
   }
}
