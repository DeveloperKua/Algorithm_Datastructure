#pragma once
#include <iostream>
#include <math.h>
#include <assert.h>

const float   PI = 3.14159f;
const float   TwoPI = PI * 2.0f;
const float   HalfPI = PI / 2.0f;
const float   QuarterPI = PI / 4.0f;

const int MaxInt = (std::numeric_limits<int>::max)();
const int MinInt = (std::numeric_limits<int>::min)();
const float MaxFloat = (std::numeric_limits<float>::max)();
const float MinFloat = (std::numeric_limits<float>::min)();

inline bool isEqual(float a, float b)
{
	if (fabs(a - b) < 1E-12)
		return true;
	return false;
}

//템플릿으로 MaxOf작성 
template <class T>
inline T MaxOf(const T& a, const T& b)
{
	return ((a > b) ? a : b);
}

template <class T>
inline T MinOf(const T& a, const T& b)
{
	return ((a < b) ? a : b);
}

inline int   RandInt(int x, int y)
{
	assert(y >= x && "<RandInt>: y is less than x");
	return rand() % (y - x + 1) + x;
}

inline double RandFloat()      { return ((rand()) / (RAND_MAX + 1.0)); }

inline double RandInRange(double x, double y)
{
	return x + RandFloat()*(y - x);
}

inline bool   RandBool()
{
	if (RandFloat() > 0.5) return true;

	else return false;
}

inline double RandomClamped()    { return RandFloat() - RandFloat(); }