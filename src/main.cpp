// #include <avr/signature.h>
#include "RegisterAccessor.h"
#include "SpiAdapter.h"
#include "SpiHandler.h"
#include "UartAdapter.h"
#include "logger.h"
#include "src/UartManager.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "ConfigGetter.h"

#include <string.h>

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
   ConfigGetter configurations;
   UartAdapter uartAdapter{&registerAccessor, &configurations};
   UartManager uartManager{&uartAdapter};
   SpiAdapter spiAdapter{&registerAccessor, &configurations};
   SpiHandler spiHandler{&spiAdapter};
   sei();
   volatile char in_char;
   const char *litLed = "turning on led";
   const char *downLed = "turning off led";
   char buffer[32];
   int testDataToSebnd = 1337;
   sprintf(buffer, "ALO %u", testDataToSebnd);
   LOGGER_DEBUG("message");
   while (1) {
      registerAccessor.setBit(PORTB, PB0); // LED ON
      LOGGER_DEBUG(litLed);
      _delay_ms(2000);
      LOGGER_DEBUG(downLed);
      registerAccessor.clearBit(PORTB, PB0); // LED ON
      _delay_ms(2000);
   }
}
