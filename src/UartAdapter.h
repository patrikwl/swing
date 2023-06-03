#ifndef UARTADAPTER_H
#define UARTADAPTER_H

#include "IRegisterAccessor.h"
#include "IUartAdapter.h"

class UartAdapter : public IUartAdapter {
 public:
   UartAdapter(IRegisterAccessor *theRegisterAccessor);

   void waitForEmptyTransmitBuffer() override;
   void putChar(const char &data) override;

   void configure(IUartAdapter::UartConfig &conf);

 private:
   IRegisterAccessor *registerAccessor{nullptr};
};

#endif
