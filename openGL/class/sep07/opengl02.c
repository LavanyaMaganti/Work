
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double x,y,z,dx;

void init();
void display();
void animate();

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800,600);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program");

   glutDisplayFunc(display);
   glutIdleFunc(animate);

   init();

   glutMainLoop();
}
void init()
{
  x = y = z = 1.0;
  dx = -0.001;
}
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_LINES);
      glVertex3f(0.0, 0.0, 0.0);
      glVertex3f(x,y,z);
   glEnd();
   glFlush();
}
void animate()
{
   x += dx;
   if(x < -1.0)
     dx = -dx;
   glutPostRedisplay();
}
