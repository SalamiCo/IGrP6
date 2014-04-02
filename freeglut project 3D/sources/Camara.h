//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

class Camara{
	private:

	public:
		Camara(void);
		~Camara(void){};

		void roll(GLdouble rad);
		void yaw(GLdouble rad);
		void pitch(GLdouble rad);

		void desplazar(GLdouble x, GLdouble y, GLdouble z);
};