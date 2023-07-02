#include "IRegisterManager.h"
#include "ISpiConfigGetter.h"
#include "SpiAdapter.h"
#include <gtest/gtest.h>
#include <vector>

bool operator==(const IRegisterManager::BitField &lhs, const IRegisterManager::BitField &rhs)
{
   return lhs.targetReg == rhs.targetReg && lhs.bitIndex == rhs.bitIndex;
}

class FakeSpiConfigGetter : public ISpiConfigGetter {
 public:
   FakeSpiConfigGetter() {}
   virtual ~FakeSpiConfigGetter() {}
   enum class MethodCall {
      getAccelerometerCsPin,
      getAccelerometerCsDataDirectionReg,
      getMosiPin,
      getMosiDataDirectionReg,
      getMisoPin,
      getMisoDataDirectionReg,
      getSckPin,
      getSckDataDirectionReg,
      getClockEnabler,
      getControlReg,
      getSpiEnable,
      getMasterSlaveSelect,
      getClockPolarity,
      getClockPhase,
      getClockRateSelectZero,
      getClockRateSelectOne,
      getInterruptFlag,
      getDoubleSpeed,
      getDataReg
   };
   const IRegisterManager::BitField getAccelerometerCsPin() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getAccelerometerCsPin);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getAccelerometerCsDataDirectionReg() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getAccelerometerCsDataDirectionReg);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }

   const IRegisterManager::BitField getMosiPin() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getMosiPin);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getMosiDataDirectionReg() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getMosiDataDirectionReg);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getMisoPin() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getMisoPin);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getMisoDataDirectionReg() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getMisoDataDirectionReg);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getSckPin() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getSckPin);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getSckDataDirectionReg() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getSckDataDirectionReg);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }

   const SpiFrequency getSckFreqyency() override
   {
      getSckCallCounter += 1;
      return ISpiConfigGetter::SpiFrequency::FOSC_2;
   }
   const IRegisterManager::BitField getClockEnabler() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getClockEnabler);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getControlReg() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getControlReg);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getSpiEnable() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getSpiEnable);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getMasterSlaveSelect() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getMasterSlaveSelect);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getClockPolarity() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getClockPolarity);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getClockPhase() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getClockPhase);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }

   const IRegisterManager::BitField getClockRateSelectZero() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getClockRateSelectZero);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getClockRateSelectOne() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getClockRateSelectOne);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }

   const IRegisterManager::BitField getInterruptFlag() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getInterruptFlag);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   const IRegisterManager::BitField getDoubleSpeed() override
   {
      uint8_t calledMethod = static_cast<uint8_t>(MethodCall::getDoubleSpeed);
      return IRegisterManager::BitField(dummyReg, calledMethod);
   }
   volatile uint8_t &getDataReg() override
   {

      getDataRegCallcounter += 1;
      return dummyDataReg;
   }

   bool getSckHaveBeenCalledOnce() { return getSckCallCounter == 1; }
   uint8_t getGetDataRegCallCounter() { return getDataRegCallcounter; }
   volatile uint8_t getDummyDataReg() { return dummyDataReg; }

 private:
   volatile uint8_t dummyReg = 0;
   uint8_t dummyBit = 0;

 private:
   uint8_t getSckCallCounter = 0;
   uint8_t getDataRegCallcounter = 0;
   volatile uint8_t dummyDataReg = 0;
};

class SpyRegisterManager : public IRegisterManager {
 public:
   SpyRegisterManager() {}
   virtual ~SpyRegisterManager() {}
   void setBit(IRegisterManager::BitField theBitField) override
   {
      bool settingBit = true;
      std::pair<FakeSpiConfigGetter::MethodCall, bool> inputArg(
          static_cast<FakeSpiConfigGetter::MethodCall>(theBitField.bitIndex), settingBit);
      argContainer.push_back(inputArg);
   }
   void clearBit(IRegisterManager::BitField theBitField) override
   {
      bool settingBit = false;
      std::pair<FakeSpiConfigGetter::MethodCall, bool> inputArg(
          static_cast<FakeSpiConfigGetter::MethodCall>(theBitField.bitIndex), settingBit);
      argContainer.push_back(inputArg);
   }
   uint8_t read8BitRegister(volatile uint8_t &reg) override {}
   uint16_t read16BitRegister(volatile uint16_t &reg) override {}
   bool isBitSet(IRegisterManager::BitField theBitField) override { return isBitSetRetVal; }

   bool isConfigUniquelySet(FakeSpiConfigGetter::MethodCall calls, bool settingBit)
   {
      uint8_t counter = 0;
      for (const auto &pair : argContainer) {
         if (pair.first == calls && pair.second == settingBit) {
            counter += 1;
         }
      }
      if (counter == 1) {
         return true;
      }
      else {
         return false;
      }
   }

   void IsBitSetReturnsTrue() { isBitSetRetVal = true; }

 private:
   std::vector<std::pair<FakeSpiConfigGetter::MethodCall, bool>> argContainer;
   bool isBitSetRetVal = false;
};

class TestSpiAdapter : public ::testing::Test {
 public:
   TestSpiAdapter() {}
   ~TestSpiAdapter() {}
   SpyRegisterManager spyRegisterManager;
   FakeSpiConfigGetter confGetter;
   SpiAdapter spiAdapter{&spyRegisterManager, &confGetter};

   bool isConfigCleared(FakeSpiConfigGetter::MethodCall config) { return spyRegisterManager.isConfigUniquelySet(config, false); }
   bool isConfigSet(FakeSpiConfigGetter::MethodCall config) { return spyRegisterManager.isConfigUniquelySet(config, true); }

 private:
};

TEST_F(TestSpiAdapter, testWorks) { ASSERT_TRUE(true); }

TEST_F(TestSpiAdapter, itEnablesSpiClock) { ASSERT_TRUE(isConfigCleared(FakeSpiConfigGetter::MethodCall::getClockEnabler)); }
TEST_F(TestSpiAdapter, itEnablesSpi) { ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getSpiEnable)); }
TEST_F(TestSpiAdapter, itsSetsMasterSpiRole) { ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getMasterSlaveSelect)); }
TEST_F(TestSpiAdapter, itSetsClockPolarity) { ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getClockPolarity)); }
TEST_F(TestSpiAdapter, itSetsClockPhase) { ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getClockPhase)); }
TEST_F(TestSpiAdapter, SckSpeed)
{
   ASSERT_TRUE(confGetter.getSckHaveBeenCalledOnce());
   ASSERT_TRUE(isConfigCleared(FakeSpiConfigGetter::MethodCall::getClockRateSelectZero));
   ASSERT_TRUE(isConfigCleared(FakeSpiConfigGetter::MethodCall::getClockRateSelectOne));
   ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getDoubleSpeed));
}

TEST_F(TestSpiAdapter, itSetsAccelerometerCsPinAsOutput)
{
   ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getAccelerometerCsDataDirectionReg));
}

TEST_F(TestSpiAdapter, itSetsMosiPinAsOutput)
{
   ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getMosiDataDirectionReg));
}
TEST_F(TestSpiAdapter, itSetsSckPinAsOutput)
{
   ASSERT_TRUE(isConfigSet(FakeSpiConfigGetter::MethodCall::getSckDataDirectionReg));
}
TEST_F(TestSpiAdapter, itSetsMisoPinAsInput)
{
   ASSERT_TRUE(isConfigCleared(FakeSpiConfigGetter::MethodCall::getMisoDataDirectionReg));
}

TEST_F(TestSpiAdapter, transferCopiesArgToDataReg)
{
   spyRegisterManager.IsBitSetReturnsTrue();
   uint8_t testData = 0x11;
   uint8_t retVal = spiAdapter.transfer(testData);
   ASSERT_EQ(testData, retVal);
   ASSERT_EQ(confGetter.getDummyDataReg(), testData);
   ASSERT_EQ(confGetter.getGetDataRegCallCounter(), 2);
}
