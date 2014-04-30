//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "Malla.h"

Malla::Malla(void){
	this->numVertices = 0;
	this->numNormales = 0;
	this->numCaras = 0;
	this->vertice = new PV3D*[1];
	this->normal = new PV3D*[numCaras];
	this->cara = new Cara*[numCaras];
	
	angleX = angleY = angleZ = 0.0;
}

Malla::Malla(int numV, int numN, int numC, PV3D** v, PV3D** n, Cara** c){
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

		//Color marron
		if(i < 15){
			TColor colorVerde = TColor((GLfloat)0.0, (GLfloat)0.5, (GLfloat)0.0);
			glColor3f(colorVerde.getRed(), colorVerde.getGreen(), colorVerde.getBlue());
		} else {
			TColor colorMarron = TColor((GLfloat)0.55, (GLfloat)0.27, (GLfloat)0.07);
			glColor3f(colorMarron.getRed(), colorMarron.getGreen(), colorMarron.getBlue());
		}

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
