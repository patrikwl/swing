#ifndef IUARTCONFIGGETTER_H
#define IUARTCONFIGGETTER_H

#include <stdint.h>

class IUartConfigGetter {
 public:
   enum class UartBaudRate {
      br9600,
      br115200,
   };

   enum class UartFrameSize { FiveBit, SixBit, SevenBit, EightBit, NineBit };

   virtual const uint8_t getTxPin() = 0;
   virtual const UartBaudRate getBaudRate() = 0;
   virtual const UartFrameSize getFrameSize() = 0;

 private:
};

#endif
