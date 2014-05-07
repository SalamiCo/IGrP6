//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "MesaBillar.h"

MesaBillar::MesaBillar(void){
	//Tablero
	TAfin* afinTablero = new TAfin();
	afinTablero->traslacion(0,0,0);
	Objeto3D* tablero = new Tablero(8,12,4,4,6,2, afinTablero);

	//Bordes
	TColor colorMarron = TColor((GLfloat)0.55, (GLfloat)0.27, (GLfloat)0.07);
	Objeto3D* borde1 = new TCubo(1, 5, 4, 0.25, 10, 0.5, 0.5, colorMarron, 1);
	Objeto3D* borde2 = new TCubo(1, 0.25, 4, 3, 0.5, 0.5, 6, colorMarron, 1);
	Objeto3D* borde3 = new TCubo(1, 5, 4, 5.75, 10, 0.5, 0.5, colorMarron, 1);
	Objeto3D* borde4 = new TCubo(1, 9.75, 4, 3, 0.5, 0.5, 6, colorMarron, 1);

	//Patas
	Objeto3D* pata1 = new TCilindro(0.5, 0.5, 2, 10, 4, 1, 0, 1, 270, 1, 0, 0, colorMarron);
	Objeto3D* pata2 = new TCilindro(0.5, 0.5, 2, 10, 4, 9, 0, 1, 270, 1, 0, 0, colorMarron);
	Objeto3D* pata3 = new TCilindro(0.5, 0.5, 2, 10, 4, 1, 0, 5, 270, 1, 0, 0, colorMarron);
	Objeto3D* pata4 = new TCilindro(0.5, 0.5, 2, 10, 4, 9, 0, 5, 270, 1, 0, 0, colorMarron);

	//Bolas
	TColor colorBlanco = TColor((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);
	Objeto3D* bolaBlanca = new TEsfera(0.2, 30, 30, 2, 4.2, 3, colorBlanco);

	Objeto3D* bolas = new BolasCompuesto();

	//Taco
	TColor colorGoldenRod = TColor((GLfloat)0.85, (GLfloat)0.65, (GLfloat)0.13);
	TColor colorChocolate = TColor((GLfloat)0.82, (GLfloat)0.41, (GLfloat)0.12);
	Objeto3D* taco = new TCilindro(0.1, 0.1, 4, 10, 4, 1, 4.4, 3, 270, 0, 1, 0, colorGoldenRod);
	Objeto3D* mango = new TCilindro(0.1, 0.1, 3, 10, 4, -3, 4.4, 3, 270, 0, 1, 0, colorChocolate);
	Objeto3D* punta = new TCilindro(0.1, 0.1, 0.5, 10, 4, 1.5, 4.4, 3, 270, 0, 1, 0, colorBlanco);

	//Tiza
	Objeto3D* tiza = new TCubo(0.1, 0.3, 4.4, 5.7, 1, 1, 1, colorBlanco, 0);

	//Añadir objetos
	addHijo(tablero);

	addHijo(borde1);
	addHijo(borde2);
	addHijo(borde3);
	addHijo(borde4);

	addHijo(pata1);
	addHijo(pata2);
	addHijo(pata3);
	addHijo(pata4);
	
	addHijo(bolaBlanca);
	addHijo(bolas);

	addHijo(taco);
	addHijo(mango);
	addHijo(punta);

	addHijo(tiza);

	TAfin* ta = new TAfin();
	this->tAfin = ta;

}