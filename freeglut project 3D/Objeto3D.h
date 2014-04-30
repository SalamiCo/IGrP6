//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include "TAfin.h"

class Objeto3D
{
protected:
	TAfin* tAfin;

public:
	Objeto3D(void);
	Objeto3D(TAfin* ta);
	~Objeto3D(void){};

	virtual void dibuja() = 0;

	TAfin* getTAfin(){ return tAfin; }
};

