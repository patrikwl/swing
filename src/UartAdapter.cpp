#include "UartAdapter.h"
#include "IUartAdapter.h"
#include <avr/io.h>
#include <stdio.h>

UartAdapter::UartAdapter(IRegisterManager *theRegisterManager, IUartConfigGetter *theConfigGetter)
    : registerAccessor(theRegisterManager), configGetter(theConfigGetter)
{
   init();
}

void UartAdapter::init()
{
   // Enable UART receiver module
   registerAccessor->setBit(configGetter->getUartTransmitterEnable());
   setCharacterSize();
   setIOPorts();
   setBaudRate();
}

void UartAdapter::setBaudRate()
{
   switch (configGetter->getBaudRate()) {
      case (IUartConfigGetter::UartBaudRate::br115200):
         registerAccessor->clearBit(configGetter->getUartDoubleSpeed());
         uint16_t ubrrValue = F_CPU / (16UL * 115200) - 1;
         configGetter->getBaudRateRegHigh() = (ubrrValue >> 8) & 0xFF;
         configGetter->getBaudRateRegLow() = (ubrrValue)&0xFF;
         break;
      defualt:
         break;
   };
}

void UartAdapter::setIOPorts()
{
   // Set OI port(s)
   registerAccessor->setBit(configGetter->getTxDataDirectionReg());
   registerAccessor->setBit(configGetter->getTxPin());
}

void UartAdapter::setCharacterSize()
{
   switch (configGetter->getFrameSize()) {
      case (IUartConfigGetter::UartFrameSize::EightBit):
         registerAccessor->setBit(configGetter->getUartCharSizeZero());
         registerAccessor->setBit(configGetter->getUartCharSizeOne());
         registerAccessor->clearBit(configGetter->getUartCharSizeTwo());
         break;
      default:
         // not implemented
         break;
   }
}

void UartAdapter::waitForEmptyTransmitBuffer()
{
   while (!registerAccessor->isBitSet(configGetter->getUartDataRegisterEmpty())) {
   }
}
void UartAdapter::putChar(const char &data) { configGetter->getUartDataRegister() = data; }
