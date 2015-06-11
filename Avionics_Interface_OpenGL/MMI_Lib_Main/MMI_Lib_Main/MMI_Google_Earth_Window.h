#pragma once
#include "stdafx.h"
#include "MMI_Google_Earth.h"
#include "MMI_Google_Earth_Control.h"
LRESULT CALLBACK MMI_GE_WINDOW_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class MMI_GE_WINDOW : public MMI_GE, public MMI_GE_CONTROL
{

public:
	MMI_GE_WINDOW();
public:
	HDC			MAP_hDC;
	HWND		MAP_hWnd;
	HINSTANCE	MAP_hInstance;
public:
	BOOL CreateMapWindow(char *Title, int Width, int Height, HWND Parent_hWnd);
};