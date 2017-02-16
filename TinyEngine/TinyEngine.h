// *********************************************************************
// Name: TinyEngine.h
// Date: 2017/02/17 03:29:55
// Author: YuJingbo
// Description:
// *********************************************************************

#ifndef __TINYENGINE_H__
#define __TINYENGINE_H__

__TE_SPACE_BEGIN__

class TinyEngine
{
public:
	TinyEngine();
	~TinyEngine();

public:
	bool Initilize(HWND hWnd);
	void Destroy();

	void Update(float _dt);
	void Render();

private:
	HWND                    m_hWnd;
	D3D_DRIVER_TYPE         m_driverType;
	D3D_FEATURE_LEVEL       m_featureLevel;
	ID3D11Device*           m_pd3dDevice;
	ID3D11DeviceContext*    m_pImmediateContext;
	IDXGISwapChain*         m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;
};

__TE_SPACE_END__

#endif
