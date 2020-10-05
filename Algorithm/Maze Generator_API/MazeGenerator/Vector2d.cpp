#include "StdAfx.h"
#include "Vector2d.h"
#include <fstream>
#include "Util.h"

std::ostream& operator<<(std::ostream& os, const Vector2D& rhs)
{
//	os << " " << rhs.x << " " << rhs.y;
	os << "Vector( "<< rhs.x <<" , "<< rhs.y <<" )";
	return os;
}
  
std::ifstream& operator>>(std::ifstream& is, Vector2D& lhs)
{
	is >> lhs.x >> lhs.y;
	return is;
}


Vector2D operator*(const Vector2D& lhs, float rhs)
{
	Vector2D result(lhs);
	result *= rhs;
	return result;
}

Vector2D operator*(float lhs,  const Vector2D& rhs)
{
	Vector2D result(rhs);
	result *= lhs;
	return result;
}

Vector2D operator/(const Vector2D& lhs, float rhs)
{
	Vector2D result(lhs);
	result /= rhs;
	return result;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
{
	Vector2D result(lhs);
	result += rhs;
	return result;
}

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
{
	Vector2D result(lhs);
	result -= rhs;
	return result;
}

float Vec2DDistance(const Vector2D& v1, const Vector2D& v2)
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	return sqrt( dx*dx + dy*dy );
}

Vector2D Vec2DNormalize(const Vector2D &v)
{
	Vector2D vec = v;
	double vector_length = vec.Length();

	if (vector_length > std::numeric_limits<double>::epsilon())
	{
		vec.x /= vector_length;
		vec.y /= vector_length;
	}
  return vec;
}

float Vec2DLength(const Vector2D& v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

float Vec2DLengthSq(const Vector2D& v)
{
	 return (v.x*v.x + v.y*v.y);
}

Vector2D POINTStoVector(const POINTS& p)
{
	 return Vector2D(p.x, p.y);
}

Vector2D POINTtoVector(const POINT& p)
{
	 return Vector2D((float)p.x, (float)p.y);
}

POINTS VectorToPOINTS(const Vector2D& v)
{
	POINTS p;
	p.x = (short)v.x;
	p.y = (short)v.y;

	return p;
}

POINT VectorToPOINT(const Vector2D& v)
{
	POINT p;
	p.x = (long)v.x;
	p.y = (long)v.y;

	return p;
}

const Vector2D& Vector2D::operator*=(const float& rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

const Vector2D& Vector2D::operator/=(const float& rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

const Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

const Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool Vector2D::operator==(const Vector2D& rhs)const
{
	return (isEqual(x, rhs.x) && isEqual(y, rhs.y));
}

bool Vector2D::operator!=(const Vector2D& rhs)const
{
	return (x != rhs.x) || (y != rhs.y);
}

float Vector2D::Dot(const Vector2D& v2)const
{
	return x * v2.x + y * v2.y;
}

enum {clockwise, anticlockwise};
int Vector2D::Sign(const Vector2D& v2)const
{
	if( y * v2.x > x * v2.y ) return anticlockwise;
	else						 return clockwise;
}

float Vector2D::Distance(const Vector2D& v2)const
{
	float dx = v2.x - x;
	float dy = v2.y - y;
	return sqrt( dx*dx + dy*dy );
}

void Vector2D::Normalize()
{
	float vector_length = this->Length();
	if( vector_length > std::numeric_limits<float>::epsilon() )
	{
		this->x /= vector_length;
		this->y /= vector_length;
	}
}
