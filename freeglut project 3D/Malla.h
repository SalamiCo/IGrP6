//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#include "PV3D.h"
#include "Cara.h"
#include "Matr.h"
#include "Objeto3D.h"

#include <windows.h>

#include <gl/gl.h>
#include <gl/glu.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

class Malla : public Objeto3D
{
private:
	int numVertices;
	PV3D** vertice;
	int numNormales;
	PV3D** normal;
	int numCaras;
	Cara** cara;

public:
	Malla(void);
	~Malla(void);
	void dibuja(bool rellena, bool normales);
	PV3D* vectorNormalNewell(Cara* c);
	void hazMallaSuperficie();
};

