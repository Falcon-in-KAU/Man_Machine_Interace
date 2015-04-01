#include "stdafx.h"
//#include "HUD.h"



GLvoid MMI_OPENGL_WINDOW::ResizeGL(GLsizei w, GLsizei h)
{
	if (!h)	// devide by 0 방지
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// projection을 Perspective로 설정 : Window의 aspect ratio 를 계산한다.
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);

	// projection을 ortho로 설정
	//gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// GL 초기화 부분
GLint MMI_OPENGL_WINDOW::InitGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	glClearDepth(1.0f);						

	return TRUE;
}


int MMI_OPENGL_WINDOW::DrawGL()//DATA_POSITION *Position,DATA_ATTITUDES *Attitudes, DATA_CTRL *Control,DATA_SPEED *Speed, DATA_MODE *Mode, DATA_EQUIP *Equip, DATA_STATUS *Status)
{
	//printf("%d\r\n",Position.Lat);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glScalef(0.35,0.35,0.35);
	glTranslatef(0,0,0);
	glPushMatrix();
	
	
	glPopMatrix();
	return 0;
}

LRESULT CALLBACK MMI_OPENGL_WINDOW::OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, void *callbackData)
{
	MMI_OPENGL_WINDOW *OPENGL_WINDOW_CALLBACK = (MMI_OPENGL_WINDOW *)callbackData;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	MMI_OPENGL_WINDOW Display;
	switch (message)
	{
		// cloud add {
	case WM_CREATE:
		SetTimer(hWnd, OPENGL_TIMER, OPENGL_LOOP_TIME, NULL);
		SendMessage(hWnd,WM_TIMER,OPENGL_TIMER,0);
		printf("Opengl Window Activated\r\n");
		break;
		
	case WM_ACTIVATE:
	/*	if (!HIWORD(wParam))
			active = TRUE;
		else
			active = FALSE;
		break;*/
		break;
	case WM_SIZE:
		//Display.ResizeGL(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYUP:
	//	keys[wParam] = FALSE;
		break;
	case WM_TIMER:

		switch(wParam)
		{
			case OPENGL_TIMER:

		
			break;			
		}
	case WM_KEYDOWN:
	//	keys[wParam] = TRUE;
		break;
		// cloud add }
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 메뉴의 선택 영역을 구문 분석합니다.
		
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 그리기 코드를 추가합니다.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hWnd, OPENGL_TIMER);
		//DISPLAY.KillGLWindow();
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

BOOL MMI_OPENGL_WINDOW::CreateGLWinodow(char *title, int w, int h, HWND Parent_hWnd)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values

	WindowRect.left  = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)w;			// Set Right Value To Requested Width
	WindowRect.top   = (long)0;			// Set Top Value To 0
	WindowRect.bottom= (long)h;			// Set Bottom Value To Requested Height
	
	OPENGL_hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC)MMI_OPENGL_WINDOW::OPENGL_WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= OPENGL_hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE |WS_EX_DLGMODALFRAME;			// Window Extended Style
	dwStyle = WS_CHILDWINDOW;							// Windows Style

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
	
	if (!(OPENGL_hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								w,	// Calculate Window Width
								h,	// Calculate Window Height
								Parent_hWnd,								// No Parent Window
								NULL,								// No Menu
								OPENGL_hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		16,											// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	if (!(OPENGL_hDC=GetDC(OPENGL_hWnd)))							// Did We Get A Device Context?
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(OPENGL_hDC,&pfd)))	
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(OPENGL_hDC,PixelFormat,&pfd))		//
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(OPENGL_hRC=wglCreateContext(OPENGL_hDC)))				//
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(OPENGL_hDC,OPENGL_hRC))					// Try To Activate The Rendering Context
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(OPENGL_hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(OPENGL_hWnd);						// Slightly Higher Priority
	SetFocus(OPENGL_hWnd);									// Sets Keyboard Focus To The Window
	ResizeGL(w,h);
	//InitGL();
	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		//KillGLWindow();								// Reset The Display
		printf("Initialization Failed\r\n");
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	return true;
}