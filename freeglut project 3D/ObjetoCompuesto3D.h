//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include "objeto3d.h"
class ObjetoCompuesto3D :
	public Objeto3D
{
private:
	Objeto3D** hijos;
	int numHijos;

public:
	ObjetoCompuesto3D(void);
	~ObjetoCompuesto3D(void){};

	void addHijo(Objeto3D* obj);
	int getNumHijos(){ return this->numHijos; }

	virtual void dibuja();

	void traslacionEscena(GLfloat x, GLfloat y, GLfloat z);
	void escalacionEscena(GLfloat x, GLfloat y, GLfloat z);
	void rotacionEscena(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
};

