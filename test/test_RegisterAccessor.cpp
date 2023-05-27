#include "RegisterAccessor.h"
#include <gtest/gtest.h>

volatile uint8_t TEST_REGISTER{0b10000010};
volatile uint16_t TEST_16BREGISTER{0b1000000000000001};

// uint16_t
// class IRegisterAccessor;
class IRegisterAccessor;

class TestRegisterAccessor : public ::testing::Test {
 public:
   RegisterAccessor accessor;

 private:
};

TEST_F(TestRegisterAccessor, testBuilds) { ASSERT_TRUE(true); }

TEST_F(TestRegisterAccessor, itSetsABit)
{
   accessor.setBit(TEST_REGISTER, 0);
   uint8_t expectedResult = 0b10000011;
   ASSERT_EQ(TEST_REGISTER, expectedResult);
}

TEST_F(TestRegisterAccessor, itClearsABit)
{
   accessor.clearBit(TEST_REGISTER, 1);
   uint8_t expectedResult = 0b10000001;
   ASSERT_EQ(TEST_REGISTER, expectedResult);
}

TEST_F(TestRegisterAccessor, itReadsA8BitReg)
{
   uint8_t result = accessor.read8BitRegister(TEST_REGISTER);
   uint8_t expectedResult = 0b10000001;
   ASSERT_EQ(expectedResult, result);
}

TEST_F(TestRegisterAccessor, itReadsA16BitReg)
{
   uint16_t result = accessor.read16BitRegister(TEST_16BREGISTER);
   uint16_t expectedResult = 0b1000000000000001;
   ASSERT_EQ(expectedResult, result);
}