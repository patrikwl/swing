#ifndef UARTADAPTER_H
#define UARTADAPTER_H

#include "IRegisterManager.h"
#include "IUartAdapter.h"
#include "IUartConfigGetter.h"

class UartAdapter : public IUartAdapter {
 public:
   UartAdapter(IRegisterManager *theRegisterManager, IUartConfigGetter *theConfigGetter);

   void waitForEmptyTransmitBuffer() override;
   void putChar(const char &data) override;

 private:
   void init();
   void setCharacterSize();
   void setIOPorts();
   void setBaudRate();
   IRegisterManager *registerAccessor{nullptr};
   IUartConfigGetter *configGetter{nullptr};
};

#endif
