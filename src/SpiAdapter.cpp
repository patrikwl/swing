#include "SpiAdapter.h"
#include "ISpiAdapter.h"

#include <avr/io.h>

SpiAdapter::SpiAdapter(IRegisterAccessor *theRegisterAccessor) : registerAccessor(theRegisterAccessor) { init(); }

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
}

void SpiAdapter::configure(ISpiAdapter::SpiConfig const &conf)
{
   setSckRate(conf.freq);
   setOutputPorts(conf.CS_PIN, conf.MOSI_PIN, conf.SCK_PIN);
}

void SpiAdapter::setOutputPorts(const uint8_t &csPin, const uint8_t &mosiPin, const uint8_t &sckPin)
{
   registerAccessor->setBit(DDRB, csPin);
   registerAccessor->setBit(DDRB, mosiPin);
   registerAccessor->setBit(DDRB, sckPin);
}

void SpiAdapter::setSckRate(ISpiAdapter::SpiFrequency const &freq)
{
   switch (freq) {
      case (ISpiAdapter::SpiFrequency::FOSC_4):
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_16):
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_64):
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_128):
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_2):
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_8):
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_32):
         registerAccessor->setBit(SPCR, SPR1);
         registerAccessor->clearBit(SPCR, SPR1);
         registerAccessor->setBit(SPSR, SPI2X);
         break;
      case (ISpiAdapter::SpiFrequency::FOSC_6):
         registerAccessor->setBit(SPCR, SPR1);
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