#include <gtest/gtest.h>
#include <something.h>

class TestGtest : public ::testing::Test {
 public:
   Something something;
};

TEST_F(TestGtest, firstTest) { ASSERT_EQ(1, something.getInt()); }

TEST_F(TestGtest, secTest) { ASSERT_EQ(1, 0); }
