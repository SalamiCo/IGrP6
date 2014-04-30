//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

class TAfin
{
private:

	GLfloat* matr;

public:
	TAfin(void);
	~TAfin(void){};

	GLfloat* getMatr(){ return this->matr; }

	void traslacion(GLfloat x, GLfloat y, GLfloat z);
	void escalacion(GLfloat x, GLfloat y, GLfloat z);
	void rotacion(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

	void postMultiplica(GLfloat* mm);
};

