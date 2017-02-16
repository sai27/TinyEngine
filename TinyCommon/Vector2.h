#ifndef __VECTOR2_H__
#define __VECTOR2_H__

// *********************************************************************
// Name: Vector2.h
// Date: 2017/02/17 03:27:28
// Author: YuJingbo
// Description:
// *********************************************************************

__TE_SPACE_BEGIN__

class Vector2
{
public:
	TE_EXPORT Vector2();
	TE_EXPORT Vector2(float x, float y);
	TE_EXPORT ~Vector2();

public:
	TE_EXPORT float	Length();
	TE_EXPORT float	LengthSq();
	TE_EXPORT void	Normalize();

public:
	union
	{
		struct  
		{
			float x;
			float y;
		};
		
		float raw[2];
	};
};

__TE_SPACE_END__

#endif
