#define BOOST_TEST_MODULE MatrixTests

#include <boost/test/included/unit_test.hpp>
#include <Matrix.hpp> 
#include <Matrix.cpp> 

BOOST_AUTO_TEST_CASE(ScalarMultiplication_Operator_Test)
{
	mp::Matrix<int> test(2, 2);

	test[0][1] = 1;
	test *= 10;

	BOOST_ASSERT(test[0][1] == 10);
}
