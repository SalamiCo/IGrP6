//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

class TColor
{
private:
	GLfloat red, green, blue;

public:
	TColor(void);
	TColor(GLfloat r, GLfloat g, GLfloat b);
	~TColor(void);

	GLfloat getRed(){ return this->red; }
	GLfloat getGreen(){ return this->green; }
	GLfloat getBlue(){ return this->blue; }

	void setRed(GLfloat r){ this->red = r; }
	void setGreen(GLfloat g){ this->green = g; }
	void setBlue(GLfloat b){ this->blue = b; }
};

