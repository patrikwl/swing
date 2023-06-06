#include "RegisterManager.h"

RegisterManager::RegisterManager() {}

void RegisterManager::setBit(volatile uint8_t &reg, const uint8_t bitPosition) { reg |= (1 << bitPosition); }
void RegisterManager::clearBit(volatile uint8_t &reg, const uint8_t bitPosition) { reg &= ~(1 << bitPosition); }

uint8_t RegisterManager::read8BitRegister(volatile uint8_t &reg) { return reg; }
uint16_t RegisterManager::read16BitRegister(volatile uint16_t &reg) { return reg; }
