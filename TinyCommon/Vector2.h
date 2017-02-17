// *********************************************************************
// Name: Vector2.h
// Date: 2017/02/17 03:27:28
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __VECTOR2_H__
#define __VECTOR2_H__

__TE_SPACE_BEGIN__

class Vector2
{
public:
	TE_EXPORT Vector2();
	TE_EXPORT Vector2(const float x, const float y);
	TE_EXPORT Vector2(const Vector2& v);
	TE_EXPORT ~Vector2();

public:
	TE_EXPORT float	Length();
	TE_EXPORT float	LengthSq();
	TE_EXPORT void	Normalize();

public:
	TE_EXPORT Vector2& operator =(const Vector2 v);

public:
	union
	{
		struct { float x; float y; };
		float raw[2];
	};
};

inline Vector2 operator +(const Vector2& v1, const Vector2& v2)
{
	Vector2 v(v1.x + v2.x, v1.y + v2.y);
	return v;
}

inline Vector2 operator -(const Vector2& v1, const Vector2& v2)
{
	Vector2 v(v1.x - v2.x, v1.y - v2.y);
	return v;
}

inline Vector2 operator *(const Vector2& v1, const float f)
{
	Vector2 v(v1.x * f, v1.y * f);
	return v;
}

inline Vector2 operator /(const Vector2& v1, const float f)
{
	Vector2 v(v1.x / f, v1.y / f);
	return v;
}

__TE_SPACE_END__

#endif
