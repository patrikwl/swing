// #include <avr/signature.h>
#include "ISpiAdapter.h"
#include "IUartAdapter.h"
#include "RegisterAccessor.h"
#include "SpiAdapter.h"
#include "SpiHandler.h"
#include "UartAdapter.h"
#include "src/UartManager.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include <string.h>

/* This port corresponds to the "-W 0x20,-" command line option. */
#define special_output_port (*((volatile char *)0x20))
/* This port corresponds to the "-R 0x22,-" command line option. */
#define special_input_port (*((volatile char *)0x22))
/* Poll the specified string out the debug port. */
void debug_puts(const char *str)
{
   const char *c;

   for (c = str; *c; c++)
      special_output_port = *c;
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
   UartManager uartManager{&uartAdapter};
   SpiAdapter spiAdapter{&registerAccessor};
   ISpiAdapter::SpiConfig spiConf(ISpiAdapter::SpiFrequency::FOSC_8, PINB2, PINB3, PINB4, PINB5);
   spiAdapter.configure(spiConf);
   SpiHandler spiHandler{&spiAdapter};
   sei();
   volatile char in_char;

   const char *litLed = "turning on led \n";
   const char *downLed = "turning off led \n";

   /* Output the prompt string */
   debug_puts("\nPress any key and enter:\n");

   /* Input one character but since line buffered, blocks until a CR. */
   //   in_char = special_input_port;

   /* Print the "what you entered:" message. */
   debug_puts("\nYou entered:");

   /* now echo the rest of the characters */

   //   do {
   //     special_output_port = in_char;
   //   } while((in_char = special_input_port) != '\n');

   char buffer[32];
   int testDataToSebnd = 1337;
   sprintf(buffer, "ALO %u", testDataToSebnd);
   debug_puts(buffer);

   special_output_port = '\n';
   while (1) {
      PORTB |= (1 << PB0); // LED ON
      uartManager.transmitString(litLed);
      _delay_ms(2000);
      uartManager.transmitString(downLed);
      PORTB &= ~(1 << PB0); // LED OFF ok
      _delay_ms(2000);
   }
}
