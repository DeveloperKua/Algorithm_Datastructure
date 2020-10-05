#pragma once
#include <iostream>
#include <math.h>

struct Vector2D //class
{
	float x;
	float y;

	Vector2D():x(0.0f),y(0.0f){} //디폴트 생성자
	Vector2D(float a, float b):x(a),y(b){} //인자가 있는 생성자

	//벡터 : 스칼라 연산
	const Vector2D& operator*=(const float& rhs);
	const Vector2D& operator/=(const float& rhs);

	//벡터 : 벡터 연산
	const Vector2D& operator+=(const Vector2D& rhs);
	const Vector2D& operator-=(const Vector2D& rhs);

	//비교
	bool operator==(const Vector2D& rhs)const;
	bool operator!=(const Vector2D& rhs)const;

	inline float Length()const { return sqrt( x*x + y*y );} 

	float	Dot(const Vector2D& v2)const;
	int		Sign(const Vector2D& v2)const;
	float	Distance(const Vector2D& v2)const;
	void		Normalize();
	inline  Vector2D  Perp()const { return Vector2D(-y, x); }
};

std::ostream& operator<<(std::ostream& os, const Vector2D& rhs);
std::ifstream& operator>>(std::ifstream& is, Vector2D& lhs);

Vector2D operator*(const Vector2D& lhs, float rhs);
Vector2D operator*(float lhs, const Vector2D& rhs);
Vector2D operator/(const Vector2D& lhs, float rhs);

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);

float	Vec2DDistance(const Vector2D& v1, const Vector2D& v2);
Vector2D Vec2DNormalize(const Vector2D &v);
POINT	VectorToPOINT(const Vector2D& v);
POINTS	VectorToPOINTS(const Vector2D& v);
Vector2D POINTtoVector(const POINT& p);
Vector2D POINTStoVector(const POINTS& p);
float Vec2DLengthSq(const Vector2D& v);
float Vec2DLength(const Vector2D& v);

