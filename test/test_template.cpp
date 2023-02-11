#include<gtest/gtest.h>

class TestGtest : public ::testing::Test {
  public:

};

TEST_F(TestGtest, firstTest)
{
    ASSERT_EQ(1, 1);
}

TEST_F(TestGtest, secTest)
{
  ASSERT_EQ(1, 0);
}
