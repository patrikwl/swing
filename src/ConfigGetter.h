#ifndef CONFIGGETTER_H
#define CONFIGGETTER_H

#include "IConfigGetter.h"
#include "ISpiConfigGetter.h"
#include "IUartConfigGetter.h"

class ConfigGetter : public IConfigGetter, public ISpiConfigGetter, public IUartConfigGetter {
 public:
   ConfigGetter();

   // Uncategorized configurations
   const IRegisterManager::BitField getLedDataDirectionReg() override;
   const IRegisterManager::BitField getLedPin() override;

   // SPI
   const uint8_t getCsPin() override;
   const uint8_t getMosiPin() override;
   const uint8_t getMisoPin() override;
   const uint8_t getSckPin() override;
   const ISpiConfigGetter::SpiFrequency getSckFreqyency() override;

   // UART
   const uint8_t getTxPin() override;
   const IUartConfigGetter::UartBaudRate getBaudRate() override;
   const IUartConfigGetter::UartFrameSize getFrameSize() override;

 private:
};

#endif
