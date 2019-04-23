#ifndef MATH_TRIGONOMETRY_CONVERSIONS_H
#define MATH_TRIGONOMETRY_CONVERSIONS_H

namespace math
{
	const float PI = 3.14159265359f;
	const float TAU = 6.28318530717f;

	inline float radians(float degrees)
	{
		return degrees / 180.0f * PI;
		
	}
	inline double radians(double degrees)
	{
		return degrees / 180.0 * PI;
	}

	inline float Rad2Deg(float radians)
	{
		return radians / PI * 180.0f;
	}
	inline double Rad2Deg(double radians)
	{
		return radians / PI * 180.0;
	}







}

#endif