// *********************************************************************
// Name: Vector3.h
// Date: 2017/02/17 03:27:35
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __VECTOR3_H__
#define __VECTOR3_H__

__TE_SPACE_BEGIN__

class Vector3
{
public:
	TE_EXPORT Vector3();
	TE_EXPORT Vector3(const float x, const float y, const float z);
	TE_EXPORT Vector3(const Vector3& v);
	TE_EXPORT ~Vector3();

public:
	TE_EXPORT void	Normalize();

	TE_EXPORT float	Length() const;
	TE_EXPORT float	LengthSq() const;
	TE_EXPORT float Dot(const Vector3& v) const;
	TE_EXPORT Vector3 Cross(const Vector3& v) const;
public:
	TE_EXPORT inline Vector3& operator =(const Vector3 v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}

	TE_EXPORT inline Vector3 operator -() const
	{
		Vector3 vec(-x, -y, -z);
		return vec;
	}

	TE_EXPORT inline Vector3 operator +(const Vector3& v) const
	{
		Vector3 vec(x + v.x, y + v.y, z + v.z);
		return vec;
	}

	TE_EXPORT inline Vector3 operator -(const Vector3& v) const
	{
		Vector3 vec(x - v.x, y - v.y, z - v.z);
		return vec;
	}

	TE_EXPORT inline Vector3 operator *(const float f) const
	{
		Vector3 vec(x * f, y * f, z * f);
		return vec;
	}

	TE_EXPORT inline Vector3 operator /(const float f) const
	{
		Vector3 vec(x / f, y / f, z / f);
		return vec;
	}

	TE_EXPORT inline Vector3& operator +=(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}

	TE_EXPORT inline Vector3& operator -=(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return *this;
	}

	TE_EXPORT inline Vector3& operator *=(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
		return *this;
	}

	TE_EXPORT inline Vector3& operator /=(const float f)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
		return *this;
	}

public:
	union
	{
		struct { float x; float y; float z; };
		float raw[3];
	};
};

TE_EXPORT inline Vector3 operator *(const float f, const Vector3& v)
{
	Vector3 vec(v.x * f, v.y * f, v.z * f);
	return vec;
}

__TE_SPACE_END__

#endif
