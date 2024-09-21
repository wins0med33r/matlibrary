#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

namespace mp
{
	template<typename T>
	class Matrix
	{
	public:

		T* _data = nullptr;
		size_t _row = 0, _col = 0;
		void resize();

		// Constructors
		Matrix(size_t m, size_t n);

		// Destructor
		~Matrix();

		// Copy Constructor
		Matrix(const Matrix<T>& other);

		// Copy Assignment
		Matrix<T>& operator=(const Matrix<T>& other);

		// Move Constructor
		Matrix<T>(Matrix<T>&& other) noexcept;

		// Move Assignment
		Matrix<T>& operator=(const Matrix<T>&& other) noexcept;

		/* Overloaded Operators */

		Matrix<T>& operator+=(const Matrix<T>& other);

		Matrix<T>& operator-=(const Matrix<T>& other);

		Matrix<T>& operator*=(const Matrix<T>& other);

		Matrix<T>& operator*=(T scalar);

		T* operator[](size_t row);

		// Append Method
		void append(T input);
	};
}

#endif // MATRIX_H
