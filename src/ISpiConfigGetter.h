#ifndef ISPICONFIGGETTER_H
#define ISPICONFIGGETTER_H

#include <stdint.h>

class ISpiConfigGetter {
 public:
   enum class SpiFrequency { FOSC_4, FOSC_16, FOSC_64, FOSC_128, FOSC_2, FOSC_8, FOSC_32, FOSC_6 };

   virtual const uint8_t getCsPin() = 0;
   virtual const uint8_t getMosiPin() = 0;
   virtual const uint8_t getMisoPin() = 0;
   virtual const uint8_t getSckPin() = 0;
   virtual SpiFrequency getSckFreqyency() = 0;

 private:
};

#endif
