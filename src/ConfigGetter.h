#ifndef CONFIGGETTER_H
#define CONFIGGETTER_H

#include "HardwareSetup.h"
#include "ISpiConfigGetter.h"

class ConfigGetter : public ISpiConfigGetter {
 public:
   ConfigGetter();

   const uint8_t getCsPin() override;
   const uint8_t getMosiPin() override;
   const uint8_t getMisoPin() override;
   const uint8_t getSckPin() override;
   ISpiConfigGetter::SpiFrequency getSckFreqyency() override;

 private:
};

#endif
