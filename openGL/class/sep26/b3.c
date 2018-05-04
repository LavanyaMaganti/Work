
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define ZERO   0.01
#define ONE    0.99

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define D          0.1
#define NB      1024      // number of buildings

#define MINHGT     1.0
#define MAXHGT     3.0

#define GRIDUNIT   1.0
#define XMAP       5
#define ZMAP       5

int map[XMAP][ZMAP]={
 { 1,1,1,1,1},
 { 1,0,1,0,1},
 { 1,1,1,1,1},
 { 1,0,1,0,1},
 { 1,1,1,1,1}
};

typedef struct vector {
   double x,y,z;
   double theta,phi;
} VEC;

typedef struct eye {
   double x,y,z;
   VEC facing;
   VEC moving;
} EYE;

GLfloat matamb[] = {0.30, 0.00, 0.00, 1.0};
GLfloat matdif[] = {0.60, 0.00, 0.00, 1.0};
GLfloat matspe[] = {0.80, 0.60, 0.60, 1.0};

GLfloat gndamb[] = {0.20, 0.20, 0.20, 1.0};
GLfloat gnddif[] = {0.90, 0.90, 0.90, 1.0};
GLfloat gndspe[] = {0.10, 0.10, 0.10, 1.0};

GLfloat lightpos[] = {1.5,  3.0, 1.5};

EYE eye;

double bhgt[NB];
int bctr;

void init(char *fname);
void initlight();
void display();
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
   fprintf(stderr,"%lf  %lf  %lf\n", v->x, v->y, v->z);
   fprintf(stderr,"%lf  %lf\n", v->theta, v->phi);
}
void init(char *fname)
{
  int i;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 

  initlight();

  eye.x =  2.5;
  eye.y =  0.1;
  eye.z =  2.5;

  eye.facing.theta = DEG2RAD(90.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);
  eye.moving.theta = DEG2RAD(90.0);
  eye.moving.phi   = 0.0;
  setdirection(&eye.moving);

  srand48(getpid());
  for(i=0;i<NB;i++)
    bhgt[i] = MINHGT + (MAXHGT - MINHGT) * drand48();
  bhgt[0] = 9.0;
}
void drawbuilding(double hgt, int towerflag)
{
  int i;

  glPushMatrix();
//  glFrontFace(GL_CW);
  glScalef(1.0, hgt, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0,0,1);
    glVertex3f(ZERO,ZERO,ZERO);
    glVertex3f(ONE ,ZERO,ZERO);
    glVertex3f(ONE ,ONE ,ZERO);
    glVertex3f(ZERO,ONE ,ZERO);

    glNormal3f(1,0,0);
    glVertex3f(ONE ,ZERO,ZERO);
    glVertex3f(ONE ,ZERO,ONE );
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ONE ,ONE ,ZERO);

    glNormal3f(0,0,1);
    glVertex3f(ZERO,ZERO,ONE );
    glVertex3f(ONE ,ZERO,ONE );
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ZERO,ONE ,ONE );

    glNormal3f(1,0,0);
    glVertex3f(ZERO,ZERO,ZERO);
    glVertex3f(ZERO,ONE ,ZERO);
    glVertex3f(ZERO,ONE ,ONE );
    glVertex3f(ZERO,ZERO,ONE );

    glNormal3f(0,1,0);    // roof
    glVertex3f(ZERO,ONE ,ZERO);
    glVertex3f(ONE ,ONE ,ZERO);
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ZERO,ONE ,ONE );
  glEnd();
#ifdef XYZZY
  if(towerflag){
    glBegin(GL_LINES);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(1,1,0);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(1,1,1);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(0,1,1);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(0,1,0);
    glEnd();
  }
#endif
  glPopMatrix();
}
void drawblock()
{
   int i;

   glPushMatrix();
   glTranslatef(1.0,0.0,1.0);
   drawbuilding(bhgt[0], 1);
   glTranslatef(2.0,0.0,0.0);
   drawbuilding(bhgt[1], 1);
   glTranslatef(0.0,0.0,2.0);
   drawbuilding(bhgt[2], 1);
   glTranslatef(-2.0,0.0,0.0);
   drawbuilding(bhgt[3], 1);
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
   double xzlen;

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
   glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, 10.0);
   bctr = 0;
   drawblock();

   glPopMatrix();
   glutSwapBuffers();
}
int cango(GLfloat x, GLfloat z)
{
  int ix,iz;

  ix = x;
  iz = z;
  if(ix < 0) return 1;
  if(ix >= XMAP) return 1;
  if(iz < 0) return 1;
  if(iz >= ZMAP) return 1;
  return map[ix][iz];
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
     case 27:
       exit(0);
   }
   if(cango(fx,fz)){
     eye.x = fx;
     eye.y = fy;
     eye.z = fz;
   } else {
     fprintf(stderr,"cannot go there.\n");
   }
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
//  glEnable(GL_NORMALIZE);

//  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

  glLightfv(GL_LIGHT0, GL_AMBIENT,  amb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE,  dif);
  glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
}
