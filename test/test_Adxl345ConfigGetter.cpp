#include "Adxl345ConfigGetter.h"
#include "Adxl345RegisterMap.h"
#include <cstdint>
#include <gtest/gtest.h>

class TestAdxlConfigGetter : public ::testing::Test {
 public:
   Adxl345ConfigGetter getter;

 private:
};

TEST_F(TestAdxlConfigGetter, testWorks) { ASSERT_TRUE(true); }

TEST_F(TestAdxlConfigGetter, itGetsFifoCtlReg)
{
   const uint8_t fifoCtlReg = getter.getFifoControlReg();
   ASSERT_EQ(fifoCtlReg, FIFO_CTL);
}
