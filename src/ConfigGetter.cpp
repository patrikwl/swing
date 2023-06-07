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
// volatile uint8_t &ConfigGetter::getCsPortRegister() { return SpiAdxlCsPinPort; } // TODO
const uint8_t ConfigGetter::getCsPin() { return SpiAdxlCsPin; }
const uint8_t ConfigGetter::getMosiPin() { return SpiMosiPin; }
const uint8_t ConfigGetter::getMisoPin() { return SpiMisoPin; }
const uint8_t ConfigGetter::getSckPin() { return SpiSckPin; }
const ISpiConfigGetter::SpiFrequency ConfigGetter::getSckFreqyency() { return SpiOscDevider; }

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

volatile uint8_t &getBaudRateRegLow() { return UartBaudRateRegisterLow; }
volatile uint8_t &getBaudRateRegHigh() { return UartBaudRateRegisterHigh; }

const IRegisterManager::BitField ConfigGetter::getUartCharSizeZero()
{
   IRegisterManager::BitField(UartControlAndStatusRegisterC, UartCharSizeZero);
}
const IRegisterManager::BitField ConfigGetter::getUartCharSizeOne()
{
   IRegisterManager::BitField(UartControlAndStatusRegisterC, UartCharSizeOne);
}
const IRegisterManager::BitField ConfigGetter::getUartCharSizeTwo()
{
   IRegisterManager::BitField(UartControlAndStatusRegisterB, UartCharSizeTwo);
}

volatile uint8_t &ConfigGetter::getUartDataRegister() { return UartDataRegister; }

const IRegisterManager::BitField ConfigGetter::getUartDataRegisterEmpty()
{
   return IRegisterManager::BitField(UartControlAndStatusRegisterA, UartDataRegisterEmpty);
}

const IUartConfigGetter::UartBaudRate ConfigGetter::getBaudRate() { return UartBaudrate; }
const IUartConfigGetter::UartFrameSize ConfigGetter::getFrameSize() { return UartFramesize; }
