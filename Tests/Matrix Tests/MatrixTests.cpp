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

TEST(addition_operator_tests, valid_input_arithmetic)
{
	mp::Matrix<int> test1(2, 2, { 1, 2, 3, 4 }), test2(2, 2, { 1, 2, 3, 4 });
	
	test1 += test2;

	EXPECT_EQ(test1[0][0], 2); EXPECT_EQ(test1[0][1], 4);
	EXPECT_EQ(test1[1][0], 6); EXPECT_EQ(test1[1][1], 8);
}

TEST(addition_operator_tests, invalid_input_arithemetic)
{
	mp::Matrix<int> test1(2, 3, { 1, 2, 3, 4, 5 }), test2(2, 2, { 1, 2, 3, 4 });

	ASSERT_THROW(test1 += test2, std::length_error);
}

TEST(addition_operator_tests, valid_input_string)
{
	mp::Matrix<std::string> test1(2, 2, { "hi", "hi", "hi", "hi" }), test2(2, 2, { "bye", "bye", "bye", "bye" });

	test1 += test2;

	EXPECT_EQ(test1[0][0], "hibye"); EXPECT_EQ(test1[0][1], "hibye");
	EXPECT_EQ(test1[1][0], "hibye"); EXPECT_EQ(test1[1][1], "hibye");
}

TEST(subtraction_operator_tests, valid_input_arithmetic)
{
	mp::Matrix<int> test1(2, 2, { 2, 4, 6, 8 }), test2(2, 2, { 1, 2, 3, 4 });

	test1 -= test2;

	EXPECT_EQ(test1[0][0], 1); EXPECT_EQ(test1[0][1], 2);
	EXPECT_EQ(test1[1][0], 3); EXPECT_EQ(test1[1][1], 4);
}

TEST(subtraction_operator_tests, invalid_input_arithemetic)
{
	mp::Matrix<int> test1(2, 3, { 1, 2, 3, 4, 5 }), test2(2, 2, { 1, 2, 3, 4 });

	ASSERT_THROW(test1 -= test2, std::length_error);
}

TEST(multiplication_operator_tests, valid_input_arithmetic)
{
	mp::Matrix<int> test1(2, 2, { 1, 2, 3, 4 }), test2(2, 2, { 1, 2, 3, 4 });

	test1 *= test2;

	EXPECT_EQ(test1[0][0], 7); EXPECT_EQ(test1[0][1], 10);
	EXPECT_EQ(test1[1][0], 15); EXPECT_EQ(test1[1][1], 22);
}

TEST(multiplication_operator_tests, invalid_input_arithemetic)
{
	mp::Matrix<int> test1(2, 3, { 1, 2, 3, 4, 5 }), test2(2, 2, { 1, 2, 3, 4 });

	ASSERT_THROW(test1 *= test2, std::length_error);
}

TEST(move_constructor_tests, valid_input)
{
	mp::Matrix<int> test1(2, 2, { 1, 2, 3, 4 }), test2(std::move(test1));

	EXPECT_EQ(test2[0][0], 1); EXPECT_EQ(test2[0][1], 2);
	EXPECT_EQ(test2[1][0], 3); EXPECT_EQ(test2[1][1], 4);
}

TEST(move_assignment_tests, valid_input)
{
	mp::Matrix<int> test1(2, 2, { 1, 2, 3, 4 }), test2(2, 2);

	test2 = std::move(test1);

	EXPECT_EQ(test2[0][0], 1); EXPECT_EQ(test2[0][1], 2);
	EXPECT_EQ(test2[1][0], 3); EXPECT_EQ(test2[1][1], 4);
}

TEST(copy_constructor_tests, valid_input)
{
	mp::Matrix<int> test1(2, 2, { 1, 2, 3, 4 }), test2(2, 2);

	test2 = test1;

	EXPECT_EQ(test2[0][0], 1); EXPECT_EQ(test2[0][1], 2);
	EXPECT_EQ(test2[1][0], 3); EXPECT_EQ(test2[1][1], 4);
}

TEST(append_method_tests, standard_input)
{
	mp::Matrix<int> test(2, 2, { 1, 2, 3, 4 });

	test.append(5);

	EXPECT_EQ(test[2][0], 5);
}
