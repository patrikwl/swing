#include "Adxl345ConfigGetter.h"
#include "Adxl345RegisterMap.h"

Adxl345ConfigGetter::Adxl345ConfigGetter() {}

const uint8_t Adxl345ConfigGetter::getFifoControlReg() { return FIFO_CTL; }
