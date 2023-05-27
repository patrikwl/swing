#ifndef SPIADAPTER_H
#define SPIADAPTER_H

#include "IRegisterAccessor.h"
#include "ISpiAdapter.h"

class SpiAdapter : public ISpiAdapter {
 public:
   SpiAdapter(IRegisterAccessor *theRegisterAccessor);

   uint8_t const transfer(uint8_t const data) override;
   void configure(ISpiAdapter::SpiConfig const &conf);

 private:
   void init();
   void setSckRate(ISpiAdapter::SpiFrequency const &freq);
   void setOutputPorts(const uint8_t &csPin, const uint8_t &mosiPin, const uint8_t &sckPin);
   IRegisterAccessor *registerAccessor{nullptr};
};

#endif