#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
  glClearColor(0.0,0.0,0.0,0.0);	
  glShadeModel(GL_FLAT);	
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 1.0);
  glLoadIdentity();
  
  glScalef(1.0, 1.0, 1.0);
  glRotatef(60, 0.1, 0.1, 0.0);
  glutSolidSphere(65.0,20.0,20.0);
  glFlush();
}



void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-120, 120, -120, 120, -120, 120);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
  //  Inicializar los parámetros GLUT y de usuario proceso
  glutInit(&argc,argv);
  // Solicitar ventana con color real y doble buffer con Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100,100);
  // Crear ventana
  glutCreateWindow("Esfera");
  init ();
  // Funciones de retrollamada
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  // Pasar el control de eventos a GLUT
  glutMainLoop();
  // Regresar al sistema operativo
  return 0;
}
