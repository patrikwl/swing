#ifndef UARTADAPTER_H
#define UARTADAPTER_H

#include "IRegisterAccessor.h"
#include "IUartAdapter.h"
#include "IUartConfigGetter.h"

class UartAdapter : public IUartAdapter {
 public:
   UartAdapter(IRegisterAccessor *theRegisterAccessor, IUartConfigGetter *theConfigGetter);

   void waitForEmptyTransmitBuffer() override;
   void putChar(const char &data) override;

 private:
   void init();
   void setCharacterSize();
   void setIOPorts();
   void setBaudRate();
   IRegisterAccessor *registerAccessor{nullptr};
   IUartConfigGetter *configGetter{nullptr};
};

#endif
