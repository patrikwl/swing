// #include <avr/signature.h>
#include "AccelerometerHandler.h"
#include "Adxl345ConfigGetter.h"
#include "RegisterManager.h"
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
IUartManager *uartManager;
int main(void)
{
   RegisterManager registerManager;
   ConfigGetter configurations;
   UartAdapter uartAdapter{&registerManager, &configurations};
   UartManager uartManagerInstance(&uartAdapter);
   uartManager = &uartManagerInstance;

   SpiAdapter spiAdapter{&registerManager, &configurations};
   SpiHandler spiHandler{&spiAdapter};
   Adxl345ConfigGetter adxlConfigGetter;
   AccelerometerHandler acceleratorHandler{&adxlConfigGetter, &spiHandler, &registerManager};
   sei();
   volatile char in_char;
   const char *litLed = "motor on";
   const char *downLed = "motor off";
   char buffer[32];
   int testDataToSebnd = 1337;
   sprintf(buffer, "ALO %u", testDataToSebnd);
   // LOGGER_DEBUG("message");
   registerManager.setBit(DDRB, PB0);
   while (1) {
      registerAccessor.setBit(PORTB, PB0);
      LOGGER_DEBUG(litLed);
      _delay_ms(500);
      LOGGER_DEBUG(downLed);
      registerAccessor.clearBit(PORTB, PB0);
      _delay_ms(5000);
   }
}
