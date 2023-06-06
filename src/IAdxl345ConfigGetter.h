#ifndef IADXL345CONFIGGETTER_H
#define IADXL345CONFIGGETTER_H

#include <stdint.h>
class IAdxl345ConfigGetter {
 public:
   virtual const uint8_t getFifoControlReg() = 0;

 private:
};

#endif
