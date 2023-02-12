#include <avr/interrupt.h>
#include <avr/io.h>
// #include <cstdint>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include <something.h>

int main(void)
{
   Something something;
   while (1) {
      PORTB |= (1 << PB0); // LED ON
      _delay_ms(1000);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(1000);
      __attribute__((unused)) uint8_t asd = something.getInt();

      __attribute__((unused)) static char bar[10000];
      int top = 1000;
      for (int i = 0; i < top; i++) {
         bar[i] = (char)0;
      }
   }

   return 0;
}
