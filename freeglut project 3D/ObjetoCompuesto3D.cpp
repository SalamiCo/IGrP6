//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D(void)
{
	this->hijos = new Objeto3D*[30]; //30 por defecto
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

void ObjetoCompuesto3D::traslacionEscena(GLfloat x, GLfloat y, GLfloat z){
	for(int i=0; i<numHijos; i++){
		TAfin* ta = hijos[i]->getTAfin();
		ta->traslacion(x,y,z);
	}
}

void ObjetoCompuesto3D::escalacionEscena(GLfloat x, GLfloat y, GLfloat z){
	for(int i=0; i<numHijos; i++){
		TAfin* ta = hijos[i]->getTAfin();
		ta->escalacion(x,y,z);
	}
}

void ObjetoCompuesto3D::rotacionEscena(GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	for(int i=0; i<numHijos; i++){
		TAfin* ta = hijos[i]->getTAfin();
		ta->rotacion(angle,x,y,z);
	}
}