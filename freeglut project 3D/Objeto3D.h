#pragma once

#include "TAfin.h"

class Objeto3D
{
private:
	TAfin* tAfin;

public:
	Objeto3D(void);
	~Objeto3D(void);

	virtual void dibuja() = 0;

	TAfin* getTAfin(){ return tAfin; }
};

