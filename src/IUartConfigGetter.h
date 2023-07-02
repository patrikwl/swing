#ifndef IUARTCONFIGGETTER_H
#define IUARTCONFIGGETTER_H

#include "IRegisterManager.h"

class IUartConfigGetter {
 public:
   enum class UartBaudRate {
      br9600,
      br115200,
   };

   enum class UartFrameSize { FiveBit, SixBit, SevenBit, EightBit, NineBit };

   virtual const IRegisterManager::BitField getTxPin() = 0;
   virtual const IRegisterManager::BitField getTxDataDirectionReg() = 0;
   virtual const IRegisterManager::BitField getUartTransmitterEnable() = 0;
   virtual const IRegisterManager::BitField getUartDoubleSpeed() = 0;

   virtual volatile uint8_t &getBaudRateRegLow() = 0;
   virtual volatile uint8_t &getBaudRateRegHigh() = 0;

   virtual const IRegisterManager::BitField getUartCharSizeZero() = 0;
   virtual const IRegisterManager::BitField getUartCharSizeOne() = 0;
   virtual const IRegisterManager::BitField getUartCharSizeTwo() = 0;

   virtual volatile uint8_t &getUartDataRegister() = 0;
   virtual const IRegisterManager::BitField getUartDataRegisterEmpty() = 0;

   virtual const UartBaudRate getBaudRate() = 0;
   virtual const UartFrameSize getFrameSize() = 0;

 private:
};

#endif
