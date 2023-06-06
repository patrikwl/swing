#include "RegisterManager.h"

RegisterManager::RegisterManager() {}

void RegisterManager::setBit(IRegisterManager::BitField theBitField) { theBitField.targetReg |= (1 << theBitField.bitIndex); }

void RegisterManager::clearBit(IRegisterManager::BitField theBitField) { theBitField.targetReg &= ~(1 << theBitField.bitIndex); }

uint8_t RegisterManager::read8BitRegister(volatile uint8_t &reg) { return reg; }
uint16_t RegisterManager::read16BitRegister(volatile uint16_t &reg) { return reg; }
