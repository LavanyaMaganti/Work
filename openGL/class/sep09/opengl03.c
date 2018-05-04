
#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double x,y,z,dx;

void init();
void display();
void animate();
void keyboard(unsigned char c, int x, int y);

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800,600);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program");

   glutDisplayFunc(display);
   glutIdleFunc(animate);
   glutKeyboardFunc(keyboard);

   init();

   glutMainLoop();
}
void init()
{
  x = y = z = 1.0;
  dx = -0.01;
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
   glutSwapBuffers();
}
void animate()
{
   x += dx;
   if(x < -1.0 && dx < 0)
     dx = -dx;
   else if(x > 1.0 && dx > 0)
     dx = -dx;
   glutPostRedisplay();
}
void keyboard(unsigned char c, int x, int y)
{
   fprintf(stderr,"%3d%6d%6d\n", c, x, y);
   switch(c){
     case 27: exit(0);
   }
}
