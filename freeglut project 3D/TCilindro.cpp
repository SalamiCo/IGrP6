#include "TCilindro.h"


TCilindro::TCilindro(void)
{
	this->base = 0;
	this->top = 0;
	this->heigth = 0;
	this->slices = 0;
	this->stacks = 0;
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

TCilindro::TCilindro(GLfloat base, GLfloat top, GLfloat heigth, GLfloat slices, GLfloat stacks, GLfloat x, GLfloat y, GLfloat z){
	this->base = base;
	this->top = top;
	this->heigth = heigth;
	this->slices = slices;
	this->stacks = stacks;
	this->x = x;
	this->y = y;
	this->z = z;
}

TCilindro::~TCilindro(void)
{
}

void TCilindro::dibuja(){
	//glPushMatrix();
	GLUquadricObj* cilindro = gluNewQuadric();
	glTranslatef(x, y, z);
	glRotated(270, 1, 0, 0);
	gluCylinder(cilindro, base, top, heigth, slices, stacks);
	gluDeleteQuadric(cilindro);
	//glPopMatrix();
}
