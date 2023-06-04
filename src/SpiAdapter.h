#ifndef SPIADAPTER_H
#define SPIADAPTER_H

#include "IRegisterAccessor.h"
#include "ISpiAdapter.h"
#include "ISpiConfigGetter.h"

class SpiAdapter : public ISpiAdapter {
 public:
   SpiAdapter(IRegisterAccessor *theRegisterAccessor, ISpiConfigGetter *theConfGetter);

   uint8_t const transfer(uint8_t const data) override;

 private:
   void init();
   void setSckRate();
   void setIOPorts();
   IRegisterAccessor *registerAccessor{nullptr};
   ISpiConfigGetter *confGetter{nullptr};
};

#endif
