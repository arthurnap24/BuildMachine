#include "whattotest.cpp"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) {
  ASSERT_EQ(6, squareRoot(36.0));
}

TEST(SquareRootTest, NegativeNos) {
  ASSERT_EQ(-1.0, squareRoot(-15.0));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
