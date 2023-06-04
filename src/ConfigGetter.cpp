#include "ConfigGetter.h"

ConfigGetter::ConfigGetter() {}

const uint8_t ConfigGetter::getCsPin() { return SpiCsPin; }
const uint8_t ConfigGetter::getMosiPin() { return SpiMosiPin; }
const uint8_t ConfigGetter::getMisoPin() { return SpiMisoPin; }
const uint8_t ConfigGetter::getSckPin() { return SpiSckPin; }
const ISpiConfigGetter::SpiFrequency ConfigGetter::getSckFreqyency() { return SpiOscDevider; }

const uint8_t ConfigGetter::getTxPin() { return UartTxPin; }
const IUartConfigGetter::UartBaudRate ConfigGetter::getBaudRate() { return UartBaudrate; }
const IUartConfigGetter::UartFrameSize ConfigGetter::getFrameSize() { return UartFramesize; }
