#pragma once
#include "objetocuadrico.h"

#include "TColor.h"

class TCubo : public ObjetoCuadrico
{
private:
	GLfloat lado;
	GLfloat xT, yT, zT;
	TColor color;

public:
	TCubo(void);
	TCubo(GLfloat l, GLfloat xT, GLfloat yT, GLfloat zT, TColor c);
	~TCubo(void);

	virtual void dibuja();
};

