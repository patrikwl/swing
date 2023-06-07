#ifndef CONFIGGETTER_H
#define CONFIGGETTER_H

#include "IConfigGetter.h"
#include "ISpiConfigGetter.h"
#include "IUartConfigGetter.h"

class ConfigGetter : public IConfigGetter, public ISpiConfigGetter, public IUartConfigGetter {
 public:
   ConfigGetter();

   // (Uncategorized) configurations
   const IRegisterManager::BitField getLedDataDirectionReg() override;
   const IRegisterManager::BitField getLedPin() override;

   // SPI
   const uint8_t getCsPin() override;
   const uint8_t getMosiPin() override;
   const uint8_t getMisoPin() override;
   const uint8_t getSckPin() override;
   const ISpiConfigGetter::SpiFrequency getSckFreqyency() override;

   // UART
   const IRegisterManager::BitField getTxPin() override;
   const IRegisterManager::BitField getTxDataDirectionReg() override;
   const IRegisterManager::BitField getUartTransmitterEnable() override;
   const IRegisterManager::BitField getUartDoubleSpeed() override;
   volatile uint8_t &getUartDataRegister() override;
   const IRegisterManager::BitField getUartDataRegisterEmpty() override;
   volatile uint8_t &getBaudRateRegLow() override;
   volatile uint8_t &getBaudRateRegHigh() override;
   const IRegisterManager::BitField getUartCharSizeZero() override;
   const IRegisterManager::BitField getUartCharSizeOne() override;
   const IRegisterManager::BitField getUartCharSizeTwo() override;
   const IUartConfigGetter::UartBaudRate getBaudRate() override;
   const IUartConfigGetter::UartFrameSize getFrameSize() override;

 private:
};

#endif
