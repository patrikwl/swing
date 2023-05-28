#ifndef SRC_IUARTMANAGER_H
#define SRC_IUARTMANAGER_H

#include <stdint.h>

class IUartManager {
 public:
   //    enum class UartBaudRate {
   //     br9600,
   //     br115200,
   //    };

   //    struct SpiConfig {
   //       UartBaudRate baudRate;
   //       SpiConfig(UartBaudRate br) : baudRate(br) {}
   //    };
   virtual void transmit16Bits(int16_t const dataToSend) = 0;
   virtual void transmitString(const char *buffer, uint8_t const bufferSize) = 0;
};

#endif
