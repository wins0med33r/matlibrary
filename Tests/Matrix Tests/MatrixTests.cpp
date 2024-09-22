#include <gtest/gtest.h>
#include <Matrix.hpp> 
#include <Matrix.cpp> 

TEST(scalar_multiplication_operator_tests, ScalarMultiplication_Operator_Test)
{
	mp::Matrix<int> test(2, 2);

	test[0][1] = 1;
	test *= 10;
	
	EXPECT_EQ(test[0][1], 10);
}
