#pragma once
#include <Windows.h>
#include <GL.H>
#include <GL.H>
#include <GLAUX.H>
#include <GLU.H>
#include <glut.h>
//LRESULT CALLBACK MMI_OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#define OPENGL_TIMER 33
#define OPENGL_LOOP_TIME	10
class MMI_OPENGL_WINDOW
{
public:
	HDC			OPENGL_hDC;
	HGLRC		OPENGL_hRC;
	HWND		OPENGL_hWnd;
	HINSTANCE	OPENGL_hInstance;
	LPARAM		OPENGL_CALLBACK_LPARAM;
	static LRESULT CALLBACK OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, void *CallbackData);
	//LRESULT CALLBACK OPENGL_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LPARAM OPENGL_CALLBACK_LPARAM);
public:
	GLvoid ResizeGL(GLsizei w, GLsizei h);
	GLint InitGL(GLvoid);
	int DrawGL();//DATA_POSITION *Position,DATA_ATTITUDES *Attitudes, DATA_CTRL *Control,DATA_SPEED *Speed, DATA_MODE *Mode, DATA_EQUIP *Equip, DATA_STATUS *Status);
public:
	BOOL CreateGLWinodow(char *Title, int Width, int Height, HWND Parent_hWnd);

};