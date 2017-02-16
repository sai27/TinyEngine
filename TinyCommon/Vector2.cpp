// *********************************************************************
// Name: Vector2.cpp
// Date: 2017/02/17 03:27:24
// Author: YuJingbo
// Description:
// *********************************************************************

#include "stdafx.h"
#include "Vector2.h"

__TE_SPACE_BEGIN__

Vector2::Vector2()
{
	ZeroMemory(raw, sizeof(raw));
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

float Vector2::Length()
{
	float len = sqrt(x * x + y * y);
	return len;
}

float Vector2::LengthSq()
{
	float len = x * x + y * y;
	return len;
}

void Vector2::Normalize()
{
	float len = Length();
	x = x / len;
	y = y / len;
}

__TE_SPACE_END__


