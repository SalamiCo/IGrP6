//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include "objetocuadrico.h"
#include "TColor.h"

class TCilindro :
	public ObjetoCuadrico
{
private:
	GLfloat base, top, heigth, slices, stacks, xT, yT, zT, angle, xR, yR, zR;
	TColor color;

public:
	TCilindro(void);
	TCilindro(GLfloat base, GLfloat top, GLfloat heigth, GLfloat slice, GLfloat stacks, GLfloat xT, GLfloat yT, GLfloat zT, GLfloat angle, GLfloat xR, GLfloat yR, GLfloat zR, TColor c);
	~TCilindro(void);

	virtual void dibuja();
};

