#include "IEventLoop.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <cstddef>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include <EventLoop.h>
#include <something.h>
#include <string>
extern "C" {
#include "../external-libs/lcd.h"
}

void foo()
{
   PORTB |= (1 << PB0); // LED ON
   _delay_ms(1000);
   PORTB &= ~(1 << PB0); // LED OFF ok
   _delay_ms(1000);
}

int main(void)
{
   EventLoop eventLoop;
   while (1) {
      if (eventLoop.queue_pending()) {
         eventLoop.handle_event();
      }
      else {
         EventLoop::Event *eventPtr = new EventLoop::Event{1, reinterpret_cast<void *>(&foo)};
         // eventLoop.add_event(&eventLoop, &);
      }
   }
}
