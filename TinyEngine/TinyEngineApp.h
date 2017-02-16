// *********************************************************************
// Name: SoftRenderApp.h
// Date: 2017/02/12 04:12:01
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __SOFTRENDERAPP_H__
#define __SOFTRENDERAPP_H__

class TinyEngineApp
{
public:
	TinyEngineApp();
	~TinyEngineApp();

	bool Init(HINSTANCE hInstance);
	void Destroy();
	void Run();

	bool Update();
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	tiny::TinyEngine*	m_pTinyEngine;

};

#endif
