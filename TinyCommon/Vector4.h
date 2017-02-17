// *********************************************************************
// Name: Vector4.h
// Date: 2017/02/17 03:27:46
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __VECTOR4_H__
#define __VECTOR4_H__

__TE_SPACE_BEGIN__

class Vector4
{
public:
	TE_EXPORT Vector4();
	TE_EXPORT Vector4(const float x, const float y, const float z, const float w);
	TE_EXPORT Vector4(const Vector4& v);
	TE_EXPORT ~Vector4();

public:
	TE_EXPORT float	Length();
	TE_EXPORT float	LengthSq();
	TE_EXPORT void	Normalize();

public:
	TE_EXPORT Vector4& operator =(const Vector4 v);
public:
	union
	{
		struct { float x; float y; float z; float w; };
		float raw[4];
	};
};

inline Vector4 operator +(const Vector4& v1, const Vector4& v2)
{
	Vector4 v(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
	return v;
}

inline Vector4 operator -(const Vector4& v1, const Vector4& v2)
{
	Vector4 v(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	return v;
}

inline Vector4 operator *(const Vector4& v1, const float f)
{
	Vector4 v(v1.x * f, v1.y * f, v1.z * f, v1.w * f);
	return v;
}

inline Vector4 operator /(const Vector4& v1, const float f)
{
	Vector4 v(v1.x / f, v1.y / f, v1.z / f, v1.w / f);
	return v;
}

__TE_SPACE_END__

#endif
