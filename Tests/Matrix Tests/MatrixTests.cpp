#define BOOST_TEST_MODULE MatrixTests

#include <boost/test/included/unit_test.hpp>
#include "Matrix/Matrix.h"

BOOST_AUTO_TEST_CASE(simple_test)
{
	mp::Matrix<int> test(2, 2);

	std::cout << "HELLO" << std::endl;

	BOOST_ASSERT(true);
}
