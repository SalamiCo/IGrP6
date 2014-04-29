#include "Tablero.h"


Tablero::Tablero(void)
{
}

Tablero::Tablero(float a, float l, float g, int pa, int pl, int pg){
	this->anchoT = a;
	this->largoT = l;
	this->gruesoT = g;
	this->partesAncho = pa;
	this->partesLargo = pl;
	this->partesGrueso = pg;
}

Tablero::~Tablero(void)
{
}
