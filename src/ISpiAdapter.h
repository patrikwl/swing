#ifndef SRC_ISPIADAPTER_H
#define SRC_ISPIADAPTER_H

#include <stdint.h>

class ISpiAdapter {
 public:
   enum class SpiFrequency { FOSC_4, FOSC_16, FOSC_64, FOSC_128, FOSC_2, FOSC_8, FOSC_32, FOSC_6 };

   struct SpiConfig {
      SpiFrequency freq;
      const uint8_t CS_PIN;
      const uint8_t MOSI_PIN;
      const uint8_t MISO_PIN;
      const uint8_t SCK_PIN;

      SpiConfig(SpiFrequency f, volatile uint8_t theCS_PIN, volatile uint8_t theMOSI_PIN, volatile uint8_t theMISO_PIN,
                volatile uint8_t theSCK_PIN)
          : freq(f), CS_PIN(theCS_PIN), MOSI_PIN(theMOSI_PIN), MISO_PIN(theMISO_PIN), SCK_PIN(theSCK_PIN)
      {
      }
   };

   virtual uint8_t const transfer(uint8_t const data) = 0;
};
#endif
