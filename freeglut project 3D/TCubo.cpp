#include "TCubo.h"


TCubo::TCubo(void)
{
	this->lado = 0;
	this->xT = 0;
	this->yT = 0;
	this->zT = 0;
}

TCubo::TCubo(GLfloat l, GLfloat xT, GLfloat yT, GLfloat zT,  TColor c){
	this->lado = l;
	this->color = c;
	this->xT = xT;
	this->yT = yT;
	this->zT = zT;
}


TCubo::~TCubo(void)
{
}

void TCubo::dibuja(){
	glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	glTranslated(xT, yT, zT);

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
}
