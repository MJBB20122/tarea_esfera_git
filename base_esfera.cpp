#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>



//declarando variables 
// Propiedades del material
	GLfloat mat__ambient[] = {0.25,0.20725,0.20725};
	GLfloat mat__diffuse[] = {0.54,0.89,0.63};
	GLfloat mat__specular[] = {0.727811,0.626959,0.626959};
	GLfloat mat__shine[] = {0.2};
	
//funcion que dibuja la esfera 
void material(GLfloat mat_ambient[], GLfloat mat_diffuse[], GLfloat mat_specular[],GLfloat mat_shine[]) {
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
	
		glutSolidSphere(65.0,20.0,20.0);
		glFlush();
}
void init(void)
{

// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-120, 120, -120, 120, -120, 120);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}


void display(void)
{

// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

// Rotacion de 20 grados en torno al eje x
    glRotated(20.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
    glPushMatrix();
//llamando a la funcion material
   material(mat__ambient, mat__diffuse, mat__specular, mat__shine);
    
    
}


//funcion para teclas
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'c':
	case 'C':
		mat__ambient[0] =  0.19125; // cooper
		mat__ambient[1] =  0.0735;
		mat__ambient[2] =  0.0225;
		mat__ambient[3] = 1.0;
		
		mat__diffuse[0] =  0.7038; //cooper
		mat__diffuse[1] =  0.27048;
		mat__diffuse[2] =  0.0828;
		mat__diffuse[3] = 1.0;
		
		mat__specular[0] =  0.256777; //cooper
		mat__specular[1] = 0.137622;
		mat__specular[2] = 0.086014;
		mat__specular[3] =  1.0;
		
		mat__shine[0] = 12.8; // cooper
		display();
		break;
		
	case 'r':
	case 'R':
		mat__ambient[0] =  0.0; //red plastic
		mat__ambient[1] =  0.0;
		mat__ambient[2] = 0.0;
		mat__ambient[3] = 1.0;
		
		mat__diffuse[0] =  0.5; //red plastic
		mat__diffuse[1] =  0.0;
		mat__diffuse[2] =  0.0;
		mat__diffuse[3] =  1.0;
		
		mat__specular[0] =  0.7; //red plastic
		mat__specular[1] =  0.6;
		mat__specular[2] =  0.6;
		mat__specular[3] =  1.0;
		
		mat__shine[0] = 32.0; //red plastic
		display();
		break;
	case 'g':
	case 'G':
		mat__ambient[0] =  0.24725; // gold
		mat__ambient[1] =  0.1995; 
		mat__ambient[2] =  0.0745;
		mat__ambient[3] =  1.0; 
		
		mat__diffuse[0] =  0.75164; //gold
		mat__diffuse[1] =  0.60648;
		mat__diffuse[2] =  0.22640;
		mat__diffuse[3] =  1.0;
		
		mat__specular[0] =  0.628181; //gold
		mat__specular[1] =  0.555802;
		mat__specular[2] =  0.366065;
		mat__specular[3] =  1.0;
		
		mat__shine[0] = 51.2; // gold
		display();
		break;
    
		
	case 'b':
	case 'B':
		mat__ambient[0] =  0.329412; //brass
		mat__ambient[1] =  0.223529;
		mat__ambient[2] =  0.027451;
		mat__ambient[3] =  1.0;
		
		mat__diffuse[0] =  0.780392; //brass
		mat__diffuse[1] =  0.568627; 	
		mat__diffuse[2] =  0.113725; 	
		mat__diffuse[3] =  1.0; 	
		
		mat__specular[0] =  0.992157;	//brass
		mat__specular[1] =  0.941176;	
		mat__specular[2] =  0.807843;
		mat__specular[3] =  1.0;	
		
		mat__shine[0] = 40.0; 	//brass
	display();
	break;
	
	 case 's':
	 case 'S':
	
		mat__ambient[0] =  0.0; //silver
		mat__ambient[1] =  0.0;
		mat__ambient[2] = 0.0;
		mat__ambient[3] = 1.0;
		
		mat__diffuse[0] =  0.5; //silver
		mat__diffuse[1] =  0.4;
		mat__diffuse[2] =  0.4;
		mat__diffuse[3] =  1.0;
		
		mat__specular[0] =  0.7; //silver
		mat__specular[1] =  0.6;
		mat__specular[2] =  0.6;
		mat__specular[3] =  1.0;
		
		mat__shine[0] = 32.0; //silver
    display();
    break;
        
    }
       //Solicitar actualización de visualización
		glutPostRedisplay();
}

// Main del programa.
int main(int argc, char **argv)
{
	// Inicializo OpenGL
    glutInit(&argc, argv);

	// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

	// Definimos una ventana de medidas 650 x 650 
	// de visualizacion en pixels
    glutInitWindowSize (650, 650);

	// Posicionamos la ventana en la esquina superior izquierda de
	// la pantalla.
    glutInitWindowPosition (0, 0);

	// Creamos literalmente la ventana y le adjudicamos el nombre que se
	// observara en su barra de titulo.
    glutCreateWindow ("Esfera");

	// Inicializamos el sistema
    init();
	//callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
