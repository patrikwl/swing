#include "ConfigGetter.h"
#include "HardwareSetup.h"

ConfigGetter::ConfigGetter() {}

// Uncategorized
const IRegisterManager::BitField ConfigGetter::getLedPin() { return IRegisterManager::BitField(LedPinPort, LedPin); }
const IRegisterManager::BitField ConfigGetter::getLedDataDirectionReg()
{
   return IRegisterManager::BitField(LedDataDirectionRegister, LedPin);
}

// SPI
volatile uint8_t &ConfigGetter::getCsPortRegister() { return SpiAdxlCsPinPort; }
const uint8_t ConfigGetter::getCsPin() { return SpiAdxlCsPin; }
const uint8_t ConfigGetter::getMosiPin() { return SpiMosiPin; }
const uint8_t ConfigGetter::getMisoPin() { return SpiMisoPin; }
const uint8_t ConfigGetter::getSckPin() { return SpiSckPin; }
const ISpiConfigGetter::SpiFrequency ConfigGetter::getSckFreqyency() { return SpiOscDevider; }

// UART
const uint8_t ConfigGetter::getTxPin() { return UartTxPin; }
const IUartConfigGetter::UartBaudRate ConfigGetter::getBaudRate() { return UartBaudrate; }
const IUartConfigGetter::UartFrameSize ConfigGetter::getFrameSize() { return UartFramesize; }
