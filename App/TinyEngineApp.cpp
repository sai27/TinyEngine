// *********************************************************************
// Name: SoftRenderApp.h
// Date: 2017/02/12 04:12:28
// Author: YuJingbo
// Description:
// *********************************************************************

#include "stdafx.h"
#include "TinyEngineApp.h"

using namespace tiny;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		// 		switch (wmId)
		// 		{
		// 		default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		//		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

TinyEngineApp::TinyEngineApp()
{
	m_pTinyEngine = new TinyEngine();
}

TinyEngineApp::~TinyEngineApp()
{
	if (m_pTinyEngine)
	{
		delete m_pTinyEngine;
		m_pTinyEngine = nullptr;
	}
}

bool TinyEngineApp::Init(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCE(IDC_SOFTRENDERER);
	wcex.lpszClassName = L"TinyEngine Window Class";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wcex);


	m_hInstance = hInstance; // Store instance handle in our global variable

	const int createWidth = 1024;
	const int createHeight = 768;

	m_hWnd = CreateWindow(L"TinyEngine Window Class", L"TinyEngineApp", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, createWidth, createHeight, NULL, NULL, hInstance, NULL);

	RECT realRect;
	GetClientRect(m_hWnd, &realRect);

	int width = realRect.right - realRect.left;
	int height = realRect.bottom - realRect.top;
	width = createWidth * 2 - width;
	height = createHeight * 2 - height;

	MoveWindow(m_hWnd, GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2, width, height, FALSE);

	if (!m_hWnd)
	{
		return false;
	}

	// ÏÔÊ¾´°¿Ú
	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);

	// ÇÐ»»½¹µã
	SetFocus(m_hWnd);
	SetForegroundWindow(m_hWnd);

	m_pTinyEngine->Initilize(m_hWnd);

	return true;
}

void TinyEngineApp::Destroy()
{
	m_pTinyEngine->Destroy();
}

void TinyEngineApp::Run()
{
	for (;;)
	{
		MSG msg;

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_QUIT)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{

				break;
			}
		}
		else
		{

			if (!Update())
			{
				// need to clean the message loop (WM_QUIT might cause problems in the case of a restart)
				// another message loop might have WM_QUIT already so we cannot rely only on this 
				while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				break;
			}
		}
	}
}

bool TinyEngineApp::Update()
{
	m_pTinyEngine->Render();
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	TinyEngineApp app;
	if (app.Init(hInstance))
	{
		app.Run();
		app.Destroy();
	}
	return 0;
}