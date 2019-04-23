#ifndef MATH_LINEAR_ALGEBRA_MATRIX_H
#define MATH_LINEAR_ALGEBRA_MATRIX_H

#include <initializer_list>
#include <assert.h>
#include "vector.h"

namespace math
{
	/*
	| e[0][0]  e[1][0]  e[2][0]  e[3][0] |

	| e[0][1]  e[1][1]  e[2][1]  e[3][1] |.

	| e[0][2]  e[1][2]  e[2][2]  e[3][2] |

	| e[0][3]  e[1][3]  e[2][3]  e[3][3] |
	*/

	template <std::size_t m,std::size_t n,typename T>
	struct matrix
	{
		//m 行 n 列 
		union
		{
			T e[n][m];
			struct
			{
				vector<m, T>col[n];
			};
		};

		matrix()
		{
			for (std::size_t col = 0; col < n; ++col)
			{
				for (std::size_t row = 0; row < m; ++row)
				{
					e[col][row] = col == row ? T(1.0f) : T(0.0f);
				}
			}
		}

		matrix(const std::initializer_list<T> args)
		{
			assert(args.size() <= m * n);
			std::size_t cols = 0, rows = 0;
			for (auto& it : args)
			{
				e[cols][rows++] = it;
				if (rows >= m)
				{
					++cols;
					rows = 0;
				}
			}
		}


		vector<m, T>& operator[](const std::size_t colIndex)
		{
			assert(colIndex >= 0 && colIndex < n);
			return col[colIndex];
		}
	};

	typedef matrix<2, 2, float>mat2;
	typedef matrix<3, 3, float>mat3;
	typedef matrix<4, 4, float>mat4;
	typedef matrix<2, 2, double>dmat2;
	typedef matrix<3, 3, double>dmat3;
	typedef matrix<4, 4, double>dmat4;
	
	//矩阵相加
	template<std::size_t m,std::size_t n,typename T>
	matrix<m, n, T>operator+(matrix<m, n, T>&lhs, matrix<m, n, T>&rhs)
	{
		matrix<m, n, T>result;
		for (std::size_t col = 0; col < n; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				result[col][row] = lhs[col][row] + rhs[col][row];
			}
		}
		return result;
	}

	//矩阵相减
	template<std::size_t m, std::size_t n, typename T>
	matrix<m, n, T>operator-(matrix<m, n, T>&lhs, matrix<m, n, T>&rhs)
	{
		matrix<m, n, T>result;
		for (std::size_t col = 0; col < n; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				result[col][row] = lhs[col][row] - rhs[col][row];
			}
		}
		return result;
	}

	//矩阵乘法	
	template<std::size_t m,std::size_t n,std::size_t o,typename T>
	matrix<m, o, T>operator*(matrix<m, n, T>& lhs, matrix<n, o, T>& rhs)
	{
		matrix<m, o, T>result;
		for (std::size_t col = 0; col < o; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				T value = {};
				for (std::size_t j = 0; j < n; ++j)
					value += lhs[j][row] * rhs[col][j];
				
				result[col][row] = value;
			}
		}
		return result;
	}

	// 矩阵乘法 直接将结果存在提供的矩阵中
	template <std::size_t m, std::size_t n, std::size_t o, typename T>
	matrix<m, o, T>& mul(matrix <m, n, T> &result, const matrix<m, n, T>& lhs, const matrix<n, o, T>& rhs)
	{
		for (std::size_t col = 0; col < o; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				T value = {};
				for (std::size_t j = 0; j < n; ++j) // j equals col in math notation (i = row)
				{
					value += lhs[j][row] * rhs[col][j];
				}
				result[col][row] = value;
			}
		}
		return result;
	}

	// 矩阵 乘  向量 
	template<std::size_t m,std::size_t n,typename T>
	vector<m, T>operator*(matrix<m, n, T>& lhs, vector<n, T>& rhs)
	{
		vector<m, T>result;
		for (std::size_t row = 0; row < m; ++row)
		{
			T value = {};
			for (std::size_t j = 0; j < n; ++j)
			{
				value += lhs[j][row] * rhs[j];
			}
			result[row] = value;
		}
		return result;
	}














}






#endif // !MATH_LINEAR_ALGEBRA_MATRIX_H
