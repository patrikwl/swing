#ifndef SRC_IREGISTERACCESSOR_H
#define SRC_IREGISTERACCESSOR_H

#include <stdint.h>

class IRegisterManager {
 public:
   virtual void setBit(volatile uint8_t &reg, volatile uint8_t position) = 0;
   virtual void clearBit(volatile uint8_t &reg, volatile uint8_t position) = 0;
   virtual uint8_t read8BitRegister(volatile uint8_t &reg) = 0;
   virtual uint16_t read16BitRegister(volatile uint16_t &reg) = 0;
};

#endif // SRC_IREGISTERACCESSOR_H
