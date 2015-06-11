#include "stdafx.h"

MMI_GE_WINDOW::MMI_GE_WINDOW():MMI_GE(),MMI_GE_CONTROL()
{
}

LRESULT CALLBACK MMI_GE_WINDOW_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd,message,wParam,lParam);
}

BOOL MMI_GE_WINDOW::CreateMapWindow(char *Title, int Width, int Height, HWND Parent_hWnd)
{
	WNDCLASS MMI_GE_WINDOW_WC;
	this->MAP_hInstance = GetModuleHandle(NULL);
	MMI_GE_WINDOW_WC.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	MMI_GE_WINDOW_WC.lpfnWndProc		= (WNDPROC)MMI_GE_WINDOW_WndProc;					// WndProc Handles Messages
	MMI_GE_WINDOW_WC.cbClsExtra		= 0;									// No Extra Window Data
	MMI_GE_WINDOW_WC.cbWndExtra		= 0;									// No Extra Window Data
	MMI_GE_WINDOW_WC.hInstance		= this->MAP_hInstance;							// Set The Instance
	MMI_GE_WINDOW_WC.hIcon			= LoadIcon(NULL, NULL);			// Load The Default Icon
	MMI_GE_WINDOW_WC.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	MMI_GE_WINDOW_WC.hbrBackground	= (HBRUSH)(COLOR_WINDOWFRAME+1);			// No Background Required For GL
	MMI_GE_WINDOW_WC.lpszMenuName		= NULL;									// We Don't Want A Menu
	MMI_GE_WINDOW_WC.lpszClassName	= "MAP_GE";			

	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE |WS_EX_DLGMODALFRAME | WS_EX_TRANSPARENT;			// Window Extended Style
	DWORD dwStyle = WS_CHILDWINDOW;							// Windows Style

	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left  = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)Width;			// Set Right Value To Requested Width
	WindowRect.top   = (long)0;			// Set Top Value To 0
	WindowRect.bottom= (long)Height;			// Set Bottom Value To Requested Height

	if(!RegisterClass(&MMI_GE_WINDOW_WC))
	{
		MessageBox(NULL,"Failed To Register Map Window Class","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
	
	if(!(MAP_hWnd = CreateWindowEx(dwExStyle,"MAP_GE",
								Title,
								dwStyle | WS_CLIPSIBLINGS |	WS_CLIPCHILDREN,
								600,0,
								Width,Height,
								Parent_hWnd,
								NULL,
								MAP_hInstance,
								NULL)))
	{
		MessageBox(NULL,"Map Window Creation Error","ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	//
	ShowWindow(this->MAP_hWnd,SW_SHOW);
	UpdateWindow(this->MAP_hWnd);
	SetForegroundWindow(this->MAP_hWnd);	
	SetFocus(this->MAP_hWnd);	// Sets Keyboard Focus To The Window
	this->CreateGEWindow("MMI_GE",Width,Height,this->MAP_hWnd);
	this->CreateGEControl("MMI_GE_CONTROL",Parent_hWnd);
	return true;
}