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
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);		
}

void TAfin::escalacion(GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(x, y, z);
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::rotacion(GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(angle, x, y, z);
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::postMultiplica(GLfloat* matr){
	glLoadMatrixf(this->matr);
	glMultMatrixf(matr);
}
