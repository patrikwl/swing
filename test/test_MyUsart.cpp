#include <MyUsart.h>
#include <cstdint>
#include <gtest/gtest.h>

class TestMyUsart : public ::testing::Test {
 public:
   Usart::MyUsart myUsart;

 private:
};

TEST_F(TestMyUsart, firstTest)
{
   getIntResult = something.getInt();
   uint8_t expectedResult = 10;
   ASSERT_EQ(expectedResult, getIntResult);
}

TEST_F(TestGtest, secTest) { ASSERT_EQ(1, 1); }
