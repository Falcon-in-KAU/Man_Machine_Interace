#include "stdafx.h"

MMI_OPENGL_HUD::MMI_OPENGL_HUD()
{
	memset(&this->HUD_Data,0,sizeof(&this->HUD_Data));
}

void MMI_OPENGL_HUD::drawGunCross(float x, float y, float ScaleX, float ScaleY)
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX*2.5, ScaleY*2.5, 1);
	glColor3f(255,255,0);
	/*glBegin(GL_LINE_STRIP);
	    glVertex3f(-1.3f,  0.0f, 0);
	    glVertex3f(-1.0f,  0.0f, 0);		
	    glVertex3f(-0.5f, -0.5f, 0);		
	    glVertex3f( 0.0f,  0.0f, 0);		
	    glVertex3f( 0.5f, -0.5f, 0);		
	    glVertex3f( 1.0f,  0.0f, 0);		
	    glVertex3f( 1.3f,  0.0f, 0);
	glEnd();*/
	glBegin(GL_POLYGON);
	    glVertex3f(-3.3f,  -1.5f, 0);
	    glVertex3f(-2.0f,  -1.5f, 0);		
	    glVertex3f(0.0f, 0.0f, 0);		
	    
	glEnd();
	glBegin(GL_POLYGON);
	    glVertex3f(3.3f,  -1.5f, 0);
	    glVertex3f(2.0f,  -1.5f, 0);		
	    glVertex3f(0.0f, 0.0f, 0);		
	    
	glEnd();
	glColor3f(0,255,0);
	glPopMatrix();
	
}

void MMI_OPENGL_HUD::drawFlightPathMarker(float x, float y, float ScaleX, float ScaleY)
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	glTranslatef(this->HUD_Data.beta,this->HUD_Data.alpha,0);
	glBegin(GL_LINE_STRIP);
	
	for(int i=0;i<360;i++)
	{
		float pos_x=cos((float)i*D2R);
		float pos_y=sin((float)i*D2R);
		glVertex3f(0.3*pos_x,0.3*pos_y,0);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(1.0,0,0);
	glVertex3f(0.3,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0,0,0);
	glVertex3f(-0.3,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,0.3,0);
	glVertex3f(0,0.7,0);
	glEnd();
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawGround(float x, float y, float ScaleX, float ScaleY)
{
	glPushMatrix();
	glTranslatef(x,y,0);
	
	float Ladder_Scale_X = 0.1;
	float Ladder_Unit = 10;

	glTranslatef(Ladder_Scale_X*(this->HUD_Data.beta),0,0);
	glScalef(ScaleX,ScaleY,1);
	glRotatef(-this->HUD_Data.phi,0,0,1);
	glTranslatef(0,-this->HUD_Data.theta,0);
	
	float fWidth = 400.0;
	glBegin(GL_QUADS);
		glColor3ub(181,101,29);
		glVertex2f(fWidth,0);
		glVertex2f(-fWidth,0);
		glColor3ub(140,75,14);
		glVertex2f(-fWidth,-2);
		glVertex2f(fWidth,-2);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(140,75,14);
		glVertex2f(fWidth,-2);
		glVertex2f(-fWidth,-2);
		glColor3ub(102,51,0);
		glVertex2f(-fWidth,-5);
		glVertex2f(fWidth,-5);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(102,51,0);
		glVertex2f(fWidth,-5);
		glVertex2f(-fWidth,-5);
		glVertex2f(-fWidth,-90);
		glVertex2f(fWidth,-90);
	glEnd();

	glBegin(GL_QUADS);
		glColor3ub(169,169,255);
		glVertex2f(fWidth,0);
		glVertex2f(-fWidth,0);
		glColor3ub(83,83,197);
		glVertex2f(-fWidth,1);
		glVertex2f(fWidth,1);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(83,83,197);
		glVertex2f(fWidth,1);
		glVertex2f(-fWidth,1);
		glColor3ub(0,0,114);
		glVertex2f(-fWidth,3);
		glVertex2f(fWidth,3);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(0,0,114);
		glVertex2f(fWidth,3);
		glVertex2f(-fWidth,3);
		glColor3ub(0,0,85);
		glVertex2f(-fWidth,90);
		glVertex2f(fWidth,90);
	glEnd();

	glColor3ub(0,255,0);

	glPopMatrix();
}

void MMI_OPENGL_HUD::drawPitchLadder(float x, float y, float ScaleX, float ScaleY)
{
	char string[50];
	float Detector = 0;//this->HUD_Data.theta;
	float angle = 0;

	float cnt = Detector-36;
	
	float Ladder_Scale_X = 0.1;
	float Ladder_Unit = 10;
	glPushMatrix();
	glTranslatef(x,y,0);
	glEnable(GL_SCISSOR_TEST);
	glScissor(0,WINDOW_SIZE_Y/4*y,WINDOW_SIZE_X,WINDOW_SIZE_Y*0.6);
	glStencilFunc(GL_NEVER, 0x0, 0x0);
    glStencilOp(GL_INCR, GL_INCR, GL_INCR);
	

	glTranslatef(Ladder_Scale_X*(this->HUD_Data.beta),0,0);
	glScalef(ScaleX,ScaleY,1);
	glRotatef(-this->HUD_Data.phi,0,0,1);
	glTranslatef(0,-this->HUD_Data.theta,0);
	
	for(cnt;cnt<Detector+10;cnt=cnt+1)
	{
		
		if(cnt < Detector+0.01 && cnt > Detector-0.01)
		{
			glBegin(GL_LINE_STRIP);
			
			glVertex3f(-16*0.8,10*cnt-1,0);
			glVertex3f(-16*0.8,10*cnt,0);
			glVertex3f(0.8*-3,10*cnt,0);
			
			glEnd();
			glBegin(GL_LINE_STRIP);

			glVertex3f(16*0.8,10*cnt-1,0);
			glVertex3f(16*0.8,10*cnt,0);
			glVertex3f(0.8*3,10*cnt,0);
			glEnd();

			sprintf(string,"0");
			//glRasterPos3f(-16.5*0.85, this->HUD_Data.theta*10-1, 0);
			glRasterPos3f(-16.5*0.85, 0, 0);
			
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			
			sprintf(string,"0");
			//glRasterPos3f(16*0.85, this->HUD_Data.theta*10-1, 0);
			glRasterPos3f(16*0.85, 0, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			

		}
		
		if(cnt<Detector-0.01 && -cnt<10)
		{
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(9,0x5555);
			glBegin(GL_LINE_STRIP);

			glVertex3f(-10*0.8,10*cnt+1,0);
			glVertex3f(-10*0.8,10*cnt,0);
			glVertex3f(0.8*-3,10*cnt,0);
			glEnd();
			glBegin(GL_LINE_STRIP);

			glVertex3f(10*0.8,10*cnt+1,0);
			glVertex3f(10*0.8,10*cnt,0);
			glVertex3f(0.8*3,10*cnt,0);

			glEnd();
			glColor3f(0,191,255);
			glBegin(GL_POLYGON);
				glVertex3f(-6.3f,  -1.5f, 0);
				glVertex3f(-3.5f,  -1.5f, 0);		
				glVertex3f(0.0f, 0.0f, 0);		
	    
			glEnd();
			glBegin(GL_POLYGON);
				glVertex3f(6.3f,  -1.5f, 0);
				glVertex3f(3.5f,  -1.5f, 0);		
				glVertex3f(0.0f, 0.0f, 0);		
	    
			glEnd();
			glColor3f(0,255,0);
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12.5*0.85, cnt*10, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit);
			glRasterPos3f(-12.5*0.85, cnt*Ladder_Unit, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit);
			glRasterPos3f(10*0.85, cnt*Ladder_Unit, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			
			
			glDisable(GL_LINE_STIPPLE);
		}
		
		if(cnt>Detector+0.01 && cnt<10)
		{
			glBegin(GL_LINE_STRIP);

			glVertex3f(-10*0.8,10*cnt-1,0);
			glVertex3f(-10*0.8,10*cnt,0);
			glVertex3f(0.8*-3,10*cnt,0);
			
			glEnd();
			glBegin(GL_LINE_STRIP);
			
			glVertex3f(10*0.8,10*cnt-1,0);
			glVertex3f(10*0.8,10*cnt,0);
			glVertex3f(0.8*3,10*cnt,0);

			glEnd();
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12*0.85, cnt*10-0.8, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit);
			glPushMatrix();
			glRasterPos3f(-12*0.85, cnt*Ladder_Unit, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			glPopMatrix();
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10-0.8, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit);
			glRasterPos3f(10*0.85, cnt*Ladder_Unit, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
		}
	}
	glDisable(GL_SCISSOR_TEST);
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawSpeedLadder(float x, float y, float ScaleX, float ScaleY)
{
	char string[50];

	glPushMatrix();
	glTranslatef(x,y,0);
	glTranslatef(-3,1.5,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"SPD");
	glRasterPos3f(0,0.1,0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
	}
	

	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
		glColor3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0.01,0,0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.01,0,0);
		glVertex3f(0.01,-30,0);
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
		glColor3f(0,1,0);
		glVertex3f(0,-30,0);
		glVertex3f(0.01,-30,0);
	glEnd();
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(0.01,-17.5,0);
	glBegin(GL_LINE_STRIP);		// arrow
		glColor3f(0,1,0);
		glVertex3f(0.01,1.5,0);
		glVertex3f(0.0025,1.5,0);
		glVertex3f(0,0,0);
		glVertex3f(0.0025,-1.5,0);
		glVertex3f(0.01,-1.5,0);
		glVertex3f(0.01,1.5,0);
	glEnd();
	sprintf(string,"%.1f",this->HUD_Data.TAS);
	glRasterPos3f(0.0025,-0.5,0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
	}
	glPopMatrix();
	glEnable(GL_SCISSOR_TEST);
	glScissor(0,WINDOW_SIZE_Y/2*y,WINDOW_SIZE_X,WINDOW_SIZE_Y/2.8);
	glStencilFunc(GL_NEVER, 0x0, 0x0);
    glStencilOp(GL_INCR, GL_INCR, GL_INCR);

	float Detector = 0;//this->HUD_Data.theta;

	float cnt = Detector-36;
	float Ladder_Scale_X = 0.1;
	float Ladder_Unit = 10;
	float max_indicate_num = 1000;
	glPushMatrix();
	glTranslatef(0,-this->HUD_Data.TAS*4-17.5,0);
	for(cnt;cnt<Detector+max_indicate_num;cnt=cnt+4)
	{
		if(cnt < Detector+0.01 && cnt > Detector-0.01)
		{
			glBegin(GL_LINE_STRIP);
			
			glVertex3f(0.007,0,0);
			glVertex3f(0.01,0,0);
			
			glEnd();
			sprintf(string,"0");
			//glRasterPos3f(-16.5*0.85, this->HUD_Data.theta*10-1, 0);
			glRasterPos3f(0.002, -0.5, 0);
			
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}		
		}

		if(cnt>Detector+0.01 && cnt<max_indicate_num)
		{
			glBegin(GL_LINE_STRIP);

			glVertex3f(0.007,cnt,0);
			glVertex3f(0.01,cnt,0);
			
			glEnd();
			
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12*0.85, cnt*10-0.8, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit/40);
			//cnt*Ladder_Unit
			glRasterPos3f(0.002, -0.5+cnt, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10-0.8, 0);
			
		}
		if(cnt<Detector-0.01 && -cnt<max_indicate_num)
		{
			glBegin(GL_QUADS);
			glColor3f(1,0,1);
			glVertex3f(0.007,cnt+4,0);
			glVertex3f(0.01,cnt+4,0);
			glVertex3f(0.01,cnt-20,0);
			glVertex3f(0.007,cnt-20,0);
			glEnd();
			glColor3f(0,1,0);
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12*0.85, cnt*10-0.8, 0);
			
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10-0.8, 0);
			
		}
	}
	glDisable(GL_SCISSOR_TEST);
	glPopMatrix();
	

	glPopMatrix();
}

void MMI_OPENGL_HUD::drawAltLadder(float x, float y, float ScaleX, float ScaleY)
{
	char string[50];

	glPushMatrix();
	glTranslatef(x,y,0);
	glTranslatef(2.5,1.5,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"ALT");
	glRasterPos3f(0,0.1,0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
	}
	

	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
		glColor3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0.01,0,0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.0,0,0);
		glVertex3f(0.0,-30,0);
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
		glColor3f(0,1,0);
		glVertex3f(0,-30,0);
		glVertex3f(0.01,-30,0);
	glEnd();
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(0,-17.5,0);
	glBegin(GL_LINE_STRIP);		// arrow
		glColor3f(0,1,0);
		glVertex3f(-0.01,1.5,0);
		glVertex3f(-0.0025,1.5,0);
		glVertex3f(0,0,0);
		glVertex3f(-0.0025,-1.5,0);
		glVertex3f(-0.01,-1.5,0);
		glVertex3f(-0.01,1.5,0);
	glEnd();
	sprintf(string,"%.0f",this->HUD_Data.Altitude);
	glRasterPos3f(-0.009,-0.5,0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
	}
	glPopMatrix();
	glEnable(GL_SCISSOR_TEST);
	glScissor(0,WINDOW_SIZE_Y/2*y,WINDOW_SIZE_X,WINDOW_SIZE_Y/2.8);
	glStencilFunc(GL_NEVER, 0x0, 0x0);
    glStencilOp(GL_INCR, GL_INCR, GL_INCR);
	
	float Detector = 0;//this->HUD_Data.theta;

	float cnt = Detector-36;
	float Ladder_Scale_X = 0.1;
	float Ladder_Unit = 10;
	float max_indicate_num = 1000;

	glTranslatef(0,-this->HUD_Data.Altitude/2.5-17.5,0);
	for(cnt;cnt<Detector+max_indicate_num;cnt=cnt+4)
	{
		if(cnt < Detector+0.01 && cnt > Detector-0.01)
		{
			glBegin(GL_LINE_STRIP);
			
			glVertex3f(0.000,0,0);
			glVertex3f(0.003,0,0);
			
			glEnd();
			sprintf(string,"0");
			//glRasterPos3f(-16.5*0.85, this->HUD_Data.theta*10-1, 0);
			glRasterPos3f(0.005, -0.5, 0);
			
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}		
		}

		if(cnt>Detector+0.01 && cnt<max_indicate_num)
		{
			glBegin(GL_LINE_STRIP);

			glVertex3f(0.0,cnt,0);
			glVertex3f(0.003,cnt,0);
			
			glEnd();
			
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12*0.85, cnt*10-0.8, 0);
			sprintf(string,"%.0f",(cnt)*Ladder_Unit/4);
			//cnt*Ladder_Unit
			glRasterPos3f(0.005, -0.5+cnt, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10-0.8, 0);
			
		}
		if(cnt<Detector-0.01 && -cnt<max_indicate_num)
		{
			glBegin(GL_QUADS);
			glColor3f(1,0,1);
			glVertex3f(0.003,cnt+4,0);
			glVertex3f(0.0,cnt+4,0);
			glVertex3f(0.0,cnt-20,0);
			glVertex3f(0.003,cnt-20,0);
			glEnd();
			glColor3f(0,1,0);
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(-12*0.85, cnt*10-0.8, 0);
			
			//sprintf(string,"%.1f",(cnt-this->HUD_Data.theta)*2.5);
			//glRasterPos3f(10*0.85, cnt*10-0.8, 0);
			
		}
	}
	glDisable(GL_SCISSOR_TEST);
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawRollIndicator(float x, float y, float ScaleX, float ScaleY)
{
	char string[50] ={NULL,};
	glPushMatrix();
	float y_translate = 0.75;
	glTranslatef(x,y+y_translate,0);
	glScalef(ScaleX,ScaleY,1);
	glPushMatrix();
	glTranslatef(0,12.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,0,0);
	glVertex3f(-1,-2,0);
	glVertex3f(1,-2,0);
	glVertex3f(0,0,0);
	glEnd();
	glPopMatrix();
	glRotatef(this->HUD_Data.phi,0,0,-1);
	for(int i=30;i<=150;i=i+10)
	{
		if(i%30==0)
		{
			glLineWidth(3);
			glBegin(GL_LINE_STRIP);
			glVertex3f(15*cos(i*D2R),15*sin(i*D2R),0);
			glVertex3f(13*cos(i*D2R),13*sin(i*D2R),0);
			
			//t3dDraw3D(str,0,0,1.5);
			glEnd();
			sprintf(string,"%d",-i+90);
			if(-i+90<0)
			{
				glRasterPos3f(16*cos(i*D2R)-2.5,16*sin(i*D2R)-0.5,0);
			}
			else
			{
				glRasterPos3f(16*cos(i*D2R)-0.5,16*sin(i*D2R),0);
			}
			
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
		}       
		else
		{
			glLineWidth(0.5);
			glBegin(GL_LINE_STRIP);
			glVertex3f(15*cos(i*D2R),15*sin(i*D2R),0);
			glVertex3f(14*cos(i*D2R),14*sin(i*D2R),0);
		}
		glEnd();
	}
	glLineWidth(1);
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawHeadingMarker(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	float y_translate = -4.1;
	glTranslatef(x,y+y_translate,0);

	glScalef(ScaleX,ScaleY,1);
	
	glRotatef(this->HUD_Data.Heading,0,0,1);
	for(int i=0;i<360;i=i+10)
	{
		if(i%30==0)
		{
			glLineWidth(3);
			glBegin(GL_LINE_STRIP);
			glVertex3f(12*cos(i*D2R),12*sin(i*D2R),0);
			glVertex3f(10*cos(i*D2R),10*sin(i*D2R),0);
			
			//t3dDraw3D(str,0,0,1.5);
			glEnd();
		}       
		else
		{
			glLineWidth(0.5);
			glBegin(GL_LINE_STRIP);
			glVertex3f(12*cos(i*D2R),12*sin(i*D2R),0);
			glVertex3f(11*cos(i*D2R),11*sin(i*D2R),0);
		}
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-3.1,0);
	//glRotatef(180,0,0,1);

	//GCS_Bearing
	float Rel_Bearing = this->HUD_Data.GCS_Bearing+180-this->HUD_Data.Heading;
	
	glRotatef(Rel_Bearing+180,0,0,-1);
	glTranslatef(0,0.45,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.075,0,0);
	glVertex3f(0.0,-0.075,0);
	glVertex3f(-0.075,0,0);
	glVertex3f(0.0,0.075,0);
	glVertex3f(0.075,0,0);
	glEnd();
	glTranslatef(0,-0.9,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.075,0,0);
	glVertex3f(0.0,0.075,0);
	glVertex3f(0.075,0,0);
	glEnd();
	glPopMatrix();

	float Rel_Wind = this->HUD_Data.Wind_Bearing+180-this->HUD_Data.Heading;
	glPushMatrix();
	glTranslatef(0,-3.1,0);
	glRotatef(Rel_Wind,0,0,-1);
	glTranslatef(0,0.45,0);
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(0,-0.025,0);
	glVertex3f(0.075,0.025,0);
	glVertex3f(0.075,-0.05,0);
	glVertex3f(0,-0.1,0);
	glVertex3f(-0.075,-0.05,0);
	glVertex3f(-0.075,0.025,0);
	glVertex3f(0,-0.025,0);
	glEnd();
	glTranslatef(0,-0.9,0);
	glBegin(GL_POLYGON);
	glVertex3f(0,-0.025,0);
	glVertex3f(0.075,0.025,0);
	glVertex3f(0.075,-0.05,0);
	glVertex3f(0,-0.1,0);
	glVertex3f(-0.075,-0.05,0);
	glVertex3f(-0.075,0.025,0);
	glVertex3f(0,-0.025,0);
	glEnd();
	glColor3f(0,1,0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,2.15+y_translate,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,-0.1,0);
	glVertex3f(0.1,0,0);
	glVertex3f(-0.1,0,0);
	glVertex3f(0,-0.1,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1.5+y_translate,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,0.1,0);
	glVertex3f(0.1,0,0);
	glVertex3f(-0.1,0,0);
	glVertex3f(0,0.1,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1.5+y_translate,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0,0.55,0);
	glVertex3f(0,0.1,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1+y_translate,0);
	glBegin(GL_QUADS);
	glVertex3f(0.02,0.15,0);
	glVertex3f(0.02,-0.15,0);
	glVertex3f(-0.02,-0.15,0);
	glVertex3f(-0.02,0.15,0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.2,0.07,0);
	glVertex3f(0.2,0.02,0);
	glVertex3f(-0.2,0.02,0);
	glVertex3f(-0.2,0.07,0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.05,-0.1,0);
	glVertex3f(0.05,-0.12,0);
	glVertex3f(-0.05,-0.12,0);
	glVertex3f(-0.05,-0.1,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPointSize(5);
	glTranslatef(0,1.05+y_translate,0);
	glBegin(GL_POINTS);
	glVertex3f(0.3,0,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,1.05+y_translate,0);
	glBegin(GL_POINTS);
	glVertex3f(-0.3,0,0);
	glEnd();
	glPopMatrix();
	glPointSize(1);

	sprintf(string,"%.0f",this->HUD_Data.Heading);
	glRasterPos3f(-0.15, -1.9, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	for(int i=0;i<360;i=i+15)
	{
		
		if(i%30==0)
		{
			glPushMatrix();
			
			//glOrtho(-10, 10, -10, 10, -1, 1);
			//glTranslatef(0,11.7,0);
			glTranslatef(-0.75*cos((i-this->HUD_Data.Heading+90)*D2R),0.75*sin((i-this->HUD_Data.Heading+90)*D2R)+y_translate,0);
			//glScalef(0.01,0.01,0.0005);
			//glRotatef(i,0,0,1);
			//glRotatef(i+altitude*10,0,0,1);
			//char *c;
			sprintf(string,"%d",i);
			glRasterPos3f(-0.1, 0.95, 0);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
				//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
			}
			glPopMatrix();
			//glLoadIdentity();
				
		}       
	}	                       
}

void MMI_OPENGL_HUD::drawGroundSpeed(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"%.0f  GS",this->HUD_Data.GS);
	glRasterPos3f(-25, -17, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawVerticalSpd(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"VV  %.0f",this->HUD_Data.GS);
	glRasterPos3f(20.7, -17, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawSpeedCmd(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"%.0f  CMD",this->HUD_Data.TAS_cmd);
	glRasterPos3f(-25, -15, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}
void MMI_OPENGL_HUD::drawAltCmd(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"CMD  %.0f",this->HUD_Data.Alt_cmd);
	glRasterPos3f(19, -15, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}
void MMI_OPENGL_HUD::drawHeading(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"HDG");
	glRasterPos3f(-27.5, -45, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"%.0f",this->HUD_Data.Heading);
	glRasterPos3f(-27.5, -47, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}

void  MMI_OPENGL_HUD::drawGCSIndicator(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"GCS");
	glRasterPos3f(-18.5, -46, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"%.0f",this->HUD_Data.GCS_Deviation);
	glRasterPos3f(-18.5, -48, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glTranslatef(-20,-45.25,0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.75,0,0);
	glVertex3f(0.0,-0.75,0);
	glVertex3f(-0.75,0,0);
	glVertex3f(0.0,0.75,0);
	glVertex3f(0.75,0,0);
	glEnd();
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawWindIndicator(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	sprintf(string,"WIND");
	glRasterPos3f(15.5, -46, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"%.0f",this->HUD_Data.Wind_Bearing);
	glRasterPos3f(15.5, -48, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glTranslatef(14.5,-45.25,0);
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.25,0,0);
	glVertex3f(0.25,0.75,0);
	glVertex3f(-0.5,0.75,0);
	glVertex3f(-1.0,0,0);
	glVertex3f(-0.5,-0.75,0);
	glVertex3f(0.25,-0.75,0);
	glVertex3f(-0.25,0,0);
	
	glEnd();
	glColor3f(0,1,0);
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawLLA(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	float x_translate = -30;
	float y_translate = 25;
	sprintf(string,"LAT  %.6f",this->HUD_Data.Latitude);
	glRasterPos3f(0+x_translate, 0+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"LON  %.6f",this->HUD_Data.Longitude);
	glRasterPos3f(0+x_translate, -1.2+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"ALT  %.1f",this->HUD_Data.Altitude);
	glRasterPos3f(0+x_translate, -2.4+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}
void MMI_OPENGL_HUD::drawUTC(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);	
	float x_translate = 19;
	float y_translate = 25;
	SYSTEMTIME st;
	GetLocalTime(&st);

	sprintf(string,"LOCAL KST %d:%d:%d",st.wHour,st.wMinute,st.wSecond);
	glRasterPos3f(0+x_translate, 0+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	sprintf(string,"              %d/%d/%d",st.wDay,st.wMonth,st.wYear);
	glRasterPos3f(0+x_translate, 0+y_translate-1.5, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	glPopMatrix();
}


void MMI_OPENGL_HUD::drawRPMIndicator(float x, float y, float ScaleX, float ScaleY)
{
	char string[50];
	glPushMatrix();
	float x_translate = 2.5;
	float y_translate = -2;
	glTranslatef(x+x_translate,y+y_translate,0);
	glScalef(ScaleX*8,ScaleY*8,1);
	glBegin(GL_LINE_STRIP);
	glColor3f(1,1,1);
	for(int i=30;i<270;i++)
	{
		float x = 0.5*cos(i*D2R);
		float y = 0.5*sin(i*D2R);
		glVertex3f(x,y,0);
	
	}
	glColor3f(0.1,1,0.1);
	glEnd();
	
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.5*cos(270*D2R),0.5*sin(270*D2R),0);
			glVertex3f(0.45*cos(270*D2R),0.4*sin(270*D2R),0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1,1,1);
			glVertex3f(0.5*cos(30*D2R),0.5*sin(30*D2R),0);
			glVertex3f(0.45*cos(40*D2R),0.4*sin(30*D2R),0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1,0.9,0);
			glVertex3f(0.5*cos(40*D2R),0.5*sin(40*D2R),0);
			glVertex3f(0.45*cos(45*D2R),0.4*sin(40*D2R),0);
			glEnd();
			glColor3f(1,1,1);
			glTranslatef(0.05,-0.2,0);
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.5,0,0);
			glVertex3f(0,0,0);
			glVertex3f(0,0.2,0);
			glVertex3f(0.5,0.2,0);
			glVertex3f(0.5,0,0);
			glEnd();
			sprintf(string,"%.0f",this->HUD_Data.RPM);
			glColor3f(1,1,1);
			glRasterPos2f(0.1,0.04);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
			}
			sprintf(string,"RPM");
			glRasterPos2f(0.1,-0.2);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
	
	glPopMatrix();

	glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(x+x_translate,y+y_translate,0);
			glScalef(ScaleX*8,ScaleY*8,0);
			glRotatef(this->HUD_Data.RPM*0.04+180,0,0,-1);
			glBegin(GL_TRIANGLES);
			glVertex3f(0,0.5,0);
			glVertex3f(0.02,0,0);
			glVertex3f(-0.02,0,0);
	
	
			glEnd();
			glColor3f(0.1,1,0.1);
	glPopMatrix();
}
void MMI_OPENGL_HUD::drawPowerIndicator(float x, float y, float ScaleX, float ScaleY)
{
	char string[50];
	glPushMatrix();
	float x_translate = 2.5;
	float y_translate = -2.75;
	glTranslatef(x+x_translate,y+y_translate,0);
	glScalef(ScaleX*8,ScaleY*8,1);
	glBegin(GL_LINE_STRIP);
	glColor3f(1,1,1);
	for(int i=30;i<270;i++)
	{
		float x = 0.5*cos(i*D2R);
		float y = 0.5*sin(i*D2R);
		glVertex3f(x,y,0);
	
	}
	glColor3f(0.1,1,0.1);
	glEnd();
	
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.5*cos(270*D2R),0.5*sin(270*D2R),0);
			glVertex3f(0.45*cos(270*D2R),0.4*sin(270*D2R),0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1,1,1);
			glVertex3f(0.5*cos(30*D2R),0.5*sin(30*D2R),0);
			glVertex3f(0.45*cos(40*D2R),0.4*sin(30*D2R),0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1,0.9,0);
			glVertex3f(0.5*cos(40*D2R),0.5*sin(40*D2R),0);
			glVertex3f(0.45*cos(45*D2R),0.4*sin(40*D2R),0);
			glEnd();
			glColor3f(1,1,1);
			glTranslatef(0.05,-0.2,0);
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.5,0,0);
			glVertex3f(0,0,0);
			glVertex3f(0,0.2,0);
			glVertex3f(0.5,0.2,0);
			glVertex3f(0.5,0,0);
			glEnd();
			sprintf(string,"%.0f",this->HUD_Data.Power_cmd);
			glColor3f(1,1,1);
			glRasterPos2f(0.1,0.04);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
			}
			sprintf(string,"POW");
			glRasterPos2f(0.1,-0.2);
			for(unsigned int i=0;i<strlen(string);i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , string[i]);
			}
	
	glPopMatrix();

	glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(x+x_translate,y+y_translate,0);
			glScalef(ScaleX*8,ScaleY*8,0);
			glRotatef(this->HUD_Data.RPM*0.04+180,0,0,-1);
			glBegin(GL_TRIANGLES);
			glVertex3f(0,0.5,0);
			glVertex3f(0.02,0,0);
			glVertex3f(-0.02,0,0);
			glEnd();
			glColor3f(0.1,1,0.1);
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawGPSStatus(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	float x_translate = 25;
	float y_translate = 20;
	switch(this->HUD_Data.GPS_Status)
	{
	case 0:
		sprintf(string,"GPS STBY");
		break;
	case 1:
		sprintf(string,"GPS NAV");
		break;
	}

	glRasterPos3f(0+x_translate, 0+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	
	glPopMatrix();
}

void MMI_OPENGL_HUD::drawFCCStatus(float x, float y, float ScaleX, float ScaleY)
{
	char string[200] ={NULL,};
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(ScaleX,ScaleY,1);
	float x_translate = 25;
	float y_translate = 21.5;
	switch(this->HUD_Data.FCC_Status)
	{
	case 0:
		sprintf(string,"FCC STBY");
		break;
	case 1:
		sprintf(string,"FCC NAV");
		break;
	}

	glRasterPos3f(0+x_translate, 0+y_translate, 0);
	for(unsigned int i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , string[i]);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN ,*c);
	}
	
	glPopMatrix();
}