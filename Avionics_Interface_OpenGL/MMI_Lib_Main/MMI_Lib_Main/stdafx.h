// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
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
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
