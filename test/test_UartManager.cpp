#include "IUartAdapter.h"
#include "UartManager.h"
#include <cstdint>
#include <gtest/gtest.h>

class FakeUartAdaptor : public IUartAdapter {
 public:
   FakeUartAdaptor() {}
   ~FakeUartAdaptor() {}

   enum class theStatus { undefined, transfered, waited };

   void waitForEmptyTransmitBuffer() override
   {
      waitCounter += 1;
      status = theStatus::waited;
   }

   void putChar(const char &data) override
   {
      putCharContainer[containerFlag] = data;
      containerFlag += 1;
      return;
   }

   theStatus getStatus() { return status; }
   void setRetVal(uint8_t dataToSet) { retVal = dataToSet; }
   uint16_t getWaitCounter() { return waitCounter; }
   char *getPutCharContainer()
   {
      putChar('\0'); // enables str eq. Any better soluton?
      return putCharContainer;
   }

 private:
   theStatus status = theStatus::undefined;
   uint8_t retVal;
   uint16_t waitCounter = 0;
   uint8_t containerFlag = 0;
   char putCharContainer[0x11111111];
};

class TestUartManager : public ::testing::Test {
 public:
   void SetUp() override
   {
      fakeAdapter = new FakeUartAdaptor();
      uartHandler = new UartManager(fakeAdapter);
   }

   void TearDown() override
   {
      delete fakeAdapter;
      delete uartHandler;
   }

   FakeUartAdaptor *fakeAdapter;
   UartManager *uartHandler;

 private:
};

TEST_F(TestUartManager, testBuilds) { ASSERT_TRUE(true); }

TEST_F(TestUartManager, transmit16bitsPutsTheExpectedChars)
{
   const int16_t dataTosend{666};
   uartHandler->transmit16Bits(dataTosend);
   const char expectedVaue[] = "666";
   EXPECT_STREQ(fakeAdapter->getPutCharContainer(), expectedVaue);
   EXPECT_EQ(fakeAdapter->getWaitCounter(), 3);
}

TEST_F(TestUartManager, transmit16bitsCanSendNegativeNumbers)
{
   const int16_t dataTosend{-666};
   uartHandler->transmit16Bits(dataTosend);
   const char expectedVaue[] = "-666";
   EXPECT_STREQ(fakeAdapter->getPutCharContainer(), expectedVaue);
   EXPECT_EQ(strlen(expectedVaue), strlen(fakeAdapter->getPutCharContainer()));
   EXPECT_EQ(fakeAdapter->getWaitCounter(), 4);
}

TEST_F(TestUartManager, transmit16BitsWaitsForEmptyBufferTenTimesOnMaxint16Value)
{
   // 65535
   const int16_t dataTosend{32767};
   uartHandler->transmit16Bits(dataTosend);
   ASSERT_EQ(fakeAdapter->getWaitCounter(), 5);
}

TEST_F(TestUartManager, transmit16BitsCanOverflow)
{
   const int16_t dataTosend = 32768;
   const char expectedVaue[] = "-32768";
   uartHandler->transmit16Bits(dataTosend);
   ASSERT_EQ(fakeAdapter->getWaitCounter(), strlen(expectedVaue));
   EXPECT_STREQ(fakeAdapter->getPutCharContainer(), expectedVaue);
}

TEST_F(TestUartManager, transmit16BitsCanSendAZero)
{
   const int16_t dataTosend = 0;
   const char expectedVaue[] = "0";
   uartHandler->transmit16Bits(dataTosend);
   ASSERT_EQ(fakeAdapter->getWaitCounter(), strlen(expectedVaue));
   EXPECT_STREQ(fakeAdapter->getPutCharContainer(), expectedVaue);
}

TEST_F(TestUartManager, transmitString)
{
   const char *dataToSend = "test: 555 x/s";
   uartHandler->transmitString(dataToSend);
   EXPECT_STREQ(fakeAdapter->getPutCharContainer(), dataToSend);
   ASSERT_EQ(fakeAdapter->getWaitCounter(), strlen(dataToSend));
}
