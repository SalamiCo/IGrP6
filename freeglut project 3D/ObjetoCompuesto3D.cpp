#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D(void)
{
}


ObjetoCompuesto3D::~ObjetoCompuesto3D(void)
{
}

void ObjetoCompuesto3D::dibuja(){
	for(int i=0; i<numHijos; i++){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();

		glMultMatrixf(hijos[i]->getTAfin()->getMatr());
		hijos[i]->dibuja();

		glPopMatrix();
	}
}