#ifndef ADXL345CONFIGGETTER_H
#define ADXL345CONFIGGETTER_H

#include "IAdxl345ConfigGetter.h"

class Adxl345ConfigGetter : public IAdxl345ConfigGetter {
 public:
   Adxl345ConfigGetter();

   const uint8_t getFifoControlReg() override;

 private:
};

#endif
