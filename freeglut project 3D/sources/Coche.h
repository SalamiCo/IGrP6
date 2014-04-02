//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include "PV3D.h"

class Coche {
	private:
		GLdouble size;
	public:
		Coche(void);
		~Coche(void){};

		void drawCoche(GLdouble size);
};