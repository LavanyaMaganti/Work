
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI)

#define DFILE  "cube.data"
#define MAXLINES  1024

typedef struct thing {
   double x, y, z;     // position
   double vx, vy, vz;  // velocity
   double theta, phi;  // heading (orientation) angles
   double len;
} THING;

typedef struct eye {
   double x,y,z;
} EYE;

typedef struct line {
  double x1,y1,z1;
  double x2,y2,z2;
} LINE;

EYE eye;
THING it;
LINE lines[MAXLINES];
int nlines=0;

void init();
void display();
void readcar();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);

   init();

   glutMainLoop();
}
void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  it.x  = it.y  = it.z  = 0.0; 
  it.vx = it.vy = it.vz = 0.0; 
  it.theta = 0.0;                    // this is used
  it.phi   = 0.0;
  it.len   = 0.25;

  eye.x =  0.0;
  eye.y =  0.1;
  eye.z = -1.0;

  readcar();
}
void drawcar()
{
  int i;

  glPushMatrix();
  glColor3f(1.0,1.0,0.0);          // yellow
  glBegin(GL_LINES);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f( 2.0, 0.0, 0.0);    // x-axis
    glVertex3f(0.0, -2.0, 0.0);
    glVertex3f(0.0,  2.0, 0.0);    // y-axis
    glVertex3f(0.0, 0.0, -2.0);
    glVertex3f(0.0, 0.0,  2.0);    // z-axis
  glEnd();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
    for(i=0;i<nlines;i++){
      glVertex3f(lines[i].x1,lines[i].y1,lines[i].z1);
      glVertex3f(lines[i].x2,lines[i].y2,lines[i].z2);
    }
  glEnd();
  glPopMatrix();
}
void display()
{
   double xzlen;
   double dx,dy,dz;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2.0, 2.0,-2.0, 2.0,-2.0, 2.0);
   gluLookAt(eye.x,eye.y,eye.z,
             0.0, 0.1, 0.0,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glLoadIdentity();
   glTranslatef(it.x, it.y, it.z);
   glRotatef(RAD2DEG(it.theta), 0.0, 1.0, 0.0);
   drawcar();
   glPopMatrix();
   glutSwapBuffers();
}
void keyboard(unsigned char c, int x, int y)
{
   switch(c){
     case 27: exit(0);
   }
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_DOWN : eye.y -= 0.05; break;
     case GLUT_KEY_UP   : eye.y += 0.05; break;
     case GLUT_KEY_LEFT : it.theta += 0.05; break;
     case GLUT_KEY_RIGHT: it.theta -= 0.05; break;
   }
   fprintf(stderr,"eye.y = %lf\n", eye.y);
   glutPostRedisplay();
}
void readcar()
{
  FILE *fd;
  double x1,y1,z1,x2,y2,z2;

  fd = fopen(DFILE,"r");
  nlines = 0;
  while(fscanf(fd,"%lf %lf %lf %lf %lf %lf\n",&x1,&y1,&z1,&x2,&y2,&z2) == 6){
    lines[nlines].x1 = x1;
    lines[nlines].y1 = y1;
    lines[nlines].z1 = z1;
    lines[nlines].x2 = x2;
    lines[nlines].y2 = y2;
    lines[nlines].z2 = z2;
    nlines++;
  }
  fclose(fd);
}
