
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800,600);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program");

   glutDisplayFunc(display);

   glutMainLoop();
}
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_LINES);
      glVertex3f(0.0, 0.0, 0.0);
      glVertex3f(1.0, 1.0, 1.0);
   glEnd();
   glFlush();
}
