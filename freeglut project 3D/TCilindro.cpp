//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "TCilindro.h"


TCilindro::TCilindro(void)
{
	this->base = 0;
	this->top = 0;
	this->heigth = 0;
	this->slices = 0;
	this->stacks = 0;
	this->xT = 0;
	this->yT = 0;
	this->zT = 0;
	this->angle = 0;
	this->xR = 0;
	this->yR = 0;
	this->zR = 0;
}

TCilindro::TCilindro(GLfloat base, GLfloat top, GLfloat heigth, GLfloat slices, GLfloat stacks, GLfloat xT, GLfloat yT, GLfloat zT, GLfloat angle, GLfloat xR, GLfloat yR, GLfloat zR, TColor c){
	this->base = base;
	this->top = top;
	this->heigth = heigth;
	this->slices = slices;
	this->stacks = stacks;
	this->xT = xT;
	this->yT = yT;
	this->zT = zT;
	this->angle = angle;
	this->angle = angle;
	this->xR = xR;
	this->yR = yR;
	this->zR = zR;
	this->color = c;
	TAfin* afin = new TAfin();
	afin->rotacion(angle, xR, yR, zR);
	afin->traslacion(xT, yT, zT);
	this->tAfin = afin;
}

TCilindro::~TCilindro(void)
{
}

void TCilindro::dibuja(){
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);

	GLUquadricObj* cilindro = gluNewQuadric();
	glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	gluCylinder(cilindro, base, top, heigth, slices, stacks);
	gluDeleteQuadric(cilindro);

	glPopMatrix();
}
