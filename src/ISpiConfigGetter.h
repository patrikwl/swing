#ifndef ISPICONFIGGETTER_H
#define ISPICONFIGGETTER_H

#include "IRegisterManager.h"
#include <stdint.h>

class ISpiConfigGetter {
 public:
   enum class SpiFrequency { FOSC_4, FOSC_16, FOSC_64, FOSC_128, FOSC_2, FOSC_8, FOSC_32, FOSC_6 };

   virtual const IRegisterManager::BitField getAccelerometerCsPin() = 0;
   virtual const IRegisterManager::BitField getAccelerometerCsDataDirectionReg() = 0;

   virtual const IRegisterManager::BitField getMosiPin() = 0;
   virtual const IRegisterManager::BitField getMosiDataDirectionReg() = 0;
   virtual const IRegisterManager::BitField getMisoPin() = 0;
   virtual const IRegisterManager::BitField getMisoDataDirectionReg() = 0;
   virtual const IRegisterManager::BitField getSckPin() = 0;
   virtual const IRegisterManager::BitField getSckDataDirectionReg() = 0;

   virtual const SpiFrequency getSckFreqyency() = 0;
   virtual const IRegisterManager::BitField getClockEnabler() = 0;
   virtual const IRegisterManager::BitField getControlReg() = 0;
   virtual const IRegisterManager::BitField getSpiEnable() = 0;
   virtual const IRegisterManager::BitField getMasterSlaveSelect() = 0;
   virtual const IRegisterManager::BitField getClockPolarity() = 0;
   virtual const IRegisterManager::BitField getClockPhase() = 0;

   virtual const IRegisterManager::BitField getClockRateSelectZero() = 0;
   virtual const IRegisterManager::BitField getClockRateSelectOne() = 0;

   virtual const IRegisterManager::BitField getInterruptFlag() = 0;
   virtual const IRegisterManager::BitField getDoubleSpeed() = 0;
   virtual volatile uint8_t &getDataReg() = 0;

 private:
};

#endif
