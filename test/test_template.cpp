#include "something.h"
#include <cstdint>
#include <gtest/gtest.h>

class TestGtest : public ::testing::Test {
 public:
   Something something;
   uint8_t getIntResult;

 private:
};

TEST_F(TestGtest, firstTest)
{
   getIntResult = something.getInt();
   uint8_t expectedResult = 10;
   ASSERT_EQ(expectedResult, getIntResult);
}

TEST_F(TestGtest, secTest) { ASSERT_EQ(1, 1); }
