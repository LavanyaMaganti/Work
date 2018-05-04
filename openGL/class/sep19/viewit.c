
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define CHUNK   4096

#define D  10.0

typedef struct eye {
   double x,y,z;                // location of the viewer
   double dx,dy,dz;             // direction the viewer is looking
   double theta,phi;            // theta is rotation of head, phi is the elevation
} EYE;

typedef struct point {
  double x,y,z;
} POINT;

typedef struct pointlist {
  POINT *li;
  int n;
} POINTLIST;

typedef struct line {
  int p1,p2;
} LINE;

typedef struct ll {
  LINE *li;
  int n;
  int size;
} LINELIST;

EYE eye;
POINTLIST pl;
LINELIST ll;

void init(char *fname);
void readcar(char *fname);
void display();
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

   init(argv[1]);

   glutMainLoop();
}
void init(char *fname)
{
  glClearColor(0.0, 0.0, 0.0, 1.0);

  eye.x  =    0.0;
  eye.y  =    0.0;
  eye.z  = -100.0;

  eye.dx =    0.0;
  eye.dy =    0.0;
  eye.dz = -100.0;

  eye.theta = 0.0;
  eye.phi   = 0.0;

  readcar(fname);
}
void drawcar()
{
  int i;
  int p1,p2;

  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
    for(i=0;i<ll.n;i++){
      p1 = ll.li[i].p1;
      p2 = ll.li[i].p2;
// next 4 lines pertain to determining the location of the blade of the chopper
      if(pl.li[p1].y > 23.0 && pl.li[p2].y > 23.0 && pl.li[p1].z < 150.0)
        glColor3f(0.0,1.0,0.0);
      else
        glColor3f(1.0,0.0,0.0);
      glVertex3f(pl.li[p1].x,pl.li[p1].y,pl.li[p1].z);
      glVertex3f(pl.li[p2].x,pl.li[p2].y,pl.li[p2].z);
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
   gluPerspective(60.0, 4.0/3.0, 1.0, 5000.0);
   gluLookAt(eye.x, eye.y, eye.z,
             eye.x+eye.dx, eye.y+eye.dy, eye.z+eye.dz,  // target = eye position + eye direction
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glLoadIdentity();
   glBegin(GL_LINES);
     glColor3f(1.0,1.0,0.0);                // yellow
     glVertex3f(   0.0,    0.0,    0.0);
     glVertex3f(2000.0,    0.0,    0.0);    // x-axis
     glColor3f(0.0,1.0,0.0);
     glVertex3f(   0.0,    0.0,    0.0);
     glVertex3f(   0.0, 2000.0,    0.0);    // y-axis
     glColor3f(0.0,0.0,1.0);
     glVertex3f(   0.0,    0.0,    0.0);
     glVertex3f(   0.0,    0.0, 2000.0);    // z-axis
   glEnd();
   drawcar();
   glPopMatrix();
   glutSwapBuffers();
}
void keyboard(unsigned char c, int x, int y)
{
   switch(c){
     case 'w':                  // forward motion in the direction viewer is looking
       eye.x += D * eye.dx;
       eye.y += D * eye.dy;
       eye.z += D * eye.dz;
       break;
     case 's':
       eye.x -= D * eye.dx;
       eye.y -= D * eye.dy;
       eye.z -= D * eye.dz;
       break;
     case 27:
       exit(0);
   }
   glutPostRedisplay();
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_PAGE_DOWN : eye.y -= 1.0; break;
     case GLUT_KEY_PAGE_UP   : eye.y += 1.0; break;
     case GLUT_KEY_DOWN : eye.phi -= 0.05; break;
     case GLUT_KEY_UP   : eye.phi += 0.05; break;
     case GLUT_KEY_LEFT : eye.theta -= 0.05; break;
     case GLUT_KEY_RIGHT: eye.theta += 0.05; break;
   }
   eye.dx = cos(eye.phi)*cos(eye.theta);
   eye.dz = cos(eye.phi)*sin(eye.theta);
   eye.dy = sin(eye.phi);
   fprintf(stderr,"%lf  %lf  %lf\n", eye.x, eye.y, eye.z);
   fprintf(stderr,"%lf  %lf  %lf\n", eye.dx, eye.dy, eye.dz);
   fprintf(stderr,"%lf  %lf\n", eye.theta, eye.phi);
   glutPostRedisplay();
}
void readcar(char *fname)
{
  FILE *fd;
  int i,n;
  int p1,p2;
  double x1,y1,z1;

  fd = fopen(fname,"r");
  if(!fd){
    fprintf(stderr,"unable to open %s\n", fname);
    exit(0);
  }
  fscanf(fd,"%d", &n);    // read number of points
  pl.n = n;
  pl.li = malloc(n * sizeof(POINT));
  for(i=0;i<n;i++){
    fscanf(fd,"%lf  %lf  %lf", &x1, &y1, &z1);    // should check return value
    pl.li[i].x = x1;
    pl.li[i].y = z1;      // notice that y and z were switched
    pl.li[i].z = y1;
  }
  ll.n = 0;
  ll.size = CHUNK;
  ll.li = malloc(ll.size * sizeof(LINE));
  while(fscanf(fd,"%d %d", &p1, &p2) == 2){
    if(ll.n >= ll.size){
      ll.size += CHUNK;
      ll.li = realloc(ll.li, ll.size * sizeof(LINE));
    }
    ll.li[ll.n].p1 = p1;
    ll.li[ll.n].p2 = p2;
    ll.n++;
  }
  fclose(fd);
}
