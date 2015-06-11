#pragma once

LRESULT CALLBACK MMI_GE_CONTROL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#define SET_HOME_POSITION	1001
#define INIT_GE				1002

static HINSTANCE SET_HOME_POSITION_hInstance;
static HINSTANCE INIT_GE_hInstance;

static HWND SET_HOME_POSITION_hWnd;
static HWND INIT_GE_hWnd;

class MMI_GE_CONTROL
{
public:
	MMI_GE_CONTROL();
	~MMI_GE_CONTROL();

public:
	bool CreateGEControl(char *title,HWND Parent_hWnd);

public:
	HWND		GE_CONTROL_hWnd;
	HINSTANCE	GE_CONTROL_hInstance;
	LPARAM		GE_CONTROL_CALLBACK_LPARAM;

	
};