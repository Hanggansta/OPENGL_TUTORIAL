#ifndef MATH_COMMON_H
#define MATH_COMMON_H


#include"vector.h"
#include<algorithm>
#include<cmath>


namespace math
{
	template <typename T>
	inline T lerp(const T& a, const T& b, const float t)
	{
		return (1.0f - t)*a + b * t;
	}
	template<std::size_t n,typename T>
	inline vector<n, T>lerp(vector<n, T>& a, vector<n, T>& b, const float t)
	{
		vector<n, T>result;
		for (std::size_t i= 0; i < n; ++i)
		{
			result[i] = lerp(a[i], b[i], t);
		}	
		return result;
	}
	template<typename T>
	inline T clamp(const T& val, const T& min, const T& max)
	{
		return max(min, std::min(val, max));
	}
    template<std::size_t n,typename T>
	inline vector<n, T> clamp(const vector<n, T>& val, const T& min, const T& max)
	{
		vector<n, T>result;
		for (std::size_t i = 0; i < n; ++i)
			result[i] = clamp(val[i], min, max);
		return result;

	}

	

}




#endif