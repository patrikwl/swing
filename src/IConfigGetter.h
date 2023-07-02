#ifndef IMCUCONFIGGETTER_H
#define IMCUCONFIGGETTER_H

#include "IRegisterManager.h"
#include <stdint.h>

class IConfigGetter {
 public:
   virtual const IRegisterManager::BitField getLedDataDirectionReg() = 0;
   virtual const IRegisterManager::BitField getLedPin() = 0;
};

#endif
