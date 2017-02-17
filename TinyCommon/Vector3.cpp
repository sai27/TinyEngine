// *********************************************************************
// Name: Vector3.cpp
// Date: 2017/02/17 03:27:32
// Author: YuJingbo
// Description:
// *********************************************************************

#include "stdafx.h"
#include "Vector3.h"

__TE_SPACE_BEGIN__

Vector3::Vector3()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

Vector3::Vector3(const float x, const float y, const float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

Vector3::~Vector3()
{
}

void Vector3::Normalize()
{
	float len = Length();
	x = x / len;
	y = y / len;
	z = z / len;
}

float Vector3::Length() const
{
	float len = sqrt(x * x + y * y + z * z);
	return len;
}

float Vector3::LengthSq() const
{
	float len = x * x + y * y + z * z;
	return len;
}

float Vector3::Dot(const Vector3& v) const
{
	float f = this->x * v.x + this->y * v.y + this->z * v.z;
	return f;
}

Vector3 Vector3::Cross(const Vector3& v) const
{
	Vector3 vec;
	vec.x = this->y * v.z - this->z * v.y;
	vec.y = this->z * v.x - this->x * v.z;
	vec.z = this->x * v.y - this->y * v.x;
	return vec;
}

__TE_SPACE_END__