
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define D      0.10
#define ZERO   0.01
#define ONE    0.99

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define NTRI   20000
#define N        100
#define DX         0.01
#define DY         0.01
#define DZ         0.01

#define GRIDUNIT   1.0

typedef struct triangle {
   GLfloat xn,yn,zn;
   GLfloat x1,y1,z1;
   GLfloat x2,y2,z2;
   GLfloat x3,y3,z3;
} TRI;

typedef struct vector {
   GLfloat x,y,z;
   GLfloat theta,phi;
} VEC;

typedef struct eye {
   GLfloat x,y,z;
   VEC facing;
   VEC moving;
} EYE;

GLfloat matamb[] = {0.00, 0.00, 0.00, 1.0};
GLfloat matdif[] = {0.60, 0.60, 0.90, 1.0};
GLfloat matspe[] = {0.50, 0.50, 0.80, 1.0};

GLfloat gndamb[] = {0.10, 0.10, 0.10, 1.0};
GLfloat gnddif[] = {0.50, 0.50, 0.50, 1.0};
GLfloat gndspe[] = {0.10, 0.10, 0.10, 1.0};

GLfloat lightpos[] = {0.5,  5.0, 0.5};

EYE eye;
int bouncing = 0;

TRI tri[NTRI];
GLfloat surface[N+1][N+1];

void init(char *fname);
void initlight();
void display();
void dostuff();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);

   init(argv[1]);

   glutMainLoop();
}
void setdirection(VEC *v)
{
   v->x = cos(v->phi)*cos(v->theta);
   v->z = cos(v->phi)*sin(v->theta);
   v->y = sin(v->phi);
   return;
   fprintf(stderr,"%f  %f  %f\n", v->x, v->y, v->z);
   fprintf(stderr,"%f  %f\n", v->theta, v->phi);
}
GLfloat tweak()
{
   return 0.00002 * (drand48() - 0.5);
}
void makenormal(TRI *p)
{
   GLfloat ux,uy,uz;
   GLfloat vx,vy,vz;
   GLfloat x,y,z,len;

   ux = p->x2 - p->x1;
   uy = p->y2 - p->y1;
   uz = p->z2 - p->z1;

   vx = p->x3 - p->x1;
   vy = p->y3 - p->y1;
   vz = p->z3 - p->z1;

   p->xn = x = uy*vz - uz*vy + tweak();
   p->yn = y = uz*vx - ux*vz + tweak();
   p->zn = z = ux*vy - uy*vz + tweak();
   len = sqrt(x*x+y*y+z*z);
   p->xn /= len;
   p->yn /= len;
   p->zn /= len;
   fprintf(stderr,"%f  %f  %f\n", p->xn, p->yn, p->zn);
}
void makethings()
{
   int i,j,n;
   GLfloat fi,fj,di,dj,r;

   for(i=0;i<=N;i++){
     fi = (double) i/ (double) N;
     di = fabs(fi - 0.5);
     for(j=0;j<=N;j++){
       fj = (double) j/ (double) N;
       dj = fabs(fj - 0.5);
       r = sqrt(di*di + dj*dj);
       surface[i][j] = 0.9 * cos(di*3.3) * cos(dj*3.3);
       if(surface[i][j] < 0.0) surface[i][j] = 0.0;
     }
   }
   n = 0;
   for(i=0;i<N;i++){
     fi = i;
     for(j=0;j<N;j++){
       fj = j;
       tri[n].x1 = fi * DX;
       tri[n].y1 = surface[i][j];
       tri[n].z1 = fj * DZ;
       tri[n].x2 = (fi+1.0) * DX;
       tri[n].y2 = surface[i+1][j];
       tri[n].z2 = fj * DZ;
       tri[n].x3 = (fi+1.0) * DX;
       tri[n].y3 = surface[i+1][j+1];
       tri[n].z3 = (fj+1.0) * DZ;
       makenormal(&tri[n]);
       n++;
       tri[n].x1 = fi * DX;
       tri[n].y1 = surface[i][j];
       tri[n].z1 = fj * DZ;
       tri[n].x3 = (fi+1.0) * DX;
       tri[n].y3 = surface[i+1][j+1];
       tri[n].z3 = (fj+1.0) * DZ;
       tri[n].x2 = fi * DX;
       tri[n].y2 = surface[i][j+1];
       tri[n].z2 = (fj+1.0) * DZ;
       makenormal(&tri[n]);
       n++;
    }
  }
  if(n != NTRI){
    fprintf(stderr,"WTF in makething?\n");
    exit(0);
  }
}
void init(char *fname)
{
  int i;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glShadeModel(GL_FLAT);
  initlight();

  eye.x =  0.5;
  eye.y =  1.0;
  eye.z = -2.5;

  eye.facing.theta = DEG2RAD(90.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);
  eye.moving.theta = DEG2RAD(90.0);
  eye.moving.phi   = 0.0;
  setdirection(&eye.moving);

  srand48(getpid());
  makethings();
}
void drawstuff()
{
  int i;

  glPushMatrix();
  glBegin(GL_TRIANGLES);
    for(i=0;i<NTRI;i++){
      glNormal3f(tri[i].xn, tri[i].yn, tri[i].zn);
      glVertex3f(tri[i].x1, tri[i].y1, tri[i].z1);
      glVertex3f(tri[i].x2, tri[i].y2, tri[i].z2);
      glVertex3f(tri[i].x3, tri[i].y3, tri[i].z3);
    }
  glEnd();
  glPopMatrix();
}
void drawground()
{
   glBegin(GL_QUADS);
     glNormal3f( 0.0, 1.00,  0.0);
     glVertex3f(-1.0, 0.01, -1.0);
     glVertex3f(-1.0, 0.01, 25.0);
     glVertex3f(25.0, 0.01, 25.0);
     glVertex3f(25.0, 0.01, -1.0);
   glEnd();
}
void display()
{
   GLfloat xzlen;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 4.0/3.0, 0.001, 5000.0);
   gluLookAt(eye.x, eye.y, eye.z,
             eye.x+eye.facing.x, eye.y+eye.facing.y, eye.z+eye.facing.z,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
   glPushMatrix();
   glTranslatef(lightpos[0],1.0 + lightpos[1],lightpos[2]);
   glutWireSphere(0.1,12,12);
   glPopMatrix();

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gndamb);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gnddif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gndspe);
   glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
   drawground();

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matamb);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matdif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matspe);
   glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, 90.0);
   drawstuff();

   glPopMatrix();
   glutSwapBuffers();
}
void keyboard(unsigned char c, int x, int y)
{
   GLfloat fx,fy,fz;

   fx = eye.x;
   fy = eye.y;
   fz = eye.z;
   switch(c){
     case 'w':                  // forward motion in the direction viewer is looking
       fx += D * eye.moving.x;
       fy += D * eye.moving.y;
       fz += D * eye.moving.z;
       break;
     case 's':
       fx -= D * eye.moving.x;
       fy -= D * eye.moving.y;
       fz -= D * eye.moving.z;
       break;
     case 'd':
       fx -= D * eye.moving.z;
       fy = eye.y;
       fz += D * eye.moving.x;
       break;
     case 'a':
       fx += D * eye.moving.z;
       fy = eye.y;
       fz -= D * eye.moving.x;
       break;
     case 'x':
       eye.moving = eye.facing;
       break;
     case 't':
       glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
       break;
     case 'f':
       glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
       break;
     case 27:
       exit(0);
   }
   eye.x = fx;
   eye.y = fy;
   eye.z = fz;

   glutPostRedisplay();
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_PAGE_DOWN : eye.y -= 0.1; break;
     case GLUT_KEY_PAGE_UP   : eye.y += 0.1; break;
     case GLUT_KEY_DOWN : eye.facing.phi -= 0.05; break;
     case GLUT_KEY_UP   : eye.facing.phi += 0.05; break;
     case GLUT_KEY_LEFT : eye.facing.theta -= 0.05; break;
     case GLUT_KEY_RIGHT: eye.facing.theta += 0.05; break;
   }
   setdirection(&eye.facing);
   glutPostRedisplay();
}
void initlight()
{
  int i;

  GLfloat amb[] = {0.1, 0.1, 0.1, 1.0};
  GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat spe[] = {1.0, 1.0, 1.0, 1.0};

  glEnable(GL_LIGHTING); 
  glEnable(GL_LIGHT0); 
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

  glLightfv(GL_LIGHT0, GL_AMBIENT,  amb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE,  dif);
  glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
}
