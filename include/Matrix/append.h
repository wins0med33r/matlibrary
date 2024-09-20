#pragma once
#include "Matrix.h"

namespace mp
{
	template<typename T>
	void append(Matrix<T>& mat, T input)
	{
		mat.resize();
		mat._data[mat._row * mat._col - mat._col] = input;
		return;
	};
}