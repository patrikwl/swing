#include "AccelerometerHandler.h"

#include <stdio.h>
#include <string.h>

AccelerometerHandler::AccelerometerHandler(ISpiConfigGetter *theSpiConfigGetter, IAdxl345ConfigGetter *theAccelConfigGetter,
                                           ISpiHandler *theSpiHandler, IRegisterManager *theRegisterManager)
    : spiConfigGetter(theSpiConfigGetter), accelConfigGetter(theAccelConfigGetter), spiHandler(theSpiHandler),
      registerManager(theRegisterManager)
{
   // registerManager->setBit(DDRB, configurations.getCsPin());
}

void AccelerometerHandler::setBypassMode()
{
   char textbuffer[70];
   char textbuffer2[70];
   registerManager->clearBit(spiConfigGetter->getAccelerometerCsPin());
   const uint8_t test = spiHandler->transfer(multiRead(0x2C));
   uint8_t readData = spiHandler->transfer(0xFF);
   sprintf(textbuffer, "read data is: %08u", readData);
   LOGGER_INFO(textbuffer);
   memset(textbuffer, '\0', sizeof(textbuffer));
   readData = spiHandler->transfer(0xFF);
   sprintf(textbuffer, "read data is: %02x", readData);
   LOGGER_INFO(textbuffer);
   memset(textbuffer, '\0', sizeof(textbuffer));
   readData = spiHandler->transfer(0xFF);
   sprintf(textbuffer, "read data is: %02X", readData);
   LOGGER_INFO(textbuffer);
   memset(textbuffer, '\0', sizeof(textbuffer));
   readData = spiHandler->transfer(0xFF);
   sprintf(textbuffer, "read data is: %02X", readData);
   LOGGER_INFO(textbuffer);
   memset(textbuffer, '\0', sizeof(textbuffer));
   readData = spiHandler->transfer(0xFF);
   sprintf(textbuffer, "read data is: %08u", readData);
   LOGGER_INFO(textbuffer);
   memset(textbuffer, '\0', sizeof(textbuffer));
   registerManager->setBit(spiConfigGetter->getAccelerometerCsPin());
   return;
}

volatile uint8_t AccelerometerHandler::singleRead(volatile uint8_t inputReg)
{
   IRegisterManager::BitField field(inputReg, accelConfigGetter->getReadWriteBitPos());
   registerManager->setBit(field);
   return field.targetReg;
}

volatile uint8_t AccelerometerHandler::singleWrite(volatile uint8_t inputReg)
{
   IRegisterManager::BitField field(inputReg, accelConfigGetter->getReadWriteBitPos());
   registerManager->clearBit(field);
   return field.targetReg;
}

volatile uint8_t AccelerometerHandler::multiRead(volatile uint8_t inputReg)
{
   uint8_t res = singleRead(inputReg);
   IRegisterManager::BitField field(res, accelConfigGetter->getMultiReadWriteBitPos());
   registerManager->setBit(field);
   return field.targetReg;
}

volatile uint8_t AccelerometerHandler::multiWrite(volatile uint8_t inputReg)
{
   uint8_t res = singleWrite(inputReg);
   IRegisterManager::BitField field(res, accelConfigGetter->getMultiReadWriteBitPos());
   registerManager->setBit(field);
   return field.targetReg;
}
