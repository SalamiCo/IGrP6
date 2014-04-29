#pragma once

#include "TAfin.h"

class Objeto3D
{
private:
	TAfin tafin;

public:
	Objeto3D(void);
	~Objeto3D(void);

	virtual void dibuja() = 0;
};

