#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <exception>
#include <ctime>
#include <cstdlib>

namespace Math
{

	const float	EPSILON = 0.00001f;  ///Used for error checking
	const float	PI = 3.1415926535897932384626433832795f;
	const float TWO_PI = PI * 2.0f;
	const float HALF_PI = PI / 2.0f;
	const float QUARTER_PI = PI / 4.0f;

	inline float FAbs(float value)
	{
		return (value < 0) ? -value : value;
	}

	inline float DegreeToRadian(float value)
	{
		return value * PI / 180.0f;
	}
	
	inline float RadianToDegree(float value)
	{
		return value * 180.0f / PI;
	}

	template<typename T>
	T Wrap(T val, T minVal, T maxVal)
	{
		if (val < minVal)
		{
			return maxVal;
		}
		else if (val > maxVal)
		{
			return minVal;
		}

		return val;
	}
	
	template<typename T>
	T Clamp(T val, T minVal, T maxVal)
	{
		if (val < minVal)
		{
			return minVal;
		}
		else if (val > maxVal)
		{
			return maxVal;
		}

		return val;
	}
	
	template<typename T>
	T Min(T x, T y)
	{
		return (x < y) ? x : y;
	}
	
	template<typename T>
	T Max(T x, T y)
	{
		return (x > y) ? x : y;
	}
	
	template<typename T>
	T Square(T x)
	{
		return x * x;
	}
	
	inline void InitRNG(void)
	{
		srand(static_cast<unsigned> (time(0)));
	}//end of InitRNG function


	inline unsigned RandInt(void)
	{
		return rand();
	}//end of RandInt function

	inline int RandIntMinMax(int min, int max)
	{
		int num = rand() % (max - min + 1);
		return (num + min);
	}//end of RandIntMinMax function

	
	inline float RandFloat(void)
	{
		return rand() / static_cast <float> (RAND_MAX);
	}//end of RandFloat function

	
	inline float RandFloatMinMax(float min, float max)
	{
		float num = (max - min) * RandFloat();
		return (num + min);
	}//end of RandFloatMinMax function

}//end namespace Math

class DivideByZero : public std::exception
{
public:
	const char* what() { return "Divide By Zero"; }
};

#endif
