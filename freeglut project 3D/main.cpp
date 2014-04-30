//Pedro Morgado Alarcón
//Samuel Méndez Galán

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
using namespace std;

#include "Coche.h"
#include "Camara.h"
#include "PV3D.h"
//#include "Objeto3D.h"
#include "Tablero.h"
#include "ObjetoCompuesto3D.h"
#include "TAfin.h"
#include "TCilindro.h"
#include "TEsfera.h"

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=10.0, eyeY=10.0, eyeZ=10.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

//Our parameters
Coche coche;
GLdouble angleX = 0.0;
GLdouble angleY = 0.0;
GLdouble angleZ = 0.0;
Camara camera;
GLdouble recorridoX = 0.0;
GLdouble recorridoY = 0.0;
GLdouble recorridoZ = 0.0;
GLdouble desplazaY = 0.0;

GLdouble angleGiraX = 0.0;
GLdouble angleGiraY = 0.0;
GLdouble angleGiraZ = 0.0;

PV3D d = PV3D(0.1, 0.1, 1, 0); //Para proyección oblicua

ObjetoCompuesto3D* objCompuesto;
Objeto3D* tablero;

void buildScene() {
	objCompuesto = new ObjetoCompuesto3D();

	//Tablero
	TAfin* afinTablero = new TAfin();
	afinTablero->traslacion(0,10,0);
	tablero = new Tablero(8,12,4,4,6,2, afinTablero);

	//Patas
	Objeto3D* pata1 = new TCilindro(0.5, 0.5, 2, 10, 4, 1, 0, 1);
	Objeto3D* pata2 = new TCilindro(0.5, 0.5, 2, 10, 4, 9, 0, 1);
	Objeto3D* pata3 = new TCilindro(0.5, 0.5, 2, 10, 4, 1, 0, 5);
	Objeto3D* pata4 = new TCilindro(0.5, 0.5, 2, 10, 4, 9, 0, 5);

	//Bolas
	TColor colorBlanco = TColor((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);
	Objeto3D* bolaBlanca = new TEsfera(0.2, 30, 30, 2, 4.2, 3, colorBlanco);

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

	//Añadir objetos
	objCompuesto->addHijo(tablero);
	objCompuesto->addHijo(pata1);
	objCompuesto->addHijo(pata2);
	objCompuesto->addHijo(pata3);
	objCompuesto->addHijo(pata4);
	objCompuesto->addHijo(bolaBlanca);
	objCompuesto->addHijo(bolaNegra);
	objCompuesto->addHijo(bola1);
	objCompuesto->addHijo(bola2);
	objCompuesto->addHijo(bola3);
	objCompuesto->addHijo(bola4);
	objCompuesto->addHijo(bola5);
	objCompuesto->addHijo(bola6);
	objCompuesto->addHijo(bola7);
	objCompuesto->addHijo(bola9);
	objCompuesto->addHijo(bola10);
	objCompuesto->addHijo(bola11);
	objCompuesto->addHijo(bola12);
	objCompuesto->addHijo(bola13);
	objCompuesto->addHijo(bola14);
	objCompuesto->addHijo(bola15);

	// Camera set up
	camera = Camara(PV3D(eyeX, eyeY, eyeZ, 1), PV3D(lookX, lookY, lookZ, 1), PV3D(upX, upY, upZ, 0));

}

void initGL() {	 	
	buildScene();

	//glClearColor(0.6f,0.7f,0.8f,1.0);
	glClearColor(0.0f,0.0f,0.0f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	 // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	
	// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);

		glColor3f(1.0, 0.0, 0.0);
	glEnd();

	//Our code

	/*glPushMatrix();
	glMatrixMode(GL_MODELVIEW);

	glRotated(angleX, 1,0,0);
	glRotated(angleY, 0,1,0);
	glRotated(angleZ, 0,0,1);


	glColor3f(1.0, 0.0, 0.0);
	//coche.drawCoche(4);
	glutSolidCube(4);

	glPopMatrix();*/
	//tablero->dibuja();
	objCompuesto->dibuja();

	
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;	

		/*case 'a': //Eje X
			angleX += 1.0;
			break;
		case 'z': //Eje X
			angleX -= 1.0;
			break;

		case 's': //Eje Y
			angleY += 1.0;
			break;
		case 'x': //Eje Y
			angleY -= 1.0;
			break;

		case 'd': //Eje Z
			angleZ += 1.0;
			break;
		case 'c': //Eje Z
			angleZ -= 1.0;
			break;*/
		case 'u': //roll
			camera.roll(0.09); //0.09 radianes = 5 grados
			break;
		case 'i':
			camera.roll(-0.09);
			break;

		case 'j': //yaw
			camera.yaw(0.01);
			break;
		case 'k':
			camera.yaw(-0.01);
			break;

		case 'n': //pitch
			camera.pitch(0.01);
			break;
		case 'm':
			camera.pitch(-0.01);
			break;

		case 'e': //Along axis X
			recorridoX = 10.0;
			recorridoY = 0.0;
			recorridoZ = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;
		case 'r':
			recorridoX = -10.0;
			recorridoY = 0.0;
			recorridoZ = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;

		case 'd': //Along axis Y
			recorridoY = 10.0;
			recorridoX = 0.0;
			recorridoZ = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;
		case 'f':
			recorridoY = -10.0;
			recorridoX = 0.0;
			recorridoZ = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;

		case 'c': //Along axis Z
			recorridoZ = 10.0;
			recorridoX = 0.0;
			recorridoY = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;
		case 'v':
			recorridoZ = -10.0;
			recorridoX = 0.0;
			recorridoY = 0.0;
			camera.recorridoEje(recorridoX, recorridoY, recorridoZ);
			break;

		case 's': //Desplazar
			desplazaY = 2.0; 
			camera.desplazar(0.0, desplazaY, 0.0);
			break;
		case 'x':
			desplazaY = -2.0;
			camera.desplazar(0.0, desplazaY, 0.0);
			break;

		case '1': //Gira X
			//angleGiraX += 0.1;
			camera.giraX(0.1);
			break;

		case '2': //Gira Y
			//angleGiraY += 0.1;
			camera.giraY(0.1);
			break;

		case '3': //Gira Z
			//angleGiraZ += 0.1;
			camera.giraZ(0.1);
			break;

		case '4': //Lateral
			camera.lateral();
			break;

		case '5': //Frontal
			camera.frontal();
			break;

		case '6': //Cenital
			camera.cenital();
			break;

		case '7': //Esquina
			camera.esquina();
			break;

		case 'o': //Ortogonal
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(xLeft, xRight, yBot, yTop, N, F);
			break;
		case 'p': //Perspectiva
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45, 1, N, F);
			break;
		case 'l': //Oblicua
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			
			d.normaliza();

			if(d.getZ() != 0.0 && (d.getX() != 0 || d.getY() != 0 || d.getZ() != 1)){
				GLfloat m[16] = {	
						1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1
					};
				m[8] = -(d.getX()) / d.getZ();
				m[9] = -(d.getY()) / d.getZ();
				m[12] = -N * (d.getX() / d.getZ());
				m[13] = -N * (d.getY() / d.getZ());

				glOrtho(xLeft, xRight, yBot, yTop, N, F);
				glMultMatrixf(m);
			}
			break;

		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	//system("PAUSE"); 
   
	return 0;
}
