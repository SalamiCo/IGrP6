//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Malla.h"

Malla::Malla(void):Objeto3D(new TAfin()){
	this->numVertices = 0;
	this->numNormales = 0;
	this->numCaras = 0;
	this->vertice = new PV3D*[1];
	this->normal = new PV3D*[numCaras];
	this->cara = new Cara*[numCaras];
	
	angleX = angleY = angleZ = 0.0;
}

Malla::Malla(int numV, int numN, int numC, PV3D** v, PV3D** n, Cara** c, TAfin* ta):Objeto3D(ta){
	this->numVertices = numV;
	this->numNormales = numN;
	this->numCaras = numC;
	this->vertice = v;
	this->normal = n;
	this->cara = c;

	angleX = angleY = angleZ = 0.0;
}

void Malla::dibuja(bool rellena, bool normales){
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);

	glRotated(angleX, 1,0,0);
	glRotated(angleY, 0,1,0);
	glRotated(angleZ, 0,0,1);

	for(int i = 0; i < numCaras; i++){
		glColor3f(0.f, 0.f, 1.f);
		glLineWidth(1.0);

		if(rellena)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glBegin(GL_POLYGON);
		for(int j = 0; j < cara[i]->getNumVertices(); j++){
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();

		if(normales){
			//Pintar las normales
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_LINES);
			for(int j = 0; j < cara[i]->getNumVertices(); j++){
				int iN = cara[i]->getIndiceNormalK(j);
				int iV = cara[i]->getIndiceVerticeK(j);
				glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
				glVertex3f(vertice[iV]->getX() + normal[iN]->getX(), vertice[iV]->getY() + normal[iN]->getY(), vertice[iV]->getZ() + normal[iN]->getZ());
			}
			glEnd();
		}
	}
	glPopMatrix();
}


PV3D* Malla::vectorNormalNewell(Cara* c){
	PV3D* n = new PV3D();
	for(int i=0; i<c->getNumVertices(); i++){
		PV3D* vertActual = vertice[c->getIndiceVerticeK(i)];
		PV3D* vertSig = vertice[c->getIndiceVerticeK((i+1) % c->getNumVertices())];

		n->setX(n->getX() + ((vertActual->getY() - vertSig->getY()) * (vertActual->getZ() + vertSig->getZ())));
		n->setY(n->getY() + ((vertActual->getZ() - vertSig->getZ()) * (vertActual->getX() + vertSig->getX())));
		n->setZ(n->getZ() + ((vertActual->getX() - vertSig->getX()) * (vertActual->getY() + vertSig->getY())));
	}
	return n->normaliza();
}

void Malla::hazMallaSuperficie(){
	//Perfil por marco de Frenet
	int nP = 20; //Numero de lados
	PV3D perfil[20];
	double inc = (2*M_PI)/nP;
	double r = 0.5;
	for(int i=0; i<nP; i++){
		perfil[i] = PV3D(r*cos(2*M_PI-i*-inc), r*sin(2*M_PI-i*-inc), 0, 1);
	}

	Matr m;
	numVertices = 6;
	vertice = new PV3D*[numVertices];
	numNormales = 6;
	normal = new PV3D*[numNormales];
	numCaras = 6;
	cara = new Cara*[numCaras];

	for(int i=0; i<2; i++){
		float t = (4* M_PI * i) / 150.0;
		m = Matr::matrizNBTC(t);
		for(int j=0; j<nP; j++){
			int i1 = (i + 1) % 150;
			int j1 = (j + 1) % nP;

			int k00 = i * nP + j;
			int k01 = i * nP + j1;
			int k10 = i1 * nP + j;
			int k11 = i1 * nP + j1;

			VerticeNormal** vns = new VerticeNormal*[4];
			vns[0] = new VerticeNormal(k00, k00);
			vns[1] = new VerticeNormal(k01, k01);
			vns[2] = new VerticeNormal(k11, k11);
			vns[3] = new VerticeNormal(k10, k10);

			vertice[k00] = new PV3D(m.prodVect(perfil[j]));
			cara[k00]    = new Cara(4, vns);
			normal[k00]  = new PV3D();
		}
	}

	for(int i=0; i<150; i++){
		for(int j=0; j<nP; j++){
			int k = i * nP + j;
			normal[k]  = vectorNormalNewell(cara[k]);
		}
	}
}
