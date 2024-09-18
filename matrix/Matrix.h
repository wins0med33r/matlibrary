#pragma once

namespace mp
{
	template<typename T>
	class Matrix
	{
	private:

		T* _data = nullptr;
		size_t _row = 0;
		size_t _col = 0;

		void resize();

	public:

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
		Matrix<T>& operator=(Matrix<T>&& other) noexcept;

		/* Overloaded Operators */

		Matrix<T>& operator+=(Matrix<T>& other);

		Matrix<T>& operator-=(Matrix<T>& other);

		Matrix<T>& operator*=(Matrix<T>& other);

		Matrix<T>& operator*=(T scalar);
	};
}
