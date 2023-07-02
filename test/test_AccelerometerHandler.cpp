#include "AccelerometerHandler.h"
// #include "ConfigGetter.h"
#include "Adxl345ConfigGetter.h"
#include "ISpiConfigGetter.h"
#include "ISpiHandler.h"
#include "RegisterManager.h"
#include <cstdint>
#include <gtest/gtest.h>

class DummySpiHandler : public ISpiHandler {
 public:
   DummySpiHandler() {}
   ~DummySpiHandler() {}
   uint8_t const transfer(uint8_t data) override { return 1; }
};

class DummySpiConfigGetter : public ISpiConfigGetter {
 public:
   DummySpiConfigGetter() {}
   ~DummySpiConfigGetter() {}
   // SPI
   const IRegisterManager::BitField getAccelerometerCsPin() override {}
   const IRegisterManager::BitField getAccelerometerCsDataDirectionReg() override {}

   const IRegisterManager::BitField getMosiPin() override {}
   const IRegisterManager::BitField getMisoPin() override {}
   const IRegisterManager::BitField getSckPin() override {}
   const IRegisterManager::BitField getMosiDataDirectionReg() override {}
   const IRegisterManager::BitField getMisoDataDirectionReg() override {}
   const IRegisterManager::BitField getSckDataDirectionReg() override {}

   const ISpiConfigGetter::SpiFrequency getSckFreqyency() override {}
   const IRegisterManager::BitField getClockEnabler() override {}

   const IRegisterManager::BitField getControlReg() override {}
   const IRegisterManager::BitField getSpiEnable() override {}
   const IRegisterManager::BitField getMasterSlaveSelect() override {}
   const IRegisterManager::BitField getClockPolarity() override {}
   const IRegisterManager::BitField getClockPhase() override {}
   const IRegisterManager::BitField getClockRateSelectZero() override {}
   const IRegisterManager::BitField getClockRateSelectOne() override {}

   const IRegisterManager::BitField getInterruptFlag() override {}
   const IRegisterManager::BitField getDoubleSpeed() override {}
   volatile uint8_t &getDataReg() override {}
};

class TestAccelerometerHandler : public ::testing::Test {
 public:
   TestAccelerometerHandler() {}
   ~TestAccelerometerHandler() {}
   RegisterManager regManager;
   // ConfigGetter confGetter;
   DummySpiConfigGetter dummySpiConfGetter;
   Adxl345ConfigGetter adxlConfGetter;
   DummySpiHandler dummySpiHandler;
   AccelerometerHandler handler{&dummySpiConfGetter, &adxlConfGetter, &dummySpiHandler, &regManager};

   // AccelerometerHandler(ISpiConfigGetter *theSpiConfigGetter, IAdxl345ConfigGetter *theAccelConfigGetter, ISpiHandler
   // *theSpiHandler,
   //                         IRegisterManager *theRegisterManager);

 private:
};

TEST_F(TestAccelerometerHandler, testWorks) { ASSERT_TRUE(true); }

TEST_F(TestAccelerometerHandler, singleReadReturnsSetEightThBit)
{
   uint8_t testReg = 0b00000000;
   uint8_t expectedResult = 0b10000000;
   uint8_t result = handler.singleRead(testReg);
   ASSERT_EQ(expectedResult, result);
}

TEST_F(TestAccelerometerHandler, singleWriteReturnsUnSetEightThBit)
{
   uint8_t testReg = 0b10000000;
   uint8_t expectedResult = 0b00000000;
   uint8_t result = handler.singleWrite(testReg);
   ASSERT_EQ(expectedResult, result);
}

TEST_F(TestAccelerometerHandler, multiReadReturnsSetEightThAndSeventThBit)
{
   uint8_t testReg = 0b00000000;
   uint8_t expectedResult = 0b11000000;
   uint8_t result = handler.multiRead(testReg);
   ASSERT_EQ(expectedResult, result);
}

TEST_F(TestAccelerometerHandler, multiWriteReturnsSevenThBitSet)
{
   uint8_t testReg = 0b00000000;
   uint8_t expectedResult = 0b01000000;
   uint8_t result = handler.multiWrite(testReg);
   ASSERT_EQ(expectedResult, result);
}
