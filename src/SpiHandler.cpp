#include "SpiHandler.h"
#include "ISpiAdapter.h"

SpiHandler::SpiHandler(ISpiAdapter *theSpiAdapter)
    : spiAdapter(theSpiAdapter) {}

;
// SpiHandler::~SpiHandler() {}

uint8_t const SpiHandler::transfer(uint8_t data) { return spiAdapter->transfer(data); }