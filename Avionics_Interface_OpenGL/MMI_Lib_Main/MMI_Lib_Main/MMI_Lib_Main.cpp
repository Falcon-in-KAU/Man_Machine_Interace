// MMI_Lib_Main.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MMI_Lib_Main.h"

#define MAX_LOADSTRING 100
#define MAIN_TIMER_ID		1


// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


HWND hWnd;
MMI_OPENGL_WINDOW MMI_OpenGL_Window;
MMI_GE_WINDOW MMI_GE_Window;
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	/************************************************
		@Brief : Define Variables for OpenGL Window
	************************************************/


	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MMI_LIB_MAIN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MMI_LIB_MAIN));
	MMI_OpenGL_Window.CreateGLWinodow("MMI_Lib",WINDOW_SIZE_X,WINDOW_SIZE_Y,hWnd);
	MMI_GE_Window.CreateMapWindow("MMI_GE",WINDOW_SIZE_X+83,WINDOW_SIZE_Y,hWnd);
	// �⺻ �޽��� �����Դϴ�.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MMI_LIB_MAIN));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MMI_LIB_MAIN);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   

   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1300, 1000, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

namespace PK
{
	void KillProcess(const char *EXEName)
	{
		HANDLE snapshot_handle = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE != snapshot_handle)
		{
			PROCESSENTRY32 pe;
			if(Process32First(snapshot_handle, &pe))
			{
				do
				{
					//TRACE("KillProcess() PID = %04u, FileName = %s\n", pe.th32ProcessID, pe.szExeFile);
					if (!_tcscmp(pe.szExeFile, (LPCTSTR)EXEName))
					{
						HANDLE process_handle = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
						if (INVALID_HANDLE_VALUE != process_handle)
						{
							//TRACE("���μ��� ����!\n");
							TerminateProcess(process_handle, 0);
							CloseHandle(process_handle);
						}
					}
				}
				while(Process32Next(snapshot_handle, &pe));
			}
			CloseHandle(snapshot_handle);
			snapshot_handle = INVALID_HANDLE_VALUE;
		} 
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd,MAIN_TIMER_ID,10,NULL);
		SendMessage(hWnd,WM_TIMER,MAIN_TIMER_ID,0);
		break;
	case WM_TIMER:
		switch(wParam)
		{
		case MAIN_TIMER_ID:
			
			if(MMI_OpenGL_Window.OPENGL_hRC = wglCreateContext(MMI_OpenGL_Window.OPENGL_hDC))
			{
				if(wglMakeCurrent(MMI_OpenGL_Window.OPENGL_hDC,MMI_OpenGL_Window.OPENGL_hRC))
				{
					MMI_OpenGL_Window.DrawGL();

					SwapBuffers(MMI_OpenGL_Window.OPENGL_hDC);
				}
			}
			wglMakeCurrent(NULL,NULL);
			::ReleaseDC(MMI_OpenGL_Window.OPENGL_hWnd,MMI_OpenGL_Window.OPENGL_hDC);
			wglDeleteContext(MMI_OpenGL_Window.OPENGL_hRC);
			break;
		}
		

		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PK::KillProcess("googleearth.exe");
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
