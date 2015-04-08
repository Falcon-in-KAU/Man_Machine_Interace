#include "stdafx.h"

MMI_OPENGL_HUD::MMI_OPENGL_HUD()
{
	memset(&this->HUD_Data,0,sizeof(&this->HUD_Data));
	this->HUD_Data.Vt = 10;
}

void MMI_OPENGL_HUD::drawGunCross(float x, float y, float ScaleX, float ScaleY)
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX, ScaleY, 1);
	glBegin(GL_LINE_STRIP);
	    glVertex3f(-1.3f,  0.0f, 0);
	    glVertex3f(-0.5f,  0.0f, 0);
	glEnd();
    glBegin(GL_LINE_STRIP);
		glVertex3f( 0.5f,  0.0f, 0);		
	    glVertex3f( 1.3f,  0.0f, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f( 0.0f,  1.3f, 0);		
	    glVertex3f( 0.0f,  0.5f, 0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f( 0.0f,  -1.3f, 0);		
	    glVertex3f( 0.0f,  -0.5f, 0);
	glEnd();

	glPopMatrix();
	
}
