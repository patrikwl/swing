#include "Adxl345ConfigGetter.h"
#include "Adxl345RegisterMap.h"
#include <stdint.h>

Adxl345ConfigGetter::Adxl345ConfigGetter() {}

const uint8_t Adxl345ConfigGetter::getFifoControlReg() { return FIFO_CTL; }
const uint8_t Adxl345ConfigGetter::getReadWriteBitPos() { return ReadWriteBit; }
const uint8_t Adxl345ConfigGetter::getMultiReadWriteBitPos() { return MultipleReadWriteBit; }
