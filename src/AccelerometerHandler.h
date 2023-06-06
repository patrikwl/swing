#ifndef ACCELEROMETERHANDLER_H
#define ACCELEROMETERHANDLER_H

#include "IAdxl345.h"
#include "IAdxl345ConfigGetter.h"
#include "ISpiHandler.h"

#include "IRegisterManager.h"
#include "IUartManager.h"

class AccelerometerHandler : public IAdxl345 {
 public:
   AccelerometerHandler(IAdxl345ConfigGetter *theConfigGetter, ISpiHandler *theSpiHandler, IRegisterManager *theRegisterManager,
                        IUartManager *theUartManager);

   void setBypassMode() override;

 private:
   IAdxl345ConfigGetter *configGetter{nullptr};
   ISpiHandler *spiHandler{nullptr};
   IUartManager *uartManager{nullptr};
   IRegisterManager *registerManager{nullptr};
};

#endif
