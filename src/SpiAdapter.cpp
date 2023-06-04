#include "SpiAdapter.h"
#include "ISpiAdapter.h"

#include <avr/io.h>

SpiAdapter::SpiAdapter(IRegisterAccessor *theRegisterAccessor, ISpiConfigGetter *theConfGetter)
    : registerAccessor(theRegisterAccessor), confGetter(theConfGetter)
{
   init();
}

void SpiAdapter::init()
{
   // enable clock to SPI module
   registerAccessor->clearBit(PRR, PRSPI);
   // Enable SPI
   registerAccessor->setBit(SPCR, SPE);
   // Set atmega as master
   registerAccessor->setBit(SPCR, MSTR);
   // Set SCK to high when idle
   registerAccessor->setBit(SPCR, CPOL);
   // Set data sampling on leading edge of SCK
   registerAccessor->setBit(SPCR, CPHA);

   setSckRate();
   setIOPorts();
}

void SpiAdapter::setIOPorts()
{
   registerAccessor->setBit(DDRB, confGetter->getCsPin());
   registerAccessor->setBit(DDRB, confGetter->getMosiPin());
   registerAccessor->setBit(DDRB, confGetter->getSckPin());
}

void SpiAdapter::setSckRate()
{
   switch (confGetter->getSckFreqyency()) {
      case (ISpiConfigGetter::SpiFrequency::FOSC_4):
         registerAccessor->clearBit(SPCR, SPR0);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_16):
         registerAccessor->clearBit(SPCR, SPR0);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_64):
         registerAccessor->clearBit(SPCR, SPR0);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_128):
         registerAccessor->setBit(SPCR, SPR0);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_2):
         registerAccessor->clearBit(SPCR, SPR0);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_8):
         registerAccessor->setBit(SPCR, SPR0);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_32):
         registerAccessor->clearBit(SPCR, SPR0);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiConfigGetter::SpiFrequency::FOSC_6):
         registerAccessor->setBit(SPCR, SPR0);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
   }
}

uint8_t const SpiAdapter::transfer(uint8_t const data)
{
   SPDR = data;
   while (!(SPSR & (1 << SPIF)))
      return SPDR;
}
