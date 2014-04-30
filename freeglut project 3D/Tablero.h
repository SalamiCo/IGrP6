//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include "malla.h"
class Tablero : public Malla
{
private:
	int anchoT, largoT, altoT;
	int partesAncho, partesLargo, partesAlto;

public:
	Tablero(void);
	Tablero(int a, int l, int al, int pa, int pl, int pal, TAfin* ta);
	~Tablero(void);

	int getAncho(){return this->anchoT;}
	int getLargo(){return this->largoT;}
	int getAlto(){return this->altoT;}

	int getPartesAncho(){return this->partesAncho;}
	int getPartesLargo(){return this->partesLargo;}
	int getPartesAlto(){return this->partesAlto;}
};

