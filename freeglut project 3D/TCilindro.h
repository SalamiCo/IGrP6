#pragma once
#include "objetocuadrico.h"
class TCilindro :
	public ObjetoCuadrico
{
private:
	GLfloat base, top, heigth, slices, stacks, x, y, z;

public:
	TCilindro(void);
	TCilindro(GLfloat base, GLfloat top, GLfloat heigth, GLfloat slice, GLfloat stacks, GLfloat x, GLfloat y, GLfloat z);
	~TCilindro(void);

	virtual void dibuja();
};

