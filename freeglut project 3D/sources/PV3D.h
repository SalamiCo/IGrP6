//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <cmath>

class PV3D
{

private:
	GLdouble x, y, z;
	int pv; // 0: vector 1: punto
	PV3D *t, *b, *n;
public:
	PV3D(void);
	PV3D(GLdouble x, GLdouble y, GLdouble z, int pv);
	~PV3D(void){};
	
	GLdouble getX(){return x;};
	GLdouble getY(){return y;};
	GLdouble getZ(){return z;};
	int getPV(){return pv;};
	void setX(GLdouble x){this->x = x;};
	void setY(GLdouble y){this->y = y;};
	void setZ(GLdouble z){this->z = z;};
	void setPV(int pv){this->pv = pv;};
	PV3D* getT(){return t;};
	PV3D* getB(){return b;};
	PV3D* getN(){return n;};

	GLdouble module(PV3D* v);
	PV3D* normaliza();
	GLdouble productoEscalar(PV3D* v);
	PV3D* productoVectorial(PV3D* v);
	PV3D* calculaValorFormula(float t);
	PV3D* calculaValorPrimDerivada(float t);
	PV3D* calculaValorSegDerivada(float t);
	PV3D* calculaT(PV3D* c);
	PV3D* calculaB(PV3D* c, PV3D* cc);
	PV3D* calculaN();

	PV3D* clona();
};