#include "ISpiAdapter.h"
#include "SpiHandler.h"
#include <cstdint>
#include <gtest/gtest.h>

class ISpiHandler;

class DummySpiAdaptor : public ISpiAdapter {
 public:
   DummySpiAdaptor() {}

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

class TestSpiHandler : public ::testing::Test {
 public:
   DummySpiAdaptor dummyAdapter;
   SpiHandler spiHandler{&dummyAdapter};

 private:
};

TEST_F(TestSpiHandler, itSendsAndGetsBackExpectedValue)
{
   const uint8_t dataToSend = 0x01;
   const uint8_t expectedReturnData = 0x02;
   dummyAdapter.setRetVal(expectedReturnData);
   uint8_t retVal = spiHandler.transfer(dataToSend);
   ASSERT_EQ(dummyAdapter.getStatus(), DummySpiAdaptor::theStatus::transfereCalled);
   ASSERT_EQ(retVal, expectedReturnData);
}
