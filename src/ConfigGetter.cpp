#include "ConfigGetter.h"

ConfigGetter::ConfigGetter() {}

const uint8_t ConfigGetter::getCsPin() { return SpiCsPin; }
const uint8_t ConfigGetter::getMosiPin() { return SpiMosiPin; }
const uint8_t ConfigGetter::getMisoPin() { return SpiMisoPin; }
const uint8_t ConfigGetter::getSckPin() { return SpiSckPin; }
ISpiConfigGetter::SpiFrequency ConfigGetter::getSckFreqyency() {}
