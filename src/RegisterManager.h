#ifndef BITMANIPULATOR_H
#define BITMANIPULATOR_H

#include "IRegisterManager.h"

class RegisterManager : public IRegisterManager {
 public:
   RegisterManager();
   void setBit(IRegisterManager::BitField theBitField) override;
   void clearBit(IRegisterManager::BitField theBitField) override;
   uint8_t read8BitRegister(volatile uint8_t &reg) override;
   uint16_t read16BitRegister(volatile uint16_t &reg) override;
   bool isBitSet(IRegisterManager::BitField theBitField) override;

 private:
};

#endif
