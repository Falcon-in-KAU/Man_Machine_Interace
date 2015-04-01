#pragma once

#include <Windows.h>
#include <GL.H>
//#include "OpenGL\GLU.H"
#include <glut.h>

class AVIONICS
{
public:
	void Avionics_Init();
	void Avionics_Resize(int w, int h) ;
	void Avionics_Update(int value) ;
	void Avionics_Drawing();

};

