#pragma once
#include "stdafx.h"

class MMI_OPENGL_HUD
{
public:
	MMI_OPENGL_HUD();
public:
	void drawGunCross(float x, float y, float ScaleX, float ScaleY);
	//void drawSpeedLadder(float x, float y, float scale, int n);  // (n = only even)
protected:
	struct HUD_DATA
	{
		float Vt;
	}HUD_Data;

};