//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "TColor.h"


TColor::TColor(void)
{
	this->red = 0.0;
	this->green = 0.0;
	this->blue = 0.0;
}

TColor::TColor(GLfloat r, GLfloat g, GLfloat b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

TColor::~TColor(void)
{
}
