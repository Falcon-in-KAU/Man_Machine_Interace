#pragma once
#include "stdafx.h"
//LRESULT CALLBACK MMI_OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#include "MMI_Opengl_HUD.h"
#define OPENGL_TIMER 33
#define OPENGL_LOOP_TIME	10
class MMI_OPENGL_WINDOW : public MMI_OPENGL_HUD
{
public:
	MMI_OPENGL_WINDOW();
public:
	HDC			OPENGL_hDC;
	HGLRC		OPENGL_hRC;
	HWND		OPENGL_hWnd;
	HINSTANCE	OPENGL_hInstance;
	LPARAM		OPENGL_CALLBACK_LPARAM;
private :
	static LRESULT CALLBACK OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, void *Callback);
	static MMI_OPENGL_WINDOW *_This;
	
public:
	GLvoid ResizeGL(GLsizei w, GLsizei h);
	GLint InitGL(GLvoid);
	int DrawGL();//DATA_POSITION *Position,DATA_ATTITUDES *Attitudes, DATA_CTRL *Control,DATA_SPEED *Speed, DATA_MODE *Mode, DATA_EQUIP *Equip, DATA_STATUS *Status);
public:
	void Update();
	BOOL CreateGLWinodow(char *Title, int Width, int Height, HWND Parent_hWnd);

private:
	double GUI_Test;

};