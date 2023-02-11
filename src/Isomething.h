#ifndef SRC_ISOMETHING_H
#define SRC_ISOMETHING_H

#include<stdint.h>

class ISomething {
    public:
        virtual ~ISomething() {}
        virtual uint8_t getInt() = 0;
};

#endif
