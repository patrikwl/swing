#ifndef SPIADAPTER_H
#define SPIADAPTER_H

#include "IRegisterManager.h"
#include "ISpiAdapter.h"
#include "ISpiConfigGetter.h"

class SpiAdapter : public ISpiAdapter {
 public:
   SpiAdapter(IRegisterManager *theRegisterManager, ISpiConfigGetter *theConfGetter);

   uint8_t const transfer(uint8_t const data) override;

 private:
   void init();
   void setSckRate();
   void setIOPorts();
   IRegisterManager *registerManager{nullptr};
   ISpiConfigGetter *confGetter{nullptr};
};

#endif
