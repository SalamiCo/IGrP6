//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "BolasCompuesto.h"

BolasCompuesto::BolasCompuesto(void){
	TAfin* ta = new TAfin();
	ta->traslacion(1.4, 0, 0);
	this->tAfin = ta;

	TColor colorNegro = TColor((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0);
	Objeto3D* bolaNegra = new TEsfera(0.2, 30, 30, 7, 4.2, 3, colorNegro);

	TColor colorRojo = TColor((GLfloat)1.0, (GLfloat)0.0, (GLfloat)0.0);
	Objeto3D* bola1 = new TEsfera(0.2, 30, 30, 6.2, 4.2, 3, colorRojo);
	Objeto3D* bola2 = new TEsfera(0.2, 30, 30, 6.6, 4.2, 3.2, colorRojo);
	Objeto3D* bola3 = new TEsfera(0.2, 30, 30, 6.6, 4.2, 2.8, colorRojo);
	Objeto3D* bola4 = new TEsfera(0.2, 30, 30, 7, 4.2, 3.4, colorRojo);
	Objeto3D* bola5 = new TEsfera(0.2, 30, 30, 7, 4.2, 2.6, colorRojo);
	Objeto3D* bola6 = new TEsfera(0.2, 30, 30, 7.4, 4.2, 3.6, colorRojo);
	Objeto3D* bola7 = new TEsfera(0.2, 30, 30, 7.4, 4.2, 3.2, colorRojo);
	Objeto3D* bola9 = new TEsfera(0.2, 30, 30, 7.4, 4.2, 2.8, colorRojo);
	Objeto3D* bola10 = new TEsfera(0.2, 30, 30, 7.4, 4.2, 2.4, colorRojo);
	Objeto3D* bola11 = new TEsfera(0.2, 30, 30, 7.8, 4.2, 3.8, colorRojo);
	Objeto3D* bola12 = new TEsfera(0.2, 30, 30, 7.8, 4.2, 3.4, colorRojo);
	Objeto3D* bola13 = new TEsfera(0.2, 30, 30, 7.8, 4.2, 3, colorRojo);
	Objeto3D* bola14 = new TEsfera(0.2, 30, 30, 7.8, 4.2, 2.6, colorRojo);
	Objeto3D* bola15 = new TEsfera(0.2, 30, 30, 7.8, 4.2, 2.2, colorRojo);

	addHijo(bolaNegra);
	addHijo(bola1);
	addHijo(bola2);
	addHijo(bola3);
	addHijo(bola4);
	addHijo(bola5);
	addHijo(bola6);
	addHijo(bola7);
	addHijo(bola9);
	addHijo(bola10);
	addHijo(bola11);
	addHijo(bola12);
	addHijo(bola13);
	addHijo(bola14);
	addHijo(bola15);

}