#include "Tablero.h"


Tablero::Tablero(void)
{
}

//Largo = 6 vertices, Ancho = 4 vertices, alto = 2 vertices
Tablero::Tablero(int a, int l, int al, int pa, int pl, int pal){
	this->anchoT = a;
	this->largoT = l;
	this->altoT = al;
	this->partesAncho = pa;
	this->partesLargo = pl;
	this->partesAlto = pal;

	setNumVertices((pl*pa) /*+ (pa*pal*2) + (pl*pal*2)*/); //cara arriba + cara abajo + caras laterales
	setNumNormales(numVertices);
	setNumCaras(((pl-1)*(pa-1)) /*+ ((pa-1)*(pal-1)*2) + ((pl-1)*(pal-1)*2)*/);

	vertice = new PV3D* [numVertices];
	normal = new PV3D* [numNormales];
	cara = new Cara* [numCaras];

	//Cara arriba
	int u = l / pl, v = a / pa;
	for(int i = 0; i < pa; i++){ //ancho
		for(int j = 0; j < pl; j++){ //largo
			int indiceVertice = i * pl + j;
			vertice[indiceVertice] = new PV3D(u*j, pal, v*(pa-i-1), 1);
			normal[indiceVertice] = new PV3D();

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

Tablero::~Tablero(void)
{
}
