#include "IUartManager.h"
#include <gtest/gtest.h>

class DummyUartManager : public IUartManager {
 public:
   DummyUartManager() {}
   ~DummyUartManager() {}
   void transmit16Bits(int16_t const dataToSend) override {}
   void transmitString(const char *buffer) override {}
};

IUartManager *uartManager;

int main()
{
   DummyUartManager uartManagerInstance;
   uartManager = &uartManagerInstance;
   testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}
