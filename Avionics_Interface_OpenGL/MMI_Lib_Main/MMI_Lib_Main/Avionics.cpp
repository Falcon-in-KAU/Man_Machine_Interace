#include "stdafx.h"

void Avionics_Drawing()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0, 0, 0); //Move forward 5 units x y 'z' coordinate
	glRotatef(0, 0.0f, 1.0f, 0.0f); //Rotate the camera
	glTranslatef(0, 0, 0);
	glutSwapBuffers();

}

void Avionics_Init()
{
	glEnable(GL_DEPTH_TEST);
	glColor3f(1,1,1);
	

}

void Avionics_Resize(int w, int h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void Avionics_Update(int value) 
{
	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 250 milliseconds
	glutTimerFunc(10, Avionics_Update, 0);
}