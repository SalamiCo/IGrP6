//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "PV3D.h"

class Camara{
	private:
		PV3D eye, look, up; 
		PV3D *u, *v, *n;
		GLdouble left, right, top, bottom;
		GLdouble nearC, farC, fovy, aspect;
		
	public:
		Camara(void){};
		Camara(PV3D eye, PV3D look, PV3D up);
		~Camara(void){};

		void roll(GLdouble rad);
		void yaw(GLdouble rad);
		void pitch(GLdouble rad);
		void recorridoEje(GLdouble x, GLdouble y, GLdouble z);
		void giraX(GLdouble angle);
		void giraY(GLdouble angle);
		void giraZ(GLdouble angle);
		void lateral();
		void frontal();
		void cenital();
		void esquina();

		void desplazar(GLdouble x, GLdouble y, GLdouble z);
};