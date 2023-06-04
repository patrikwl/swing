#ifndef SRC_ISPIADAPTER_H
#define SRC_ISPIADAPTER_H

#include <stdint.h>
// #include <inttypes.h>

class ISpiAdapter {
 public:
   virtual uint8_t const transfer(uint8_t const data) = 0;
};
#endif
