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

// TODO fixa register-bitPost struct i hela projektet
// TODO uppdatera alla confGetters see: "volatile uint8_t &getCsPortRegister() override;""
// TODO unittest för adapters efter ovan
// TODO Kolla reg MCUCR om pull-up/down inte behövs
// TODO Fixa en logger class som ligger i global istället för att exponera uartManager

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
   registerManager.setBit(configurations.getLedDataDirectionReg());
   while (1) {
      registerManager.setBit(configurations.getLedPin());
      LOGGER_DEBUG(litLed);
      _delay_ms(500);
      acceleratorHandler.setBypassMode();
      registerManager.clearBit(configurations.getLedPin());
      _delay_ms(5000);
      LOGGER_DEBUG(downLed);
   }
}
