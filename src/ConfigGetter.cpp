#include "ConfigGetter.h"
#include "HardwareSetup.h"
#include "src/IRegisterManager.h"

ConfigGetter::ConfigGetter() {}

// Uncategorized
const IRegisterManager::BitField ConfigGetter::getLedPin() { return IRegisterManager::BitField(LedPinPort, LedPin); }
const IRegisterManager::BitField ConfigGetter::getLedDataDirectionReg()
{
   return IRegisterManager::BitField(LedDataDirectionRegister, LedPin);
}

// SPI

const IRegisterManager::BitField ConfigGetter::getAccelerometerCsPin()
{
   return IRegisterManager::BitField(SpiAdxlCsPinPort, SpiAdxlCsPin);
}

const IRegisterManager::BitField ConfigGetter::getAccelerometerCsDataDirectionReg()
{
   return IRegisterManager::BitField(SpiAdxlCsDataDirectionRegister, SpiAdxlCsPin);
}

const IRegisterManager::BitField ConfigGetter::getMosiPin() { return IRegisterManager::BitField(SpiPinPort, SpiMosiPin); }
const IRegisterManager::BitField ConfigGetter::getMisoPin() { return IRegisterManager::BitField(SpiPinPort, SpiMisoPin); }
const IRegisterManager::BitField ConfigGetter::getSckPin() { return IRegisterManager::BitField(SpiPinPort, SpiSckPin); }

const IRegisterManager::BitField ConfigGetter::getMosiDataDirectionReg()
{
   return IRegisterManager::BitField(SpiMosiDataDirectionReg, SpiMosiPin);
}
const IRegisterManager::BitField ConfigGetter::getMisoDataDirectionReg()
{
   return IRegisterManager::BitField(SpiMisoDataDirecionReg, SpiMisoPin);
}
const IRegisterManager::BitField ConfigGetter::getSckDataDirectionReg()
{
   return IRegisterManager::BitField(SpiSckDataDirectionReg, SpiSckPin);
}

const ISpiConfigGetter::SpiFrequency ConfigGetter::getSckFreqyency() { return SpiOscDevider; }
const IRegisterManager::BitField ConfigGetter::getClockEnabler()
{
   return IRegisterManager::BitField(PowerReductionRegister, SpiEnableClock);
}
const IRegisterManager::BitField ConfigGetter::getControlReg() {}
const IRegisterManager::BitField ConfigGetter::getSpiEnable()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiEnable);
}
const IRegisterManager::BitField ConfigGetter::getMasterSlaveSelect()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiMasterSlaveSelect);
}
const IRegisterManager::BitField ConfigGetter::getClockPolarity()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiClockPolarity);
}
const IRegisterManager::BitField ConfigGetter::getClockPhase()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiClockPhase);
}
const IRegisterManager::BitField ConfigGetter::getClockRateSelectZero()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiClockRateSelectZero);
}
const IRegisterManager::BitField ConfigGetter::getClockRateSelectOne()
{
   return IRegisterManager::BitField(SpiControlRegister, SpiClockRateSelectOne);
}
const IRegisterManager::BitField ConfigGetter::getInterruptFlag()
{
   return IRegisterManager::BitField(SpiStatusReg, SpiInterruptFlag);
}
const IRegisterManager::BitField ConfigGetter::getDoubleSpeed()
{
   return IRegisterManager::BitField(SpiStatusReg, SpiDoubleSpeed);
}
volatile uint8_t &ConfigGetter::getDataReg() { return SpiDataReg; }

// UART
const IRegisterManager::BitField ConfigGetter::getTxPin() { return IRegisterManager::BitField(LedPinPort, LedPin); }
const IRegisterManager::BitField ConfigGetter::getTxDataDirectionReg()
{
   return IRegisterManager::BitField(LedDataDirectionRegister, LedPin);
}
const IRegisterManager::BitField ConfigGetter::getUartTransmitterEnable()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterB, UartTransmitterEnable);
}

const IRegisterManager::BitField ConfigGetter::getUartDoubleSpeed()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterA, UartDoubleSpeed);
}

volatile uint8_t &ConfigGetter::getBaudRateRegLow() { return UartBaudRateRegisterLow; }
volatile uint8_t &ConfigGetter::getBaudRateRegHigh() { return UartBaudRateRegisterHigh; }

const IRegisterManager::BitField ConfigGetter::getUartCharSizeZero()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterC, UartCharSizeZero);
}
const IRegisterManager::BitField ConfigGetter::getUartCharSizeOne()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterC, UartCharSizeOne);
}
const IRegisterManager::BitField ConfigGetter::getUartCharSizeTwo()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterB, UartCharSizeTwo);
}

volatile uint8_t &ConfigGetter::getUartDataRegister() { return UartDataRegister; }

const IRegisterManager::BitField ConfigGetter::getUartDataRegisterEmpty()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterA, UartDataRegisterEmpty);
}

const IUartConfigGetter::UartBaudRate ConfigGetter::getBaudRate() { return UartBaudrate; }
const IUartConfigGetter::UartFrameSize ConfigGetter::getFrameSize() { return UartFramesize; }
