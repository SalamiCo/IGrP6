//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include "PV3D.h"

class Camara{
	private:
		PV3D eye, look, up, u, v, n;
		GLdouble left, right, top, bottom;
		GLdouble nearC, farC, fovy, aspect;
	public:
		Camara(void);
		~Camara(void){};

		void roll(GLdouble rad);
		void yaw(GLdouble rad);
		void pitch(GLdouble rad);
		void recorridoEje(GLdouble x, GLdouble y, GLdouble z);

		void desplazar(GLdouble x, GLdouble y, GLdouble z);
};