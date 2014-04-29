#pragma once
#include "objeto3d.h"
class ObjetoCompuesto3D :
	public Objeto3D
{
private:
	Objeto3D** hijos;
	int numHijos;

public:
	ObjetoCompuesto3D(void);
	~ObjetoCompuesto3D(void);


};

