
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

typedef struct thing {
   double x, y, z;     // position
   double vx, vy, vz;  // velocity
   double theta, phi;  // heading (orientation) angles
   double len;
} THING;

THING it;

void init();
void display();
void animate();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);
void mouse(int bno, int state, int x, int y);
void motion(int x, int y);

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");

   glutDisplayFunc(display);
   glutIdleFunc(animate);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);

   init();

   glutMainLoop();
}
void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  it.x = it.y = it.z = 0.0; 
  it.vx = it.vy = it.vz = 0.0; 
  it.theta = 0.0;
  it.phi = 0.0;
  it.len = 0.25;
}
void accelerate(double ds)
{
   double xzlen;
   double dx,dy,dz;

   xzlen = ds * cos(it.phi);
   it.vy += ds * sin(it.phi);
   it.vx += xzlen * cos(it.theta);  
   it.vz += xzlen * sin(it.theta);  
   fprintf(stderr,"%f  %f  %f\n", it.vx, it.vy, it.vz);
}
void display()
{
   double xzlen;
   double dx,dy,dz;

   glClear(GL_COLOR_BUFFER_BIT);
   xzlen = it.len * cos(it.phi);
   dy    = it.len * sin(it.phi);
   dx    = xzlen * cos(it.theta);  
   dz    = xzlen * sin(it.theta);  
   glLineWidth(5.0);
   glBegin(GL_LINES);
      glColor3f(1.0, 0.0, 0.0);
      glVertex3f(it.x,it.y,it.z);
      glColor3f(0.0, 0.0, 1.0);
      glVertex3f(it.x+dx,it.y+dy,it.z+dz);
   glEnd();
   glFlush();
   glutSwapBuffers();
}
void animate()
{
   it.x += it.vx;
   it.y += it.vy;
   it.z += it.vz;
   glutPostRedisplay();
}
void keyboard(unsigned char c, int x, int y)
{
   fprintf(stderr,"%3d%6d%6d\n", c, x, y);
   switch(c){
     case 'r':
        init();
        break;
     case 'w':
        accelerate(0.001);
        break;
     case 27: exit(0);
   }
   glutPostRedisplay();
}
void mouse(int bno, int state, int x, int y)
{
   fprintf(stderr,"%3d%3d%6d%6d\n", bno, state, x, y);
}
void motion(int x, int y)
{
   fprintf(stderr,"%6d%6d\n", x, y);
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_UP   : it.phi += 0.1;   break;  
     case GLUT_KEY_DOWN : it.phi -= 0.1;   break;
     case GLUT_KEY_RIGHT: it.theta -= 0.1; break;
     case GLUT_KEY_LEFT : it.theta += 0.1; break;
   }
   glutPostRedisplay();
}
