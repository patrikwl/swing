#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include <something.h>

extern "C" {
#include "../include/lcd.h"
#include <string.h>
}

int main(void)
{
   Something something;
   lcd_init(LCD_DISP_ON);

   while (1) {
      PORTB |= (1 << PB0); // LED ON
      _delay_ms(1000);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(1000);
      uint8_t asd = something.getInt();
   }
}
