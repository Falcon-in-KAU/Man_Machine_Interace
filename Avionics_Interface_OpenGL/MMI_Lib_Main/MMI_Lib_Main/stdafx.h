// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <Windows.h>
#include <GL.H>
#include <GL.H>
#include <GLAUX.H>
#include <GLU.H>
#include <glut.h>
#include <math.h>

#include <atlstr.h>						//for using CString

#include "Avionics.h"
#include "MMI_Opengl_Window.h"
#include "MMI_Google_Earth_Window.h"

//#include "MMI_Opengl_HUD.h"

#define WINDOW_SIZE_X	600
#define WINDOW_SIZE_Y	700

#define R2D		57.2957795
#define D2R		0.0174532925
// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
