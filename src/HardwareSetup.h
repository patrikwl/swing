#include <avr/io.h>

#include "ISpiConfigGetter.h"

#define SpiCsPin PINB2
#define SpiMosiPin PINB3
#define SpiMisoPin 0
#define SpiSckPin PINB5
#define SpiOscDevider ISpiConfigGetter::SpiFrequency::FOSC_8
