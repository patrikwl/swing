#include "RegisterAccessor.h"

RegisterAccessor::RegisterAccessor() {}

void RegisterAccessor::setBit( volatile uint8_t &reg, const uint8_t bitPosition) { reg |= (1 << bitPosition); }
void RegisterAccessor::clearBit( volatile uint8_t &reg, const uint8_t bitPosition) { reg &= ~(1 << bitPosition); }

uint8_t RegisterAccessor::read8BitRegister( volatile uint8_t &reg) { return reg; }
uint16_t RegisterAccessor::read16BitRegister( volatile uint16_t &reg) { return reg; }