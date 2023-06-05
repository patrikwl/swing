#ifndef SPIHANDLER_H
#define SPIHANDLER_H

#include "IRegisterManager.h"
#include "ISpiAdapter.h"
#include "ISpiHandler.h"

class SpiHandler : public ISpiHandler {
 public:
   SpiHandler(ISpiAdapter *theSpiAdapter);
   //    ~SpiHandler();
   uint8_t const transfer(uint8_t data) override;

 private:
   ISpiAdapter *spiAdapter{nullptr};
};

#endif
