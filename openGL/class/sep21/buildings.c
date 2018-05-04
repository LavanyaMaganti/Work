#include <stdio.h>
#include <stdlib.h>
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



#define GRIDUNIT   1.0
#define XMAP       5
#define ZMAP       5



#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define CHUNK   4096

#define NB      1024      // number of buildings
#define MINHGT     1.0
#define MAXHGT     3.0


int map[XMAP][ZMAP]={
 { 1,1,1,1,1},
  { 1,0,1,0,1},
   { 1,1,1,1,1},
    { 1,0,1,0,1},
     { 1,1,1,1,1}
     };
     

/*typedef struct eye {
   double x,y,z;                // location of the viewer
   double dx,dy,dz;             // direction the viewer is looking
   double theta,phi;            // theta is rotation of head, phi is the elevation
} EYE;
*/

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


GLfloat lightpos[] = {1.5,8.0, 1.5};

GLfloat bulambi[] = {0.0, 0.8, 0.0, 1.0};
GLfloat buldiff[] = {1.0, 1.0, 1.0, 1.0};
GLfloat bulspec[] = {1.0, 1.0, 1.0, 1.0};

GLfloat roadambi[] = {1.0, 1.0, 0.0, 0.0};
GLfloat roaddiff[] = {1.0, 1.0, 1.0, 0.0};
GLfloat roadspec[] = {1.0, 1.0, 1.0, 0.0};

GLfloat sunambi[] = {1.0, 0.5, 0.0, 1.0};
GLfloat sundiff[] = {1.0, 1.0, 1.0, 1.0};
GLfloat sunspec[] = {1.0, 1.0, 1.0, 1.0};

EYE eye;

double bhgt[NB];
int bctr = 0;

void init(char *fname);
void initlight();
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


/*void setdirection()
{
   eye.dx = cos(eye.phi)*cos(eye.theta);
   eye.dz = cos(eye.phi)*sin(eye.theta);
   eye.dy = sin(eye.phi);
}
*/
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

/*  eye.x  =    0.0;
  eye.y  =    2.0;
  eye.z  =  -10.0;

  eye.theta = DEG2RAD(90.0);
  eye.phi   = 0.0;
  setdirection();
*/
eye.x =  2.5;
eye.y =  0.1;
eye.z =  2.5;

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
}


void drawbuilding(double hgt)
{
  int i;

  glPushMatrix();
  glScalef(1.0, hgt, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glVertex3f(0,1,1);
    glVertex3f(0,0,1);
    glVertex3f(1,0,1);
    glVertex3f(1,1,1);
    glVertex3f(1,1,0);
    glVertex3f(1,0,0);
 // glEnd();
 // glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glVertex3f(1,0,0);
    glVertex3f(1,0,1);
    glVertex3f(0,1,0);
    glVertex3f(1,1,0);
    glVertex3f(0,1,1);
    glVertex3f(1,1,1);
  glEnd();
  glPopMatrix();

}

/*void drawdoor() {  
  glPushMatrix();
  glBegin(GL_POLYGON);
  glVertex3f(0.2,0,0);
  glVertex3f(0.8,0,0);
  glVertex3f(0.8,0,0);
  glVertex3f(0.8,0.5,0);
  glVertex3f(0.8,0.5,0);
  glVertex3f(0.0,0.5,0);
  glVertex3f(0.0,0.5,0);
  glVertex3f(0.0,0.0,0);

  glEnd();
  glPopMatrix();
}

void drawtower()
{
      glBegin(GL_TRIANGLES);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(1,1,0);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(1,1,1);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(0,1,1);
      glVertex3f(0.5, 1.5, 0.5);   
      glVertex3f(0,1,0);
    glEnd();
}*/




/*void drawroaddash()
{

      glBegin(GL_POLYGON);
      glVertex3f(0,0,3);
      glVertex3f(0,0,3.2);
      glVertex3f(0,0,3.2);
      glVertex3f(1,0,3.2);
      glVertex3f(1,0,3.2);
      glVertex3f(1,0,3);
      glVertex3f(1,0,3);
      glVertex3f(0,0,3);
      glEnd();

}

void drawroad()
{

int i,j;
double x,z=0;

  for(j=0;j<30;j+=8)
   {
   z = (double) j;
    for(i=0;i<10;i+=2)
      {
      x =(double) i;
      glPushMatrix();
      glTranslatef(x,0,0);
      drawroaddash();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(x,0,z);
      drawroaddash();
      glPopMatrix();
      }
    }

}
*/

void drawstreet()
{
  int i;
  double x;

  for(i=0;i<15;i+=4){
    x = (double) i;
    glPushMatrix();
      glTranslatef(x,0,0);
      drawbuilding(bhgt[bctr]);
      bctr++;
    glPopMatrix();
      glPushMatrix();
      glTranslatef(x,0,5.0);
      drawbuilding(bhgt[bctr]);
      bctr++;
      glPopMatrix();
  }
}


void drawblock()
{
   int i;
   
   glColor3f(1.0, 1.0, 0.0);
   drawstreet();
   for(i=0;i<4;i++){
     // if(i%2 ==0){
         glTranslatef(0,0,6);
         drawstreet();
       /*}
     else {
        glTranslatef(0,0,3);
        drawstreet();
      } */
  }
     glColor3f(1.0, 1.0, 0.0);
   drawstreet();

}


void drawground()
{
   glBegin(GL_QUADS);
   glNormal3f( 0.0, 0.0,  0.0);
   glVertex3f(-2.0, 0.0, -1.5);
   glVertex3f(-2.0, 0.0, 20.0);
   glVertex3f(20.0, 0.0, 20.0);
   glVertex3f(20.0, 0.0, -1.5);
   glEnd();
}


void display()
{
/*   double xzlen;
   double dx,dy,dz;
  */
  
  GLfloat xzlen;
  
   glMatrixMode(GL_PROJECTION);

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   gluPerspective(60.0, 4.0/3.0, 1.0, 5000.0);
/*   gluLookAt(eye.x, eye.y, eye.z,eye.x+eye.dx, 
                    eye.y+eye.dy, eye.z+eye.dz,// target = eye position + eye direction
             0.0, 1.0, 0.0);
  */
   
   gluLookAt(eye.x, eye.y, eye.z,
                eye.x+eye.facing.x, eye.y+eye.facing.y, eye.z+eye.facing.z,
                             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);

   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, roadambi);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, roaddiff);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roadspec);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
//   drawroad();
  drawground();
   glPopMatrix();


   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, bulambi);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, buldiff);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bulspec);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
   drawblock();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(lightpos[0],lightpos[1],lightpos[2]);
  glColor3f(1.0, 0.0, 0.0);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sunambi);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sundiff);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sunspec);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
  glutSolidSphere(0.1,12,12);
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

/*
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
}*/


void keyboard(unsigned char c, int x, int y)
{

//   if(bouncing) return;
      switch(c){
         case 'w':
            eye.velocity.x = eye.speed * eye.velocity.x + POWER * eye.orientation.x;
             eye.velocity.y = eye.speed * eye.velocity.y + POWER * eye.orientation.y;
             eye.velocity.z = eye.speed * eye.velocity.z + POWER * eye.orientation.z;
             eye.speed = length(&eye.velocity);
             setangles(&eye.velocity);
             eye.velocity.x /= eye.speed;
             eye.velocity.y /= eye.speed;
             eye.velocity.z /= eye.speed;
             if(eye.speed > MAXSPEED)
                 eye.speed = MAXSPEED;
//             repo();
             break;
        case 's':
            eye.speed = 0;
            break;
        case 'e':
            eye.orientation.theta += 0.1;
            setdirection(&eye.orientation);
            if(eye.faceforward){
               eye.facing.theta = eye.orientation.theta;
               setdirection(&eye.facing);
             }
            break;
        case 'q':
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


void specialkeyboard(int kno, int x, int y)
{
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


void initlight() {

 int i;

 GLfloat amb[] = {0.5, 0.5, 0.5, 1.0};
 GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
 GLfloat spe[] = {1.0, 1.0, 1.0, 1.0};

 glEnable(GL_LIGHTING); 
 glEnable(GL_LIGHT0); 

 glLightfv(GL_LIGHT0, GL_AMBIENT,  amb);
 glLightfv(GL_LIGHT0, GL_DIFFUSE,  dif);
 glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
 glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

}

