#ifndef BITMANIPULATOR_H
#define BITMANIPULATOR_H

#include "IRegisterManager.h"

class RegisterManager : public IRegisterManager {
 public:
   RegisterManager();
   void setBit(volatile uint8_t &reg, volatile uint8_t bitPosition) override;
   void clearBit(volatile uint8_t &reg, volatile uint8_t bitPosition) override;
   uint8_t read8BitRegister(volatile uint8_t &reg) override;
   uint16_t read16BitRegister(volatile uint16_t &reg) override;

 private:
};

#endif
