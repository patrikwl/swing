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
   const IRegisterManager::BitField getAccelerometerCsPin() override;
   const IRegisterManager::BitField getAccelerometerCsDataDirectionReg() override;

   const IRegisterManager::BitField getMosiPin() override;
   const IRegisterManager::BitField getMisoPin() override;
   const IRegisterManager::BitField getSckPin() override;
   const IRegisterManager::BitField getMosiDataDirectionReg() override;
   const IRegisterManager::BitField getMisoDataDirectionReg() override;
   const IRegisterManager::BitField getSckDataDirectionReg() override;

   const ISpiConfigGetter::SpiFrequency getSckFreqyency() override;
   const IRegisterManager::BitField getClockEnabler() override;

   const IRegisterManager::BitField getControlReg() override;
   const IRegisterManager::BitField getSpiEnable() override;
   const IRegisterManager::BitField getMasterSlaveSelect() override;
   const IRegisterManager::BitField getClockPolarity() override;
   const IRegisterManager::BitField getClockPhase() override;
   const IRegisterManager::BitField getClockRateSelectZero() override;
   const IRegisterManager::BitField getClockRateSelectOne() override;

   const IRegisterManager::BitField getInterruptFlag() override;
   const IRegisterManager::BitField getDoubleSpeed() override;
   volatile uint8_t &getDataReg() override;

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
