//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

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