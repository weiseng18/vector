#include <gtest/gtest.h>
#include "my_vector.hpp"

class MyVectorTest : public testing::Test {
protected:
  MyVectorTest() {}

  MyVector<int> vec;
};

// Using a test fixture
TEST_F(MyVectorTest, IsEmptyInitially) {
  EXPECT_EQ(vec.size(), 0);
}
