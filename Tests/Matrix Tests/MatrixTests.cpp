#include <gtest/gtest.h>
#include <Matrix.hpp>
#include <Matrix.cpp> 

TEST(scalar_multiplication_operator_tests, valid_input)
{
	mp::Matrix<int> test(2, 2, { 1, 2, 3, 4 });

	test *= 10;
	
	EXPECT_EQ(test[0][0], 10); EXPECT_EQ(test[0][1], 20);
	EXPECT_EQ(test[1][0], 30); EXPECT_EQ(test[1][1], 40);
}

TEST(addition_operator_tests, valid_input)
{
	mp::Matrix<int> test(2, 2, { 1, 2, 3, 4 }), test2(2, 2, { 1, 2, 3, 4 });
	
	test += test2;

	EXPECT_EQ(test[0][0], 2); EXPECT_EQ(test[0][1], 4);
	EXPECT_EQ(test[1][0], 6); EXPECT_EQ(test[1][1], 8);
}

