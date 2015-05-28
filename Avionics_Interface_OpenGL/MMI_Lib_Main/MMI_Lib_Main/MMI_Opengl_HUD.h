#pragma once
#include "stdafx.h"

class MMI_OPENGL_HUD
{
public:
	MMI_OPENGL_HUD();
protected:
	void drawGunCross(float x, float y, float ScaleX, float ScaleY);
	void drawFlightPathMarker(float x, float y, float ScaleX, float ScaleY);
	void drawGround(float x, float y, float ScaleX, float ScaleY);
	void drawPitchLadder(float x, float y, float ScaleX, float ScaleY);
	void drawSpeedLadder(float x, float y, float ScaleX, float ScaleY);
	void drawAltLadder(float x, float y, float ScaleX, float ScaleY);
	void drawRollIndicator(float x, float y, float ScaleX, float ScaleY);
	void drawHeadingMarker(float x, float y, float ScaleX, float ScaleY);

	void drawGroundSpeed(float x, float y, float ScaleX, float ScaleY);
	void drawVerticalSpd(float x, float y, float ScaleX, float ScaleY);
	void drawSpeedCmd(float x, float y, float ScaleX, float ScaleY);
	void drawAltCmd(float x, float y, float ScaleX, float ScaleY);

	void drawLLA(float x, float y, float ScaleX, float ScaleY);
	void drawUTC(float x, float y, float ScaleX, float ScaleY);
	void drawRPMIndicator(float x, float y, float ScaleX, float ScaleY);
	void drawPowerIndicator(float x, float y, float ScaleX, float ScaleY);
	void drawHeading(float x, float y, float ScaleX, float ScaleY);
	void drawGCSIndicator(float x, float y, float ScaleX, float ScaleY);
	void drawWindIndicator(float x, float y, float ScaleX, float ScaleY);
	void drawGPSStatus(float x, float y, float ScaleX, float ScaleY);
	void drawFCCStatus(float x, float y, float ScaleX, float ScaleY);
	//void drawSpeedLadder(float x, float y, float scale, int n);  // (n = only even)
protected:
	struct HUD_DATA
	{
		float alpha;
		float beta;
		float Vt;

		float phi;
		float theta;
		float psi;
		float Heading;

		float Ax;
		float Ay;
		float Az;

		float P;
		float Q;
		float R;

		float TAS;
		float GS;
		float TAS_cmd;

		float Longitude;
		float Latitude;
		float Altitude;
		float Alt_cmd;

		float Voltage;
		float Ampere_Batt;
		float Ampere_ESC;
		float Ampere_Solar;
		float RPM;
		float Power_cmd;

		float GCS_Bearing;
		float GCS_Deviation;
		float Wind;
		float Wind_Bearing;
		
		unsigned char GPS_Status;
		unsigned char FCC_Status;
	}HUD_Data;

};