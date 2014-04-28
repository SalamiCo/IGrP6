//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Camara.h"

Camara::Camara(PV3D eye, PV3D look, PV3D up){
	this->eye = eye;
	this->look = look;
	this->up = up;

	PV3D pv3d = PV3D(this->eye.getX() - this->look.getX(), this->eye.getY() - this->look.getY(), this->eye.getZ() - this->look.getZ(), 0);
	this->n = pv3d.normaliza();
	this->u = this->up.productoVectorial(this->n)->normaliza();
	this->v = this->n->productoVectorial(this->u);

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

void Camara::roll(GLdouble rad){
	/*PV3D* uprima = new PV3D((u->getX()*cos(rad)) + (v->getX()*sin(rad)), 
							(u->getY()*cos(rad)) + (v->getY()*sin(rad)), 
							(u->getZ()*cos(rad)) + (v->getZ()*sin(rad)), 
							0);

	PV3D* vprima = new PV3D((-(u->getX())*sin(rad)) + (v->getX()*cos(rad)), 
							(-(u->getY())*sin(rad)) + (v->getY()*cos(rad)), 
							(-(u->getZ())*sin(rad)) + (v->getZ()*cos(rad)), 
							0);*/

	PV3D* tprima = u->clona();

	u->setX((tprima->getX()*cos(rad)) - (v->getX()*sin(rad))); 
	u->setY((tprima->getY()*cos(rad)) - (v->getY()*sin(rad)));
	u->setZ((tprima->getZ()*cos(rad)) - (v->getZ()*sin(rad)));

	v->setX((tprima->getX())*sin(rad) + (v->getX()*cos(rad)));
	v->setY((tprima->getY())*sin(rad) + (v->getY()*cos(rad)));
	v->setZ((tprima->getZ())*sin(rad) + (v->getZ()*cos(rad)));

	GLfloat m[16] = {u->getX(), v->getX(), n->getX(), 0, 
						u->getY(), v->getY(), n->getY(), 0,
						u->getZ(), v->getZ(), n->getZ(), 0, 
						-(eye.productoEscalar(u)), -(eye.productoEscalar(v)), -(eye.productoEscalar(n)), 1};

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
}

void Camara::yaw(GLdouble rad){
	PV3D* tprima = u->clona();

	u->setX((tprima->getX()*cos(rad)) + (n->getX()*sin(rad))); 
	u->setY((tprima->getY()*cos(rad)) + (n->getY()*sin(rad)));
	u->setZ((tprima->getZ()*cos(rad)) + (n->getZ()*sin(rad)));

	n->setX(-((tprima->getX())*sin(rad)) + (n->getX()*cos(rad)));
	n->setY(-((tprima->getY())*sin(rad)) + (n->getY()*cos(rad)));
	n->setZ(-((tprima->getZ())*sin(rad)) + (n->getZ()*cos(rad)));

	GLfloat m[16] = {u->getX(), v->getX(), n->getX(), 0, 
						u->getY(), v->getY(), n->getY(), 0,
						u->getZ(), v->getZ(), n->getZ(), 0, 
						-(eye.productoEscalar(u)), -(eye.productoEscalar(v)), -(eye.productoEscalar(n)), 1};

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
}

void Camara::pitch(GLdouble rad){
	PV3D* tprima = n->clona();

	n->setX((tprima->getX()*cos(rad)) + (v->getX()*sin(rad))); 
	n->setY((tprima->getY()*cos(rad)) + (v->getY()*sin(rad)));
	n->setZ((tprima->getZ()*cos(rad)) + (v->getZ()*sin(rad)));

	v->setX(-((tprima->getX())*sin(rad)) + (v->getX()*cos(rad)));
	v->setY(-((tprima->getY())*sin(rad)) + (v->getY()*cos(rad)));
	v->setZ(-((tprima->getZ())*sin(rad)) + (v->getZ()*cos(rad)));

	GLfloat m[16] = {u->getX(), v->getX(), n->getX(), 0, 
						u->getY(), v->getY(), n->getY(), 0,
						u->getZ(), v->getZ(), n->getZ(), 0, 
						-(eye.productoEscalar(u)), -(eye.productoEscalar(v)), -(eye.productoEscalar(n)), 1};

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
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

	GLdouble angle2 = atan2(eye.getZ(), eye.getY()) + angle;
	GLdouble dst = sqrt((eye.getY() * eye.getY()) + (eye.getZ() * eye.getZ()));

	eye.setY(dst * cos(angle2));
	eye.setZ(dst * sin(angle2));
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::giraY(GLdouble angle){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLdouble angle2 = atan2(eye.getZ(), eye.getX()) + angle;
	GLdouble dst = sqrt((eye.getX() * eye.getX()) + (eye.getZ() * eye.getZ()));

	eye.setX(dst * cos(angle2));
	eye.setZ(dst * sin(angle2));
	gluLookAt(eye.getX(), eye.getY(), eye.getZ(), look.getX(), look.getY(), look.getZ(), up.getX(), up.getY(), up.getZ());

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, nearC, farC);
}

void Camara::giraZ(GLdouble angle){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLdouble angle2 = atan2(eye.getY(), eye.getX()) + angle;
	GLdouble dst = sqrt((eye.getY() * eye.getY()) + (eye.getX() * eye.getX()));

	eye.setX(dst * cos(angle2));
	eye.setY(dst * sin(angle2));
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