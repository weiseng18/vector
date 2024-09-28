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

TEST_F(MyVectorTest, PushBackOnEmptyVector) {
  vec.push_back(1);
  EXPECT_EQ(vec.size(), 1);
}

TEST_F(MyVectorTest, PushBackOnNonemptyVector) {
  vec.push_back(1);

  vec.push_back(2);
  EXPECT_EQ(vec.size(), 2);
}
