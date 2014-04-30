//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include "objetocuadrico.h"

#include "TColor.h"

class TEsfera :
	public ObjetoCuadrico
{
private:
	GLfloat radius, slices, stacks, x, y, z;
	TColor color;

public:
	TEsfera(void);
	TEsfera(GLfloat radius, GLfloat slice, GLfloat stacks, GLfloat x, GLfloat y, GLfloat z, TColor c);
	~TEsfera(void);

	virtual void dibuja();
};

