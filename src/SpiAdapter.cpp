#include "SpiAdapter.h"
#include "ISpiAdapter.h"

#include <avr/io.h>

SpiAdapter::SpiAdapter(IRegisterManager *theRegisterManager, ISpiConfigGetter *theConfGetter)
    : registerAccessor(theRegisterManager), confGetter(theConfGetter)
{
   init();
}

void SpiAdapter::init()
{
   // enable clock to SPI module
   registerAccessor->clearBit(confGetter->getClockEnabler()); // set by default
   // Enable SPI
   registerAccessor->setBit(confGetter->getSpiEnable());
   // Set atmega as master
   registerAccessor->setBit(confGetter->getMasterSlaveSelect());
   // Set SCK to high when idle
   registerAccessor->setBit(confGetter->getClockPolarity());
   // Set data sampling on leading edge of SCK
   registerAccessor->setBit(confGetter->getClockPhase());

   setSckRate();
   setIOPorts();
}

void SpiAdapter::setIOPorts()
{
   registerAccessor->setBit(confGetter->getAccelerometerCsDataDirectionReg());
   registerAccessor->setBit(confGetter->getMosiDataDirectionReg());
   registerAccessor->clearBit(confGetter->getMisoDataDirectionReg());
   registerAccessor->setBit(confGetter->getSckDataDirectionReg());
}

void SpiAdapter::setSckRate()
{
   switch (confGetter->getSckFreqyency()) {
      case (ISpiConfigGetter::SpiFrequency::FOSC_4):
         registerAccessor->clearBit(confGetter->getClockRateSelectZero());
         registerAccessor->clearBit(confGetter->getClockRateSelectOne());
         registerAccessor->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_16):
         registerAccessor->clearBit(confGetter->getClockRateSelectZero());
         registerAccessor->setBit(confGetter->getClockRateSelectOne());
         registerAccessor->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_64):
         registerAccessor->clearBit(confGetter->getClockRateSelectZero());
         registerAccessor->setBit(confGetter->getClockRateSelectOne());
         registerAccessor->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_128):
         registerAccessor->setBit(confGetter->getClockRateSelectZero());
         registerAccessor->setBit(confGetter->getClockRateSelectOne());
         registerAccessor->clearBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_2):
         registerAccessor->clearBit(confGetter->getClockRateSelectZero());
         registerAccessor->clearBit(confGetter->getClockRateSelectOne());
         registerAccessor->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_8):
         registerAccessor->setBit(confGetter->getClockRateSelectZero());
         registerAccessor->clearBit(confGetter->getClockRateSelectOne());
         registerAccessor->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_32):
         registerAccessor->clearBit(confGetter->getClockRateSelectZero());
         registerAccessor->setBit(confGetter->getClockRateSelectOne());
         registerAccessor->setBit(confGetter->getDoubleSpeed());
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_6):
         registerAccessor->setBit(confGetter->getClockRateSelectZero());
         registerAccessor->setBit(confGetter->getClockRateSelectOne());
         registerAccessor->setBit(confGetter->getDoubleSpeed());
         break;
   }
}

uint8_t const SpiAdapter::transfer(uint8_t const data)
{
   confGetter->getDataReg() = data;
   while (!(registerAccessor->isBitSet(confGetter->getInterruptFlag()))) {
   }
   return confGetter->getDataReg();
}
