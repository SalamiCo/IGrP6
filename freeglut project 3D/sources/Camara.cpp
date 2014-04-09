//Pedro Morgado Alarc�n
//Samuel M�ndez Gal�n

#include "Camara.h"

Camara::Camara(PV3D eye, PV3D look, PV3D up){
	this->eye = eye;
	this->look = look;
	this->up = up;
	this->right = 10;
	this->left = -this->right;
	this->top = 10;
	this->bottom = -this->top;
	this->nearC = 1;
	this->farC = 1000;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(this->eye.getX(), this->eye.getY(), this->eye.getZ(),
				this->look.getX(), this->look.getY(), this->look.getZ(),
				this->up.getX(), this->up.getY(), this->up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(this->left, this->right, this->bottom, this->top, this->nearC, this->farC);
}

void Camara::recorridoEje(GLdouble x, GLdouble y, GLdouble z){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	eye.setX(eye.getX() + x);
	eye.setY(eye.getY() + y);
	eye.setZ(eye.getZ() + z);
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}