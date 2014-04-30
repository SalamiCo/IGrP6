//Pedro Morgado Alarcón
//Samuel Méndez Galán

#pragma once
#include "objetocuadrico.h"

#include "TColor.h"

class TCubo : public ObjetoCuadrico
{
private:
	GLfloat lado;
	GLfloat xT, yT, zT;
	GLfloat xE, yE, zE;
	TColor color;
	int type; //0: tiza, 1:borde

public:
	TCubo(void);
	TCubo(GLfloat l, GLfloat xT, GLfloat yT, GLfloat zT, GLfloat xE, GLfloat yE, GLfloat zE, TColor c, int t);
	~TCubo(void);

	virtual void dibuja();
};

