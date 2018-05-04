#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)


typedef struct eye {
   double x,y,z;                // location of the viewer
   double dx,dy,dz;             // direction the viewer is looking
   double theta,phi;            // theta is rotation of head, phi is the elevation
 } EYE;
         
 
GLfloat lightpos[] = {1.5,  3.0, 1.5};


EYE eye; 

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


void setdirection()
{
   eye.dx = cos(eye.phi)*cos(eye.theta);
   eye.dz = cos(eye.phi)*sin(eye.theta);
   eye.dy = sin(eye.phi);
}


void init(char *fname)
{
  int i;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 

initlight();  
  eye.x  =    0.0;
  eye.y  =    2.0;
  eye.z  =  -10.0;

  eye.theta = DEG2RAD(90.0);
  eye.phi   = 0.0;
  setdirection();

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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  glTranslatef(lightpos[0],lightpos[1],lightpos[2]);
  glColor3f(1.0, 0.0, 0.0);
  glutWireTeapot(5);
//  glutSolidSphere(0.1,12,12);
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
   setdirection();
   glutPostRedisplay();
}


void initlight() {

 int i;

 GLfloat amb[] = {0.1, 0.1, 0.1, 1.0};
 GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
 GLfloat spe[] = {1.0, 1.0, 1.0, 1.0};

 glEnable(GL_LIGHTING); 
 glEnable(GL_LIGHT0); 

 glLightfv(GL_LIGHT0, GL_AMBIENT,  amb);
 glLightfv(GL_LIGHT0, GL_DIFFUSE,  dif);
 glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
 glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

}

