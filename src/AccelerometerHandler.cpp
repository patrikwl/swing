#include "AccelerometerHandler.h"
#include "logger.h"
#include <stdio.h>
#include <string.h>

AccelerometerHandler::AccelerometerHandler(IAdxl345ConfigGetter *theConfigGetter, ISpiHandler *theSpiHandler,
                                           IRegisterManager *theRegisterManager)
    : configGetter(theConfigGetter), spiHandler(theSpiHandler), registerManager(theRegisterManager)
{
   // registerManager->setBit(DDRB, configurations.getCsPin());
}

void AccelerometerHandler::setBypassMode()
{
   // char textbuffer[70];
   // registerManager->clearBit(configGetter->g, PINB2);
   // const uint8_t test = spiHandler->transfer(0x00);
   // const uint8_t readData = spiHandler->transfer(0xFF);
   // registerManager->setBit(PORTB, PINB2);

   // sprintf(textbuffer, "read data is: %02X", readData);
   // LOGGER_INFO(textbuffer);
   // memset(textbuffer, '\0', sizeof(textbuffer));
   // sprintf(textbuffer, "return data is: %02X", test);
   // LOGGER_INFO(textbuffer);
   return;
}
