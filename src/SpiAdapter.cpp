#include "SpiAdapter.h"
#include "ISpiAdapter.h"

SpiAdapter::SpiAdapter(IRegisterManager *theRegisterManager, ISpiConfigGetter *theConfGetter)
    : registerManager(theRegisterManager), confGetter(theConfGetter)
{
   init();
}

void SpiAdapter::init()
{
   // enable clock to SPI module
   registerManager->clearBit(confGetter->getClockEnabler()); // set by default
   // Enable SPI
   registerManager->setBit(confGetter->getSpiEnable());
   // Set atmega as master
   registerManager->setBit(confGetter->getMasterSlaveSelect());
   // Set SCK to high when idle
   registerManager->setBit(confGetter->getClockPolarity());
   // Set data sampling on leading edge of SCK
   registerManager->setBit(confGetter->getClockPhase());

   setSckRate();
   setIOPorts();
}

void SpiAdapter::setIOPorts()
{
   registerManager->setBit(confGetter->getAccelerometerCsDataDirectionReg());
   registerManager->setBit(confGetter->getMosiDataDirectionReg());
   registerManager->clearBit(confGetter->getMisoDataDirectionReg());
   registerManager->setBit(confGetter->getSckDataDirectionReg());
}

void SpiAdapter::setSckRate()
{
   switch (confGetter->getSckFreqyency()) {
      case (ISpiConfigGetter::SpiFrequency::FOSC_4):
         registerManager->clearBit(confGetter->getClockRateSelectZero());
         registerManager->clearBit(confGetter->getClockRateSelectOne());
         registerManager->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_16):
         registerManager->clearBit(confGetter->getClockRateSelectZero());
         registerManager->setBit(confGetter->getClockRateSelectOne());
         registerManager->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_64):
         registerManager->clearBit(confGetter->getClockRateSelectZero());
         registerManager->setBit(confGetter->getClockRateSelectOne());
         registerManager->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_128):
         registerManager->setBit(confGetter->getClockRateSelectZero());
         registerManager->setBit(confGetter->getClockRateSelectOne());
         registerManager->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_2):
         registerManager->clearBit(confGetter->getClockRateSelectZero());
         registerManager->clearBit(confGetter->getClockRateSelectOne());
         registerManager->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_8):
         registerManager->setBit(confGetter->getClockRateSelectZero());
         registerManager->clearBit(confGetter->getClockRateSelectOne());
         registerManager->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_32):
         registerManager->clearBit(confGetter->getClockRateSelectZero());
         registerManager->setBit(confGetter->getClockRateSelectOne());
         registerManager->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_6):
         registerManager->setBit(confGetter->getClockRateSelectZero());
         registerManager->setBit(confGetter->getClockRateSelectOne());
         registerManager->setBit(confGetter->getDoubleSpeed());
         break;
   }
}

uint8_t const SpiAdapter::transfer(uint8_t const data)
{
   confGetter->getDataReg() = data;
   while (!(registerManager->isBitSet(confGetter->getInterruptFlag()))) {
   }
   return confGetter->getDataReg();
}
