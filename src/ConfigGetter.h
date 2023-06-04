#ifndef CONFIGGETTER_H
#define CONFIGGETTER_H

#include "HardwareSetup.h"
#include "ISpiConfigGetter.h"
#include "IUartConfigGetter.h"

class ConfigGetter : public ISpiConfigGetter, public IUartConfigGetter {
 public:
   ConfigGetter();

   const uint8_t getCsPin() override;
   const uint8_t getMosiPin() override;
   const uint8_t getMisoPin() override;
   const uint8_t getSckPin() override;
   const ISpiConfigGetter::SpiFrequency getSckFreqyency() override;

   const uint8_t getTxPin() override;
   const IUartConfigGetter::UartBaudRate getBaudRate() override;
   const IUartConfigGetter::UartFrameSize getFrameSize() override;

 private:
};

#endif
