//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#include "PV3D.h"
#include "Cara.h"
#include "Matr.h"
#include "Objeto3D.h"
#include "TColor.h"

#include <windows.h>

#include <gl/gl.h>
#include <gl/glu.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

class Malla : public Objeto3D
{
protected:
	int numVertices;
	PV3D** vertice;
	int numNormales;
	PV3D** normal;
	int numCaras;
	Cara** cara;

	GLfloat angleX, angleY, angleZ;

public:
	Malla(void);
	Malla(int numV, int numN, int numC, PV3D** v, PV3D** n, Cara** c);
	~Malla(void){};
	virtual void dibuja(){dibuja(true, false);};
	void dibuja(bool rellena, bool normales);
	PV3D* vectorNormalNewell(Cara* c);
	void hazMallaSuperficie();

	int getNumVertices(){return numVertices;}
	int getNumNormales(){return numNormales;}
	int getNumCaras(){return numCaras;}

	void setNumVertices(int nv){this->numVertices = nv;}
	void setNumNormales(int nn){this->numNormales = nn;}
	void setNumCaras(int nc){this->numCaras = nc;}
};

