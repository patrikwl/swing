#ifndef SRC_IUARTADAPTER_H
#define SRC_IUARTADAPTER_H

#include <stdint.h>

class IUartAdapter {
 public:
   enum class UartBaudRate {
      br9600,
      br115200,
   };

   struct UartConfig {
      UartBaudRate baudRate;
      const uint8_t TX_PIN;
      UartConfig(UartBaudRate br, const uint8_t theTX_PIN) : baudRate(br), TX_PIN(theTX_PIN) {}
   };
   virtual void waitForEmptyTransmitBuffer() = 0;
   virtual void putChar(const char &data) = 0;
};

#endif
