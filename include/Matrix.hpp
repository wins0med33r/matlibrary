﻿#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <algorithm>
#include <type_traits>
#include <vector>

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
		Matrix(size_t m, size_t n, std::vector<T> data);

		// Destructor
		~Matrix();

		// Copy Constructor
		Matrix(const Matrix<T>& other);

		// Copy Assignment
		Matrix<T>& operator=(const Matrix<T>& other);

		// Move Constructor
		Matrix<T>(Matrix<T>&& other) noexcept;

		// Move Assignment
		Matrix<T>& operator=(Matrix<T>&& other) noexcept;

		/* Overloaded Operators */
		Matrix<T>& operator=(const std::vector<T>& vec);

		template<typename U = T, std::enable_if_t<std::is_arithmetic_v<U> || std::is_same_v<U, std::string>, bool> = true>
		Matrix<T>& operator+=(const Matrix<T>& other);

		template<typename U = T, std::enable_if_t<std::is_arithmetic_v<U>, bool> = true>
		Matrix<T>& operator-=(const Matrix<T>& other);

		template<typename U = T, std::enable_if_t<std::is_arithmetic_v<U>, bool> = true>
		Matrix<T>& operator*=(const Matrix<T>& other);

		template<typename U = T, std::enable_if_t<std::is_arithmetic_v<U>, bool> = true>
		Matrix<T>& operator*=(U scalar);

		T* operator[](size_t row);

		// Append Method
		void append(T input);
	};
}

#endif // MATRIX_H
