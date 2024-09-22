#include "Matrix.hpp"
#include <type_traits>
#include <stdexcept>

namespace mp
{
	template<typename T>
	Matrix<T>::Matrix(size_t m, size_t n) : _row(m), _col(n), _data(new T[m * n]()) {}

	template<typename T>
	Matrix<T>::~Matrix()
	{
		delete[] _data;
		_data = nullptr;
	}

	template<typename T>
	void Matrix<T>::resize()
	{
		T* temp = _data;
		delete[] _data;

		size_t additional_size = _col;
		_data = new T[_row * _col + additional_size]();

		for (int i = 0; i < _row * _col; i++)
		{
			_data[i] = temp[i];
		}

		delete[] temp;
	}

	template<typename T>
	Matrix<T>::Matrix(const Matrix<T>& other) : _row(other._row), _col(other._col), _data(*other._data) {}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
	{
		if (*this == other)
		{
			return *this;
		}

		delete[] _data;

		_row = other._row;
		_col = other._col;

		_data = other._data;

		return *this;
	}

	template<typename T>
	Matrix<T>::Matrix(Matrix<T>&& other) noexcept : _data(other._data)
	{
		other._data = nullptr;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept
	{
		if (*this == other)
		{
			return *this;
		}

		delete[] _data;
		_data = other._data;
		other._data = nullptr;

		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
	{
		static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, "Type is not compatible for addition.");

		if (_row != other._row && _col != other._col)
		{
			throw std::length_error("Matrices must be of the same dimension for addition.");
		}

		for (int i = 0; i < _row * _col; i++)
		{
			_data[i] += other._data[i];
		}

		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
	{
		static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");

		if (_row != other._row && _col != other._col)
		{
			throw std::length_error("Matrices must be of the same dimension for substraction.");
		}

		for (int i = 0; i < _row * _col; i++)
		{
			_data[i] -= other._data[i];
		}

		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other)
	{
		static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");

		if (_col != other._row)
		{
			throw std::length_error("Invalid dimensions for multiplication.");
		}

		T* new_data = new T[_col * other._row]();

		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < other._col; j++)
			{
				for (int k = 0; k < other._row; k++)
				{
					new_data[i * _row + j] += _data[i * _row + k] * other._data[k * _row + j];
				}
			}
		}

		delete[] _data;
		_data = new_data;

		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator*=(T scalar)
	{
		static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");

		for (int i = 0; i < _row * _col; i++)
		{
			_data[i] *= scalar;
		}

		return *this;
	}

	template<typename T>
	T* Matrix<T>::operator[](size_t row)
	{
		return &_data[row * _col];
	}

	template<typename T>
	void Matrix<T>::append(T input)
	{
		resize();
		_data[_row * _col - _col] = input;

		return;
	}
}
