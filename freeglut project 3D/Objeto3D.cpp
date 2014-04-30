//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Objeto3D.h"

Objeto3D::Objeto3D(){
	this->tAfin = new TAfin();
}

Objeto3D::Objeto3D(TAfin* ta)
{
	this->tAfin = ta;
}