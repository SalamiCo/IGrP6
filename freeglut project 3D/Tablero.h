#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include "malla.h"
class Tablero :
	public Malla
{
private:
	float anchoT, largoT, gruesoT;
	int partesAncho, partesLargo, partesGrueso;

public:
	Tablero(void);
	Tablero(float a, float l, float g, int pa, int pl, int pg);
	~Tablero(void);

	float getAncho(){return this->anchoT;}
	float getLargo(){return this->largoT;}
	float getGrueso(){return this->gruesoT;}

	int getPartesAncho(){return this->partesAncho;}
	int getPartesLargo(){return this->partesLargo;}
	int getPartesGrueso(){return this->partesGrueso;}
};

