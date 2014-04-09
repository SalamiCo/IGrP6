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

void Camara::giraX(GLdouble angle){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	eye.setY(100 * cos(angle));
	eye.setZ(100 * sin(angle));
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::giraY(GLdouble angle){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	eye.setX(100 * cos(angle));
	eye.setZ(100 * sin(angle));
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::giraZ(GLdouble angle){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	eye.setX(100 * cos(angle));
	eye.setY(100 * sin(angle));
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());
}

void Camara::desplazar(GLdouble x, GLdouble y, GLdouble z){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	eye.setX(eye.getX() + x);
	eye.setY(eye.getY() + y);
	eye.setZ(eye.getZ() + z);
	look.setY(look.getY() + y);
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), 0.0, look.getY(), 0.0, up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::lateral(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(100.0, 0.0, 0.0, look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::frontal(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 100.0, look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::cenital(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 100.0, 0.0, look.getX(), look.getY(), look.getZ(), 1.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::esquina(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(100.0, 100.0, 100.0, look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}