#include <gtest/gtest.h>
#include "my_vector.hpp"

class MyVectorResizeTest : public testing::Test {
protected:
  MyVectorResizeTest() {
    for (int i = 0; i < 4; i++) {
      vec.push_back(i);
    }
  }

  MyVector<int> vec;
};

TEST_F(MyVectorResizeTest, DoubleCapacityWhenInsertingWhenFull) {
  // Verify initial state
  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec.capacity(), 4);

  vec.push_back(4);

  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(vec.capacity(), 8);
}

TEST_F(MyVectorResizeTest, HalveCapacityWhenQuarterFull) {
  // Verify initial state
  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec.capacity(), 4);

  // After running pop_back() 3 times,
  // vec.size() should be 1 and vec.capacity() should be 4,
  // triggering the resize.
  for (int i = 0; i < 3; i++) {
    vec.pop_back();
  }

  EXPECT_EQ(vec.size(), 1);
  EXPECT_EQ(vec.capacity(), 2);
}
