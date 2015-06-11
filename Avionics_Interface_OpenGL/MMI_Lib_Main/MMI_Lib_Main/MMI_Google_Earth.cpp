#include "stdafx.h"
//#include "Google_Earth.h"

MMI_GE::MMI_GE()
{

}

/*Private*/
HINSTANCE	GE_hInstance;



/******************************************************************************************************
*
*	Brief : Generating KML File for importing to google earth
*
*******************************************************************************************************/
CString MMI_KML::Generate_Header()
{
	CString strKML_Temp;
	CString strKML;
	
	strKML_Temp.Format("%s","<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	strKML = strKML_Temp;
	strKML_Temp.Format("%s","<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<Document>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<name>GCS</name>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<description>\n\tKML File for Ground Control System interlocking\n</description>\n");
	strKML += strKML_Temp;
	return strKML;
}

CString MMI_KML::Generate_Designed_Path()
{
	CString strKML;

	return strKML;
}

CString MMI_KML::Generate_Airplane_Traj(float *Traj_N, float *Traj_E, float *Traj_D, int sizeofarray)
{
	CString strKML_Temp;
	CString strKML;
	/*Define header of drawing trajectory*/
	//printf("%lf %lf %lf\r\n",Traj_N[10],Traj_E[10],Traj_D[10]);
	strKML_Temp.Format("%s","<Style id=\"yellowLineGreenPoly\">\n");
	strKML = strKML_Temp;
		strKML_Temp.Format("%s","\t<LineStyle>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<color>7f00ffff</color>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<width>1</width>\n");
			strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t</LineStyle>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t<PolyStyle>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<color>7400ff00</color>\n");
			strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t</PolyStyle>\n");
		strKML += strKML_Temp;
	strKML_Temp.Format("%s","</Style>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<Placemark>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<name>AbsoluteAltitudeExtrude</name>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<description>\n\tTransparent green wall with yellow outlines\n</description>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<styleUrl>\n\t#yellowLineGreenPoly\n</styleUrl>\n");
	strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t<LineString>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<extrude>1</extrude>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<tessellate>1</tessellate>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<altitudeMode>absolute</altitudeMode>\n");
			strKML += strKML_Temp;
	/*Input Coordinates*//*Longitude-Latitude-Altitude_Absolute_sea_level*/
			strKML_Temp.Format("%s","\t\t<coordinates>\n");
			strKML += strKML_Temp;
			for(int i=0;i<sizeofarray;i++)
			{
				strKML_Temp.Format("\t\t\t%f,%f,%f\n",Traj_E[i],Traj_N[i],-Traj_D[i]);
				strKML += strKML_Temp;
				//printf("%lf\r\n",Traj_E[i]);
			}
			
			/*
				strKML_Temp.Format("\t\t\t%f,%f,%f\n",126.861231,37.602658,100.0);
				strKML += strKML_Temp;
				strKML_Temp.Format("\t\t\t%f,%f,%f\n",126.865129,37.601663,100.0);
				strKML += strKML_Temp;
				strKML_Temp.Format("\t\t\t%f,%f,%f\n",126.866504,37.601960,100.0);
				strKML += strKML_Temp;
				strKML_Temp.Format("\t\t\t%f,%f,%f\n",126.866316,37.603279,100.0);
				strKML += strKML_Temp;
			*/
			strKML_Temp.Format("%s","\t\t</coordinates>\n");
			strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t</LineString>\n");
		strKML += strKML_Temp;
	strKML_Temp.Format("%s","</Placemark>\n");
	strKML += strKML_Temp;
	

	return strKML;
}


CString MMI_KML::Generate_End()
{
	CString strKML_Temp;
	CString strKML;
	//strKML = "</Document></kml>";
	strKML_Temp.Format("%s","\n</Document>");
	strKML = strKML_Temp;
	strKML_Temp.Format("%s","\n</kml>\n");
	strKML += strKML_Temp;
	return strKML;
}

CString MMI_KML::Generate_NetworkLink()
{
	CString strKML_Temp;
	CString strKML;
	strKML_Temp.Format("%s","<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	strKML = strKML_Temp;
	strKML_Temp.Format("%s","<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","<Document>\n");
	strKML += strKML_Temp;
		strKML_Temp.Format("%s","\t<NetworkLink>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<name>GCSData</name>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<Link>\n");
			strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<href>GCS1.kml</href>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshMode>onInterval</refreshMode>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshInterval>0.5</refreshInterval>\n");
				strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t</Link>\n");
			strKML +=strKML_Temp;
		strKML_Temp.Format("%s","\t</NetworkLink>\n");
		strKML += strKML_Temp;

		
		strKML_Temp.Format("%s","\t<NetworkLink>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<name>Waypoint</name>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<Link>\n");
			strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<href>Waypoint.kml</href>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshMode>onInterval</refreshMode>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshInterval>0</refreshInterval>\n");
				strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t</Link>\n");
			strKML +=strKML_Temp;
		strKML_Temp.Format("%s","\t</NetworkLink>\n");
		strKML += strKML_Temp;
		
		strKML_Temp.Format("%s","\t<NetworkLink>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<name>Bombadier</name>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t<Link>\n");
			strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<href>Bombadier.kml</href>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshMode>onInterval</refreshMode>\n");
				strKML += strKML_Temp;
				strKML_Temp.Format("%s","\t\t\t<refreshInterval>0.5</refreshInterval>\n");
				strKML += strKML_Temp;
			strKML_Temp.Format("%s","\t\t</Link>\n");
			strKML +=strKML_Temp;
		strKML_Temp.Format("%s","\t</NetworkLink>\n");
		strKML += strKML_Temp;

	strKML_Temp.Format("%s","</Document>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("%s","</kml>\n");
	strKML += strKML_Temp;
	return strKML;
}

CString MMI_KML::Generate_Aircraft(float phi, float theta, float psi, float pN, float pE, float Alt)
{
	CString strKML;
	CString strKML_Temp;
	strKML_Temp.Format("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	strKML = strKML_Temp;
	strKML_Temp.Format("<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("<Document>\r\n\r\n");
	strKML += strKML_Temp;
	//Aircraft
	strKML_Temp.Format("<Placemark>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("<Model id=\"Airplane\">\n");
	strKML += strKML_Temp;
		strKML_Temp.Format("<altitudeMode>absolute</altitudeMode>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<Location>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<longitude>%lf</longitude>\n",pE);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<latitude>%lf</latitude>\n",pN);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<altitude>%lf</altitude>\n",Alt);
			strKML += strKML_Temp;
		strKML_Temp.Format("\t</Location>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<Orientation>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<heading>%lf</heading>\n",psi);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<tilt>%lf</tilt>\n",theta);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<roll>%lf</roll>\n",phi);
			strKML += strKML_Temp;
		strKML_Temp.Format("\t</Orientation>\n");
		strKML += strKML_Temp;

		strKML_Temp.Format("\t<Link><href>4.dae</href></Link>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<ResourceMap></ResourceMap>\n");
		strKML += strKML_Temp;

	strKML_Temp.Format("</Model>\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("</Placemark>\n");
	strKML += strKML_Temp;
	/*
	strKML_Temp.Format("\t<Point>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<coordinates>\n");
			strKML += strKML_Temp;

			strKML_Temp.Format("\t\t</coordinates>\n");
			strKML += strKML_Temp;
			*/
	strKML_Temp.Format("\r\n</Document> </kml>\n");
	strKML += strKML_Temp;

	return strKML;
}

CString MMI_KML::Generate_KML_Database(float *Traj_N, float *Traj_E, float *Traj_D, int sizeofarray)
{
	CString strKML;
	
	strKML = MMI_KML::Generate_Header();
	strKML += MMI_KML::Generate_Airplane_Traj(Traj_N,Traj_E,Traj_D,sizeofarray);
	strKML += MMI_KML::Generate_End();
	//printf("%s",strKML);
	return strKML;
}
CString MMI_KML::Generate_Waypoint(double *Longitude, double *Latitude, double *Altitude, int Mission_Time, int Waypt_num)
{
	CString strKML;
	CString strKML_Temp;
	strKML_Temp.Format("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	strKML = strKML_Temp;
	strKML_Temp.Format("<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("<Document>\r\n\r\n");
	strKML += strKML_Temp;

	strKML_Temp.Format("<Style id=\"RedPoly\">\n");
	strKML += strKML_Temp;
		strKML_Temp.Format("\t<LineStyle>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<color>641400FF</color>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<width>10</width>\n");
			strKML += strKML_Temp;
			

		strKML_Temp.Format("\t</LineStyle>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<PolyStyle>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t\t<color>507800F0</color>");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t</PolyStyle>\n");
		strKML += strKML_Temp;
	strKML_Temp.Format("</Style>\n");
	strKML += strKML_Temp;

	for(int i=0;i<Waypt_num;i++)
	{
		strKML_Temp.Format("<Style id=\"Waypoint%d\">\n",i+1);
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<IconStyle><Icon><href>num%d.png</href></Icon></IconStyle>\n</Style>\n",i+1);
		strKML += strKML_Temp;
		
	}

	for(int i=0;i<Waypt_num;i++)
	{
		strKML_Temp.Format("<Placemark>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t<name></name>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("\t<description>Waypoint%d : %.6f %.6f %.1f %d</description>\n",i+1,Latitude[i],Longitude[i],Altitude[i],Mission_Time);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t<styleUrl>#Waypoint%d</styleUrl>\n",i+1);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t<Point>\n\t\t<coordinates>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t%lf,%lf,%.1f\n",Longitude[i],Latitude[i],Altitude[i]);
			strKML += strKML_Temp;
			strKML_Temp.Format("\t</coordinates>\n\t</Point>\n");
			strKML += strKML_Temp;
		strKML_Temp.Format("</Placemark>\n");
		strKML += strKML_Temp;

	}
	strKML_Temp.Format("<Placemark>\n");
	strKML += strKML_Temp;
		strKML_Temp.Format("\t<name>Trajectory Command</name>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<description>Trajectory Command</description>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<styleUrl>#RedPoly</styleUrl>\n");
		strKML += strKML_Temp;
		strKML_Temp.Format("\t<LineString>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<extrude>1</extrude>\n\t\t<tessellate>1</tessellate>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<altitudeMode>absolute</altitudeMode>\n");
			strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<coordinates>\n");
			strKML += strKML_Temp;
				for(int i=0;i<Waypt_num;i++)
				{
					strKML_Temp.Format("\t\t\t%lf,%lf,%lf\n",Longitude[i],Latitude[i],Altitude[i]);
					strKML += strKML_Temp;
				}
			strKML_Temp.Format("\t\t</coordinates>\n");
			strKML += strKML_Temp;
		strKML_Temp.Format("\t</LineString>\n");
		strKML += strKML_Temp;

	strKML_Temp.Format("</Placemark>\n");
	strKML += strKML_Temp;
	/*
	strKML_Temp.Format("\t<Point>\n");
		strKML += strKML_Temp;
			strKML_Temp.Format("\t\t<coordinates>\n");
			strKML += strKML_Temp;

			strKML_Temp.Format("\t\t</coordinates>\n");
			strKML += strKML_Temp;
			*/
	strKML_Temp.Format("\r\n</Document> </kml>\n");
	strKML += strKML_Temp;
	
	return strKML;
}

CString MMI_KML::Delete_KML_Data()
{
	CString strKML;
	CString strKML_Temp;
	strKML_Temp.Format("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	strKML = strKML_Temp;
	strKML_Temp.Format("<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("<Document>\r\n\r\n");
	strKML += strKML_Temp;
	strKML_Temp.Format("\r\n</Document> </kml>\n");
	strKML += strKML_Temp;
	
	return strKML;
}





LRESULT CALLBACK GE_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch(message)
	{
		case WM_CREATE:
		{
			//SetTimer(hWnd,1,1000,NULL);
			return 0;
		}

		case WM_KEYDOWN:
		{
			case VK_RETURN:
			{
				MessageBox(hWnd,"Hello","Hello",NULL);
				return 0;
			}
		}
		
		default :
			return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
}

BOOL MMI_GE::CreateGEWindow(char* title, int w, int h, HWND Parent_hWnd)
{
	//PK::KillProcess("googleearth.exe");
	CoInitialize(NULL);
	{
		HRESULT hr;
//		PK::KillProcess("googleearth.exe");
		hr = CoCreateInstance(    EARTHLib::CLSID_ApplicationGE,
								NULL,
								CLSCTX_LOCAL_SERVER,
								EARTHLib::IID_IApplicationGE,
								reinterpret_cast<void**>(&GE_Application) );
								
		
		/*
		DWORD		dwExStyle;				// Window Extended Style
		DWORD		dwStyle;				// Window Style
		WNDCLASS	wc;						// Windows Class Structure

		GE_hInstance = GetModuleHandle(NULL);
		wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
		wc.lpfnWndProc		= (WNDPROC) GE_WndProc;					// WndProc Handles Messages
		wc.cbClsExtra		= 0;									// No Extra Window Data
		wc.cbWndExtra		= 0;									// No Extra Window Data
		wc.hInstance		= GE_hInstance;							// Set The Instance
		wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
		wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
		wc.hbrBackground	= NULL;									// No Background Required For GL
		wc.lpszMenuName		= NULL;									// We Don't Want A Menu
		wc.lpszClassName	= "GoogleEarth";								// Set The Class Name


		dwExStyle =WS_EX_DLGMODALFRAME| WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
		RegisterClass(&wc);


		GE_hWnd = CreateWindowEx(	dwExStyle,							// Extended Style For The Window
									"Google Earth",							// Class Name
									title,								// Window Title
									dwStyle |							// Defined Window Style
									WS_CLIPSIBLINGS |					// Required Window Style
									WS_CLIPCHILDREN,					// Required Window Style
									w, 0,								// Window Position
									w,	// Calculate Window Width
									h,	// Calculate Window Height
									Parent_hWnd,								// No Parent Window
									NULL,								// No Menu
									GE_hInstance,							// Instance
									NULL);							// Dont Pass Anything To WM_CREATE

		*/
		/*
		WNDCLASS	GE_wc;						// Windows Class Structure

		GE_hInstance = GetModuleHandle(NULL);
		GE_wc.style			= CS_OWNDC;	// Redraw On Size, And Own DC For Window.
		GE_wc.lpfnWndProc		= (WNDPROC) GE_WndProc;					// WndProc Handles Messages
		GE_wc.cbClsExtra		= 0;									// No Extra Window Data
		GE_wc.cbWndExtra		= 0;									// No Extra Window Data
		GE_wc.hInstance		= (HINSTANCE)hr;							// Set The Instance
		GE_wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
		GE_wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
		GE_wc.hbrBackground	= NULL;									// No Background Required For GL
		GE_wc.lpszMenuName		= NULL;									// We Don't Want A Menu
		GE_wc.lpszClassName	= "GoogleEarth";								// Set The Class Name

		RegisterClass(&GE_wc);
		*/

		//if(GE_Application->IsInitialized()!=S_OK)
	//	{
			
	//	}
		if(GE_Application->IsOnline()==S_OK)
		{
		
		}
		GE_MainhWnd = GE_Application->GetMainHwnd();
		GE_Render = GE_Application->GetRenderHwnd();
		
		const int WM_QT_PAINT = 0xC2DC;
	
		Sleep(100);
		//ShowWindowAsync((HWND)GE_MainhWnd,SW_SHOW);
		SetParent((HWND)GE_Render,Parent_hWnd);
		Sleep(200);
		SendMessage((HWND)GE_MainhWnd, WM_SYSCOMMAND, WM_PAINT, 0);
		Sleep(200);
		PostMessage((HWND)GE_MainhWnd, WM_PAINT, 0, 0);
		//::SetWindowPos((HWND)GE_Application->GetRenderHwnd(), HWND_TOP, 0, 0,710, 680, SWP_FRAMECHANGED);
		Sleep(200);
		SetWindowPos((HWND)GE_MainhWnd, HWND_TOP, 0, 0,w+10, h+55, SWP_FRAMECHANGED);
		Sleep(200);
		SendMessage((HWND)GE_Render, WM_SYSCOMMAND, WM_SIZE, 0);
		Sleep(200);
		::ShowWindow((HWND)GE_MainhWnd,SW_HIDE);
		

		//EARTHLib::IApplicationGE* GE_Application;
	//EARTHLib::ICameraInfoGE* GE_Camera;
	//EARTHLib::ApplicationGE* GE_App;
	//EARTHLib::PointOnTerrainGE* GE_Point;
	//EARTHLib::IPointOnTerrainGEPtr GE_Coord;
		
		//::ShowWindow((HWND)GE_Render,SW_SHOW);
		//SetWindowPos((HWND)GE_Render, HWND_TOP, 0, 0,w, h, SWP_FRAMECHANGED);
		//SetWindowPos((HWND)GE_Render, HWND_BOTTOM, 0, 0,w, h, SWP_FRAMECHANGED);
		//SendMessage((HWND)GE_Render,WM_TIMER,0,0);
		//SetForegroundWindow(Parent_hWnd);						// Slightly Higher Priority
		//SetFocus(Parent_hWnd);



		//GE_Plugin_hInst = LoadLibrary("Interop.GEPlugin.dll");
		
	//	GE_Plugin_RC = ::FindResourceA(GE_Plugin_hWnd,resourceID,"Plugin.html");
	}
	
	

	//GE_Application->SetCameraParams(-112.2550785337791,36.07954952145647,1000.0,EARTHLib::AbsoluteAltitudeGE,100,0,0,5);
	
	//PK::KillProcess("googleearth.exe *32");
	/*char *KML_File = "C:\Users\s_vettel_desk\Desktop\¹Ú»óÇõ±³¼ö´Ô\GCS_DEV\API_GCS\GCS\userpalette.kml";
	

	GE_Application->SetCameraParams(37.60413611,126.86531667,1000,EARTHLib::AbsoluteAltitudeGE,100,0,0,5);
	GE_Application->OpenKmlFile((LPCTSTR)KML_File,1);*/
	//Process process;
	//PK::KillProcess("googleearth.exe");
	//for(int i=0;i<100;i++)
	//{ 
	//	process.GetProcesses();
	//	if(process.ProcessName->StartsWith("googleearth"))
	//	{
			//PK::KillProcess("googleearth.exe");
			//process.Kill();
	//	}
	//}
	
	//GE_Application->GetLayersDatabases();
	//CoUninitialize();
	
	//GE_Application->Release();
	/*::ShowWindowAsync((HWND)GE_Render,0);
	::SetParent((HWND)GE_Render,Parent_hWnd);

	

	::SendMessage((HWND)GE_Application->GetRenderHwnd(), WM_SYSCOMMAND, WM_PAINT, 0);
	::PostMessage((HWND)GE_Application->GetRenderHwnd(), WM_QT_PAINT, 0, 0);
	::SetWindowPos((HWND)GE_Application->GetRenderHwnd(), HWND_TOP, 0, 200,640, 480, SWP_FRAMECHANGED);
	::SendMessage((HWND)GE_Application->GetRenderHwnd(), WM_SYSCOMMAND, WM_SIZE, 0);*/
	//::SetWindowPos((HWND)GE_Render,NULL,w,0,NULL,NULL,SWP_SHOWWINDOW);
	/*DWORD		dwExStyle;				// Window Extended Style

	/*
	CoInitialize(NULL);
	HRESULT hr;
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	
	
	hr = CoCreateInstance(    EARTHLib::CLSID_ApplicationGE,
                            NULL,
                            CLSCTX_LOCAL_SERVER,
                            EARTHLib::IID_IApplicationGE,
                            (void**) &GE_Application );
	
	CoCreateInstance(
	CoCreateInstance(    EARTHLib::CLSID_CameraInfoGE,
                            NULL,
                            CLSCTX_LOCAL_SERVER,
                            EARTHLib::IID_ICameraInfoGE,
                            (void**) &GE_Camera );

	GE_Camera->PutFocusPointLatitude(57.60413611);
	GE_Camera->PutFocusPointLongitude(10.86531667);
	GE_Camera->PutFocusPointAltitude(1);
	GE_Camera->PutRange(0.1);
	
	
	
	

	//GE_MainhWnd = GE_Application->GetMainHwnd();
	GE_MainhWnd = GE_Application->GetMainHwnd();
	GE_Render = GE_Application->GetRenderHwnd();
	
	GE_hWnd = CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"Google Earth",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								w, 0,								// Window Position
								w,	// Calculate Window Width
								h,	// Calculate Window Height
								Parent_hWnd,								// No Parent Window
								NULL,								// No Menu
								(HINSTANCE)hr,							// Instance
								NULL);							// Dont Pass Anything To WM_CREATE
	
	
	::SetParent((HWND)GE_MainhWnd,Parent_hWnd);
	::SetWindowPos((HWND)GE_MainhWnd,NULL,w,0,w,h,SWP_SHOWWINDOW);
	::ShowWindow((HWND)GE_MainhWnd,SW_SHOW);
	//::ShowWindowAsync((HWND)GE_Render,SW_SHOW);

						// Show The Window
//	SetForegroundWindow(GE_hWnd);						// Slightly Higher Priority
//	SetFocus(GE_hWnd);
	//ShowWindow((HWND)GE_Render,SW_SHOW);
	*/
	/*
	KML kml;
	CString KML_Data;
	KML_Data = kml.Generate_KML_Database();
	FILE *fp;
	fp = fopen("C:\Program Files (x86)\Google\Google Earth Pro\GCS.kml","w");
	fprintf(fp,"%s",KML_Data);
	fclose(fp);
	printf("%s",KML_Data);
	
	GE_Application->OpenKmlFile("GCS.kml",1);*/
	//BSTR bstr_KML_Data = KML_Data.AllocSysString();

	//printf("*************BSTR************\n%s",bstr_KML_Data);
	//GE_Application->LoadKmlData((BSTR *)&bstr_KML_Data);
	//GE_Application->SetCameraParams(-112.2550785337791,36.07954952145647,1000.0,EARTHLib::AbsoluteAltitudeGE,100,0,0,5);
	//SysFreeString(bstr_KML_Data);
	//
	return true;
}

