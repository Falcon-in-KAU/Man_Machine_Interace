#pragma once
//#using <mscorlib.dll>
#include <atlcomcli.h>//for dll loading
#include <Tlhelp32.h>
#include <comutil.h>
#include "stdafx.h"

/*Google Earth*/
//#import "C:\Program Files (x86)\Google\Google Earth\client\googleearth.exe" named_guids

/*Google Earth Pro*/
#import "C:\Program Files (x86)\Google\Google Earth Pro\googleearth.exe" named_guids	

using namespace EARTHLib;

#define GE_BUTTON 101
#define LAT_REF  37.60413611
#define LON_REF 126.86531667

LRESULT CALLBACK GE_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


/************************************************************************
	Brief : Google Earth Class
*************************************************************************/

class MMI_GE
{
public:
	MMI_GE();
public:
	HDC			GE_hDC;		// Device Context Handle
	HGLRC		GE_hRC;		// GL Rendering Context Handle
	HWND		GE_hWnd;
	
public:
	
	EARTHLib::IApplicationGE* GE_Application;
	EARTHLib::ICameraInfoGE* GE_Camera;
	EARTHLib::ApplicationGE* GE_App;
	EARTHLib::PointOnTerrainGE* GE_Point;
	EARTHLib::IPointOnTerrainGEPtr GE_Coord;
	OLE_HANDLE GE_MainhWnd;
	OLE_HANDLE GE_Render;
	

public:
	BOOL CreateGEWindow(char* title, int w, int h, HWND Parent_hWnd);

public:
	HINSTANCE GE_Plugin_hInst;
};

/*************************************************************************
	Brief : KML Generator Class
**************************************************************************/
class MMI_KML
{
public:
	//KML(){};
	//~KML(){};

	CString Generate_Header();
	CString Generate_Designed_Path();
	CString Generate_Airplane_Traj(float *Traj_N, float *Traj_E, float *Traj_D, int sizeofarray);
	CString Generate_End();
	CString Generate_NetworkLink();
	CString Generate_KML_Database(float *Traj_N, float *Traj_E, float *Traj_D, int sizeofarray);
	CString Generate_Waypoint(double *Longitude, double *Latitude, double *Altitude, int Mission_Time, int Waypt_num);
	CString Generate_Aircraft(float phi, float theta, float psi, float pN, float pE, float Alt);
	CString Delete_KML_Data();
};