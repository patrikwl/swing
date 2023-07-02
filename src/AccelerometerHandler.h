#ifndef ACCELEROMETERHANDLER_H
#define ACCELEROMETERHANDLER_H

#include "IAdxl345.h"
#include "IAdxl345ConfigGetter.h"
#include "ISpiConfigGetter.h"
#include "ISpiHandler.h"
#include "logger.h"

#include "IRegisterManager.h"

class AccelerometerHandler : public IAdxl345 {
 public:
   AccelerometerHandler(ISpiConfigGetter *theSpiConfigGetter, IAdxl345ConfigGetter *theAccelConfigGetter,
                        ISpiHandler *theSpiHandler, IRegisterManager *theRegisterManager);

   void setBypassMode() override;
   volatile uint8_t singleRead(volatile uint8_t inputReg);
   volatile uint8_t multiRead(volatile uint8_t intputReg);
   volatile uint8_t singleWrite(volatile uint8_t intputReg);
   volatile uint8_t multiWrite(volatile uint8_t intputReg);

 private:
   ISpiConfigGetter *spiConfigGetter{nullptr};
   IAdxl345ConfigGetter *accelConfigGetter{nullptr};
   ISpiHandler *spiHandler{nullptr};
   IRegisterManager *registerManager{nullptr};
};

#endif
