// *********************************************************************
// Name: defines_func.h
// Date: 2017/02/17 03:26:27
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#define SafeDelete(v)	if(v != nullptr) { delete v; v = nullptr; }
#define SafeRelease(v)	if(v != nullptr) { v->Release(); v = nullptr; }

#endif
