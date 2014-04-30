//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include "objeto3d.h"
class ObjetoCuadrico :
	public Objeto3D
{
public:
	ObjetoCuadrico(void);
	~ObjetoCuadrico(void){};

	virtual void dibuja(){};
};

