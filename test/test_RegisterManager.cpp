#include "RegisterManager.h"
#include "src/IRegisterManager.h"
#include <gtest/gtest.h>

class TestRegisterManager : public ::testing::Test {
 public:
   RegisterManager accessor;
   volatile uint16_t TEST_16BREGISTER{0b1000000000000001};

 private:
};

TEST_F(TestRegisterManager, testBuilds) { ASSERT_TRUE(true); }

TEST_F(TestRegisterManager, itSetsABit)
{
   volatile uint8_t TestRegister{0b00000000};
   uint8_t expectedResult = 0b00000001;
   IRegisterManager::BitField bitField(TestRegister, 0);

   accessor.setBit(bitField);

   ASSERT_EQ(TestRegister, expectedResult);
}

TEST_F(TestRegisterManager, itClearsABit)
{
   volatile uint8_t TestRegister{0b00000001};
   uint8_t expectedResult = 0b00000000;
   IRegisterManager::BitField bitField(TestRegister, 0);

   accessor.clearBit(bitField);

   ASSERT_EQ(TestRegister, expectedResult);
}

// TEST_F(TestRegisterManager, itReadsA8BitReg)
// {
//    volatile uint8_t TestRegister{0b10000001}
//    uint8_t result = accessor.read8BitRegister(TestRegister);
//    uint8_t expectedResult = 0b10000001;
//    ASSERT_EQ(expectedResult, result);
// }

// TEST_F(TestRegisterManager, itReadsA16BitReg)
// {
//    uint16_t result = accessor.read16BitRegister(TEST_16BREGISTER);
//    uint16_t expectedResult = 0b1000000000000001;
//    ASSERT_EQ(expectedResult, result);
// }
