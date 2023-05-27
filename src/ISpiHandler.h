#ifndef SRC_ISPIHANDLER_H
#define SRC_ISPIHANDLER_H

#include <stdint.h>

class ISpiHandler {
 public:
   // virtual ~ISomething() {}
   virtual uint8_t const transfer(uint8_t data) = 0;
};
#endif
