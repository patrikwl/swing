#include "IUartAdapter.h"
#include "UartManager.h"
#include <cstdint>
#include <gtest/gtest.h>

class FakeUartAdaptor : public IUartAdapter {
 public:
   FakeUartAdaptor() {}

   enum class theStatus {
      undefined,
      transfereCalled,
   };

   uint8_t const transfer(uint8_t const data) override
   {
      status = theStatus::transfereCalled;
      return retVal;
   }

   theStatus getStatus() { return status; }
   void setRetVal(uint8_t dataToSet) { retVal = dataToSet; }

 private:
   theStatus status = theStatus::undefined;
   uint8_t retVal;
};

class TestUartManager : public ::testing::Test {
 public:
   FakeUartAdaptor dummyAdapter;
   UartHandler uartHandler{&dummyAdapter};

 private:
};

TEST_F(TestUartManager, testBuilds) { ASSERT_TRUE(true); }
