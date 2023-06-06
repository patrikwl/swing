#ifndef SRC_IREGISTERACCESSOR_H
#define SRC_IREGISTERACCESSOR_H

#include <stdint.h>

class IRegisterManager {
 public:
   struct BitField {
      volatile uint8_t &targetReg;
      uint8_t bitIndex;
      BitField(volatile uint8_t &theReg, uint8_t index) : targetReg(theReg), bitIndex(index) {}
   };

   virtual void setBit(IRegisterManager::BitField theBitField) = 0;
   virtual void clearBit(IRegisterManager::BitField theBitField) = 0;
   virtual uint8_t read8BitRegister(volatile uint8_t &reg) = 0;
   virtual uint16_t read16BitRegister(volatile uint16_t &reg) = 0;
};

#endif // SRC_IREGISTERACCESSOR_H
