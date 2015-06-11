#include "stdafx.h"

MMI_GE_CONTROL::MMI_GE_CONTROL()
{

}
MMI_GE_CONTROL::~MMI_GE_CONTROL()
{

}

extern MMI_GE_WINDOW MMI_GE_Window;
LRESULT CALLBACK MMI_GE_CONTROL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC GE_CONTROL_Proc;
	PAINTSTRUCT GE_CONTROL_ps_Proc;
	RECT rc;

	switch(message)
	{
		case WM_CREATE:
			SET_HOME_POSITION_hWnd = CreateWindow("button","Set Home",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0,0,80,25,hWnd,(HMENU)SET_HOME_POSITION, SET_HOME_POSITION_hInstance,NULL);
			INIT_GE_hWnd = CreateWindow("button","Init GE",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			80,0,80,25,hWnd,(HMENU)INIT_GE,INIT_GE_hInstance,NULL);
			break;

		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
			case SET_HOME_POSITION:
				printf("Set Home Position\r\n");
				break;
			case INIT_GE:
				printf("Initialize KML file for Google Earth\r\n");
				MMI_KML kml;
				CString KML_Data_Link;
				KML_Data_Link = kml.Generate_NetworkLink();
				FILE *fp;
				if(NULL == (fp=fopen("C:\\Program Files (x86)\\Google\\Google Earth Pro\\KML_Network.kml","wt")))
				{
					CreateDirectory("C:\\Program Files (x86)\\Google\\Google Earth Pro",NULL);
					fp = fopen("C:\\Program Files (x86)\\Google\\Google Earth Pro\\KML_Network.kml","wt");
				}
				fprintf(fp,"%s",KML_Data_Link);
				fclose(fp);
				MMI_GE_Window.GE_Application->OpenKmlFile("KML_Network.kml",1);
				break;
			}
			break;

		case WM_PAINT:
			GE_CONTROL_Proc = BeginPaint(hWnd, &GE_CONTROL_ps_Proc);
			GetWindowRect(hWnd,&rc);
		break;
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
			break;
	}

	return DefWindowProc(hWnd,message,wParam,lParam);
}
bool MMI_GE_CONTROL::CreateGEControl(char *title,HWND Parent_hWnd)
{
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	WNDCLASS	wc;
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC)(MMI_GE_CONTROL_WndProc);					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= GE_CONTROL_hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);;									
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "GE_CONTROL_WINDOW";								// Set The Class Name
	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE |WS_EX_DLGMODALFRAME | WS_EX_TRANSPARENT;;			// Window Extended Style
	dwStyle = WS_CHILDWINDOW;							// Windows Style
	RECT		WindowRect;
	WindowRect.left  = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)700;			// Set Right Value To Requested Width
	WindowRect.top   = (long)0;			// Set Top Value To 0
	WindowRect.bottom= (long)300;
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
	
	if (!(GE_CONTROL_hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"GE_CONTROL_WINDOW",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								600, 700,								// Window Position
								600+83,	// Calculate Window Width
								30,	// Calculate Window Height
								Parent_hWnd,								// No Parent Window
								NULL,								// No Menu
								GE_CONTROL_hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}
	ShowWindow(GE_CONTROL_hWnd,SW_SHOW);
	UpdateWindow(GE_CONTROL_hWnd);
	SetForegroundWindow(GE_CONTROL_hWnd);	
	SetFocus(GE_CONTROL_hWnd);	// Sets Keyboard Focus To The Window
	return true;
}