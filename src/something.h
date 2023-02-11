#ifndef SRC_SOMETHING_H
#define SRC_SOMETHING_H

#include "Isomething.h"

class Something : public ISomething {
    public:
       Something();
       virtual ~Something();
       virtual uint8_t getInt() override;
};

#endif
