//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "TCubo.h"


TCubo::TCubo(void)
{
	this->lado = 0;
	this->xT = 0;
	this->yT = 0;
	this->zT = 0;
}

TCubo::TCubo(GLfloat l, GLfloat xT, GLfloat yT, GLfloat zT, GLfloat xE, GLfloat yE, GLfloat zE, TColor c, int t){
	this->lado = l;
	this->color = c;
	this->xT = xT;
	this->yT = yT;
	this->zT = zT;
	this->xE = xE;
	this->yE = yE;
	this->zE = zE;
	this->type = t;
	TAfin* afin = new TAfin();
	afin->escalacion(xE, yE, zE);
	afin->traslacion(xT, yT, zT);
	this->tAfin = afin;
}


TCubo::~TCubo(void)
{
}

void TCubo::dibuja(){
	if(type == 0){
		glColor3f(color.getRed(), color.getGreen(), color.getBlue());
		//glTranslated(xT, yT, zT);

		glBegin(GL_POLYGON);
		glVertex3f(  lado, -lado, -lado );
		glVertex3f(  lado,  lado, -lado );
		glVertex3f( -lado,  lado, -lado );
		glVertex3f( -lado, -lado, -lado );
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(  lado, -lado, lado );
		glVertex3f(  lado,  lado, lado );
		glVertex3f( -lado,  lado, lado );
		glVertex3f( -lado, -lado, lado );
		glEnd();
 
		glBegin(GL_POLYGON);
		glVertex3f( lado, -lado, -lado );
		glVertex3f( lado,  lado, -lado );
		glVertex3f( lado,  lado,  lado );
		glVertex3f( lado, -lado,  lado );
		glEnd();
 
		glBegin(GL_POLYGON);
		glVertex3f( -lado, -lado,  lado );
		glVertex3f( -lado,  lado,  lado );
		glVertex3f( -lado,  lado, -lado );
		glVertex3f( -lado, -lado, -lado );
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(  lado, -lado, -lado );
		glVertex3f(  lado, -lado,  lado );
		glVertex3f( -lado, -lado,  lado );
		glVertex3f( -lado, -lado, -lado );
		glEnd();

		//LADO SUPERIOR – Lado Azul
		glBegin(GL_POLYGON);
		glColor3f(   0.0,  0.0,  1.0 );
		glVertex3f(  lado,  lado,  lado );
		glVertex3f(  lado,  lado, -lado );
		glVertex3f( -lado,  lado, -lado );
		glVertex3f( -lado, lado,  lado );
		glEnd();
	} else {
		glColor3f(color.getRed(), color.getGreen(), color.getBlue());
		glutSolidCube(lado);
	}
}
