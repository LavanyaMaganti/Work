
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define MAXSPEED   (1.0/60.0)
#define FRICTION   0.999
#define POWER      0.01

#define ZERO       0.01
#define ONE        0.99

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)


#define NB      1024      // number of buildings

#define MINHGT     1.0
#define MAXHGT     3.0
#define GRIDUNIT   1.0
#define XMAP       20
#define ZMAP       20

int map[XMAP][ZMAP]={
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 0,1,0,1,0,1,0,1,0,1,0,1,0},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 0,1,0,1,0,1,0,1,0,1,0,1,0},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 0,1,0,1,0,1,0,1,0,1,0,1,0},
};

typedef struct vector {
   GLfloat x,y,z;
   GLfloat theta,phi;
} VEC;

typedef struct eye {
   int faceforward;
   GLfloat x,y,z;
   GLfloat speed;
   VEC facing;          // direction "pilot" is looking
   VEC velocity;        // direction "ship" is moving
   VEC orientation;     // direction "ship" is pointing
} EYE;

GLfloat matamb[] = {0.0, 0.00, 1.00, 1.0};
GLfloat matdif[] = {0.60, 0.00, 0.00, 1.0};
GLfloat matspe[] = {0.80, 0.60, 0.60, 1.0};

GLfloat gndamb[] = {0.0, 1.0, 0.0, 1.0};
GLfloat gnddif[] = {0.0, 1.0, 0.0, 1.0};
GLfloat gndspe[] = {0.0, 1.0, 0.0, 1.0};

GLfloat sunambi[] = {1.0, 0.1, 0.0, 1.0};
GLfloat sundiff[] = {1.0, 1.0, 0.0, 1.0};
GLfloat sunspec[] = {1.0, 0.0, 0.0, 1.0};


GLfloat lightpos[] = {1.5,  10.0, 1.5};

EYE eye;
int bouncing = 0;

GLfloat bhgt[NB];
int bctr;

void init(char *fname);
void initlight();
void display();
void dostuff();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);
void repo();
int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");
   glRotatef(15,eye.facing.x,eye.facing.y,eye.facing.z);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(dostuff);

   init(argv[1]);

   glutMainLoop();
}
GLfloat length(VEC *v)
{
   GLfloat vx,vz;

   vx = v->x;
   vz = v->z;
   return sqrt(vx*vx+vz*vz);
}
void setdirection(VEC *v)
{
   v->x = cos(v->phi)*cos(v->theta);
   v->z = cos(v->phi)*sin(v->theta);
   v->y = sin(v->phi);
}
void setangles(VEC *v)
{
   GLfloat vx,vz,r;

   r = length(v);
   if(r > 0.0)
     v->theta = acosf(v->x/r);
}
void init(char *fname)
{
  int i;

  glClearColor(0.4, 0.6, 0.7, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 

  initlight();

  eye.x =  2.0;
  eye.y =  3.0;
  eye.z =  5.0;

  eye.facing.theta = DEG2RAD(90.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.orientation.theta = DEG2RAD(90.0);
  eye.orientation.phi   = 0.0;
  setdirection(&eye.orientation);

  eye.velocity.theta = DEG2RAD(90.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  eye.faceforward = 1;    /* always look where you're going */

  srand48(getpid());
  for(i=0;i<NB;i++)
    bhgt[i] = MINHGT + (MAXHGT - MINHGT) * drand48();
  bhgt[0] = 9.0;
}
void drawbuilding(GLfloat hgt)
{
  int i;

  glPushMatrix();
//  glFrontFace(GL_CW);
  glScalef(1.0, hgt, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0,0,1);
    glVertex3f(ZERO,-ZERO,ZERO);
    glVertex3f(ONE ,-ZERO,ZERO);
    glVertex3f(ONE ,ONE ,ZERO);
    glVertex3f(ZERO,ONE ,ZERO);

    glNormal3f(1,0,0);
    glVertex3f(ONE ,-ZERO,ZERO);
    glVertex3f(ONE ,-ZERO,ONE );
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ONE ,ONE ,ZERO);

    glNormal3f(0,0,1);
    glVertex3f(ZERO,-ZERO,ONE );
    glVertex3f(ONE ,-ZERO,ONE );
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ZERO,ONE ,ONE );

    glNormal3f(1,0,0);
    glVertex3f(ZERO,-ZERO,ZERO);
    glVertex3f(ZERO,ONE ,ZERO);
    glVertex3f(ZERO,ONE ,ONE );
    glVertex3f(ZERO,-ZERO,ONE );

    glNormal3f(0,1,0);    // roof
    glVertex3f(ZERO,ONE ,ZERO);
    glVertex3f(ONE ,ONE ,ZERO);
    glVertex3f(ONE ,ONE ,ONE );
    glVertex3f(ZERO,ONE ,ONE );
  glEnd();
  glPopMatrix();
}


void drawblock()
{
  int i;
  double x,z;

 for(i=0;i<15;i+=2){
    x = (double) i;
    z = (double) i;
    glPushMatrix();
    glTranslatef(x,0,0);
    drawbuilding(bhgt[bctr]);
    bctr++;
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x,0,5);
    drawbuilding(bhgt[bctr]);
    bctr++;
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x,0,10);
    drawbuilding(bhgt[bctr]);
    bctr++;
    glPopMatrix();
 }
}

void drawground()
{
   glBegin(GL_QUADS);
     glVertex3f(-1.0, 0.0, -1.0);
     glVertex3f(-1.0, 0.0, 15.0);
     glVertex3f(15.0, 0.0, 15.0);
     glVertex3f(15.0, 0.0, -1.0);
   glEnd();
}

void frontwall()
{
   glBegin(GL_POLYGON);
     glVertex3f(-1.0, 0.0, -1.0);
     glVertex3f(15.0, 0.0, -1.0);
     glVertex3f(15.0, 1.0, -1.0);
     glVertex3f(-1.0, 1.0, -1.0);
   glEnd();

}
void sidewall()
{
    glBegin(GL_QUADS);
      glVertex3f(15.0,0.0,15.0);
      glVertex3f(15.0,1.0,15.0);
      glVertex3f(15.0,1.0,-1.0);
      glVertex3f(15.0,0.0,-1.0);

      glVertex3f(-1.0,0.0,-1.0);
      glVertex3f(-1.0,1.0,-1.0);
      glVertex3f(-1.0,1.0,15.0);
      glVertex3f(-1.0,0.0,15.0);
    glEnd();
}
void drawwall()
{
    glPushMatrix();
    sidewall();
    frontwall();
    glTranslatef(0.0,0.0,16.0);
    frontwall();
  glPopMatrix();
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
   drawwall();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(lightpos[0],lightpos[1],lightpos[2]);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sunambi);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sundiff);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sunspec);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
   glutSolidSphere(0.5,12,12);
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

   if(bouncing) return;
   switch(c){
     case 'w':
       eye.velocity.x = eye.speed * eye.velocity.x + POWER * eye.orientation.x;
       eye.velocity.y = eye.speed * eye.velocity.y + POWER * eye.orientation.y;
       eye.velocity.z = eye.speed * eye.velocity.z + POWER * eye.orientation.z;
       eye.speed = length(&eye.velocity);
       setangles(&eye.orientation);
/*       eye.velocity.x /= eye.speed;
       eye.velocity.y /= eye.speed;
       eye.velocity.z /= eye.speed;
  */
  
  eye.velocity.x = eye.facing.x;
  eye.velocity.y = eye.facing.y;
  eye.velocity.z = eye.facing.z;
  
  
       if(eye.speed > MAXSPEED)
         eye.speed = MAXSPEED;
       repo();
       break;
     case 's':
       eye.speed = 0;
       break;
     case 'd':
       eye.orientation.theta += 0.1;
       setdirection(&eye.orientation);
       if(eye.faceforward){
         eye.facing.theta = eye.orientation.theta;
         setdirection(&eye.facing);
         eye.velocity.x = eye.facing.x+0.1;
         eye.velocity.x = eye.facing.x+0.1;
         eye.velocity.x = eye.facing.x+0.1;
         
       }
       break;
     case 'a':
       eye.orientation.theta -= 0.1;
       setdirection(&eye.orientation);
       if(eye.faceforward){
         eye.facing.theta = eye.orientation.theta;
         setdirection(&eye.facing);
       }
       break;
     case 27:
       exit(0);
   }
   glutPostRedisplay();
}
void dostuff()
{
   GLfloat tx,ty,tz;   // t = temporary

   if(bouncing){
     eye.facing.theta += 0.1 * (drand48() - 0.5);
     eye.facing.phi   += 0.1 * (drand48() - 0.5);
     setdirection(&eye.facing);
     if(bouncing > 0)
       --bouncing;
     glutPostRedisplay();
   } else {
     if(eye.speed > 0){
       eye.speed *= FRICTION;
       tx = eye.x + eye.speed * eye.velocity.x;
       ty = eye.y + eye.speed * eye.velocity.y;
       tz = eye.z + eye.speed * eye.velocity.z;
       if(cango(tx,tz)){
         eye.x = tx;
         eye.y = ty;
         eye.z = tz;
         fprintf(stderr,"CAN co-ord: %f %f %f\n",eye.x,eye.y,eye.z);

       } else {
         eye.speed = 0;
         bouncing = 60;
         fprintf(stderr,"co-ord: %f %f %f\n",eye.x,eye.y,eye.z);
       }
       glutPostRedisplay();
     }
   }
}
void specialkeyboard(int kno, int x, int y)
{
   if(bouncing) return;
   switch(kno){
     case GLUT_KEY_HOME      : eye.facing = eye.orientation; break;
     case GLUT_KEY_PAGE_DOWN : eye.y -= 0.1; break;
     case GLUT_KEY_PAGE_UP   : eye.y += 0.1; break;
     case GLUT_KEY_DOWN      : eye.facing.phi -= 0.05; break;
     case GLUT_KEY_UP        : eye.facing.phi += 0.05; break;
     case GLUT_KEY_LEFT      : eye.facing.theta -= 0.05; break;
     case GLUT_KEY_RIGHT     : eye.facing.theta += 0.05; break;
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
void repo()
{
  fprintf(stderr,"speed = %f\n", eye.speed);
  fprintf(stderr,"facing:   %9.2f %9.2f %9.2f\n",
    eye.facing.x, eye.facing.z, eye.facing.theta);
  fprintf(stderr,"velocity: %9.2f %9.2f %9.2f\n",
    eye.velocity.x, eye.velocity.z, eye.velocity.theta);
  fprintf(stderr,"orient:   %9.2f %9.2f %9.2f\n",
    eye.orientation.x, eye.orientation.z, eye.orientation.theta);
}
