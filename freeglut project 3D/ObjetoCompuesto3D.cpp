//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D(void)
{
	this->hijos = new Objeto3D*[15]; //15 por defecto
	this->numHijos = 0;
}

void ObjetoCompuesto3D::addHijo(Objeto3D* obj){
	hijos[numHijos] = obj;
	numHijos++;
}

void ObjetoCompuesto3D::dibuja(){
	for(int i=0; i<numHijos; i++){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();

		glMultMatrixf(hijos[i]->getTAfin()->getMatr());
		hijos[i]->dibuja();

		glPopMatrix();
	}
}