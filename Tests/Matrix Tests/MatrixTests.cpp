#define BOOST_TEST_MODULE MatrixTests

#include <boost/test/included/unit_test.hpp>
#include "Matrix/Matrix.h"
#include "Matrix/Append.h"

BOOST_AUTO_TEST_CASE(Append_AddElement)
{
	mp::Matrix<int> test(2, 2);

	mp::append<int>(test, 1);

	BOOST_ASSERT(test[3][0] == 1);
}
