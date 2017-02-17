// *********************************************************************
// Name: Vector4.cpp
// Date: 2017/02/17 03:27:40
// Author: YuJingbo
// Description:
// *********************************************************************

#include "stdafx.h"
#include "Vector4.h"


__TE_SPACE_BEGIN__

Vector4::Vector4()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

Vector4::Vector4(const float x, const float y, const float z, const float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(const Vector4& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

Vector4::~Vector4()
{
}

float Vector4::Length()
{
	float len = sqrt(x * x + y * y + z * z + w * w);
	return len;
}

float Vector4::LengthSq()
{
	float len = x * x + y * y + z * z + w * w;
	return len;
}

void Vector4::Normalize()
{
	float len = Length();
	x = x / len;
	y = y / len;
	z = z / len;
	w = w / len;
}

Vector4& Vector4::operator=(const Vector4 v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	return *this;
}

__TE_SPACE_END__