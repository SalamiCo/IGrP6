//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

#include "Coche.h"

Coche::Coche(){
	this->size = 3;
}

void Coche::drawCoche(GLdouble size){
	//Cubo
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(size);
}
