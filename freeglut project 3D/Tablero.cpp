//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Tablero.h"
#include <iostream>


Tablero::Tablero(void)
{
}

//Largo = 6 vertices, Ancho = 4 vertices, alto = 2 vertices
Tablero::Tablero(int a, int l, int al, int pa, int pl, int pal, TAfin* ta){
	this->anchoT = a;
	this->largoT = l;
	this->altoT = al;
	this->partesAncho = pa;
	this->partesLargo = pl;
	this->partesAlto = pal;
	this->tAfin = ta;

	setNumVertices((pl*pa*2) + (pa*pal*2) + (pl*pal*2)); //cara arriba + cara abajo + caras laterales
	setNumNormales(numVertices);
	setNumCaras(((pl-1)*(pa-1)*2) + ((pa-1)*(pal-1)*2) + ((pl-1)*(pal-1)*2));

	vertice = new PV3D* [numVertices];
	normal = new PV3D* [numNormales];
	cara = new Cara* [numCaras];

	//Cara arriba
	int u = l / pl, v = a / pa;
	for(int i = 0; i < pa; i++){ //ancho
		for(int j = 0; j < pl; j++){ //largo
			int indiceVertice = i * pl + j;
			vertice[indiceVertice] = new PV3D(u*j, al, v*(pa-i-1), 1);
			normal[indiceVertice] = new PV3D(0, 1, 0, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = (i-1) * (pl-1) + (j-1);
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pl, indiceVertice-pl);
				vns[2] = new VerticeNormal(indiceVertice-pl-1, indiceVertice-pl-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}	
	}

	//Cara abajo
	for(int i = 0; i < pa; i++){ //ancho
		for(int j = 0; j < pl; j++){ //largo
			int indiceVertice = (i * pl + j) + 24;
			vertice[indiceVertice] = new PV3D(u*j, al - 2, v*(pa-i-1), 1);
			normal[indiceVertice] = new PV3D(0, -1, 0, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = ((i-1) * (pl-1) + (j-1)) + 15;
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pl, indiceVertice-pl);
				vns[2] = new VerticeNormal(indiceVertice-pl-1, indiceVertice-pl-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}
	}

	//Cara trasera
	v = al / pal;
	for(int i = 0; i < pal; i++){ //alto
		for(int j = 0; j < pl; j++){ //largo
			int indiceVertice = (i * pl + j) + 48;
			vertice[indiceVertice] = new PV3D(u*j, (v*i) + 2, 0, 1);
			normal[indiceVertice] = new PV3D(0, 0, -1, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = ((i-1) * (pl-1) + (j-1)) + 30;
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pl, indiceVertice-pl);
				vns[2] = new VerticeNormal(indiceVertice-pl-1, indiceVertice-pl-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}
	}

	//Cara delantera
	for(int i = 0; i < pal; i++){ //alto
		for(int j = 0; j < pl; j++){ //largo
			int indiceVertice = (i * pl + j) + 60;
			vertice[indiceVertice] = new PV3D(u*j, (v*i) + 2, 6, 1);
			normal[indiceVertice] = new PV3D(0, 0, 1, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = ((i-1) * (pl-1) + (j-1)) + 35;
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pl, indiceVertice-pl);
				vns[2] = new VerticeNormal(indiceVertice-pl-1, indiceVertice-pl-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}
	}

	//Cara lateral izquierda
	u = al / pal, v = a / pa;
	for(int i = 0; i < pal; i++){ //alto
		for(int j = 0; j < pa; j++){ //ancho
			int indiceVertice = (i * pa + j) + 72;
			vertice[indiceVertice] = new PV3D(0, (u * i) + 2, (v * j), 1);
			normal[indiceVertice] = new PV3D(-1, 0, 0, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = ((i-1) * (pa-1) + (j-1)) + 40;
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pa, indiceVertice-pa);
				vns[2] = new VerticeNormal(indiceVertice-pa-1, indiceVertice-pa-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}
	}

	//Cara lateral derecha
	for(int i = 0; i < pal; i++){ //alto
		for(int j = 0; j < pa; j++){ //ancho
			int indiceVertice = (i * pa + j) + 80;
			vertice[indiceVertice] = new PV3D(10, (u * i) + 2, (v * j), 1);
			normal[indiceVertice] = new PV3D(1, 0, 0, 0);
			normal[indiceVertice]->normaliza();

			if(i > 0 && j > 0){
				int indiceCara = ((i-1) * (pa-1) + (j-1)) + 43;
				VerticeNormal** vns = new VerticeNormal*[4];
				vns[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vns[1] = new VerticeNormal(indiceVertice-pa, indiceVertice-pa);
				vns[2] = new VerticeNormal(indiceVertice-pa-1, indiceVertice-pa-1);
				vns[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vns);
			}
		}
	}
}

Tablero::~Tablero(void)
{
}
