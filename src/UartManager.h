#ifndef UARTMANAGER_H
#define UARTMANAGER_H

#include "IUartAdapter.h"
#include "IUartManager.h"

class UartManager : IUartManager {
 public:
   UartManager(IUartAdapter *theUartAdapter);

   void transmit16Bits(int16_t const dataToSend) override;
   void transmitString(const char *buffer) override;

 private:
   IUartAdapter *uartAdapter{nullptr};
};

#endif
