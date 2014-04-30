//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include "TAfin.h"


TAfin::TAfin(void)
{
	this->matr = new GLfloat[16];
	glPushMatrix();
    glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX,this->matr);
    glPopMatrix();
}

void TAfin::traslacion(GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(x, y, z);
		GLfloat* mm= new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);
	
}

void TAfin::escalacion(GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(x, y, z);
		GLfloat mm[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::rotacion(GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(angle, x, y, z);
		GLfloat mm[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::postMultiplica(GLfloat* mm){
	//glLoadMatrixf(this->matr);
	//glMultMatrixf(mm);
	GLfloat* res = new GLfloat[16]; 
    for(int i=0; i<4 ; i++){
		for(int j=0; j<4; j++){
			res[i*4+j] = 0;
			for(int k=0; k<4; k++ ){
				int resAux = i*4+j;
				int matrixAux = i*4+k;
				int mmAux = k*4+j;
				res[i*4+j]+= matr[i*4+k] * mm[k*4+j];
			}
		}
	}
    GLfloat* aux = matr;
    matr = res;
    delete[]aux;
    res = NULL;
}
