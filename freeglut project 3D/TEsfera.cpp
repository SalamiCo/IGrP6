//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "TEsfera.h"


TEsfera::TEsfera(void)
{
	this->radius = 0;
	this->slices = 0;
	this->stacks = 0;
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

TEsfera::TEsfera(GLfloat radius, GLfloat slices, GLfloat stacks, GLfloat x, GLfloat y, GLfloat z, TColor c){
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
	this->x = x;
	this->y = y;
	this->z = z;
	this->color = c;
	TAfin* afin = new TAfin();
	afin->traslacion(x, y, z);
	this->tAfin = afin;
}

TEsfera::~TEsfera(void)
{
}

void TEsfera::dibuja(){
	GLUquadricObj* esfera = gluNewQuadric();
	glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	gluSphere(esfera, radius, slices, stacks);
	gluDeleteQuadric(esfera);
}
