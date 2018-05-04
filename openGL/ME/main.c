
#include "main.h"

#define  FLOORFILE     "floor1.ppm"
#define  BODYFILE      "body4.ppm"

extern GLuint floortex, bodytex;

EYE eye;
MONSTER me = {
  0.05, 0.02,
  0.20, 0.20,
  0.00, 0.00, 0.00,
  0.00, 0.00, 0.00,
  0.00
};

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
   glutIdleFunc(dostuff);

   init(argv[1]);

   glutMainLoop();
}
void init(char *fname)
{

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);

  eye.x =  0.0;
  eye.y =  0.0;
  eye.z =  2.0;

  eye.facing.theta = DEG2RAD(270.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD(270.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  srand48(getpid());

  initme();

  floortex  = readppm(FLOORFILE,1);
  bodytex   = readppm(BODYFILE,1);
}
void display()
{
   GLfloat xzlen;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 4.0/3.0, 0.001, 5000.0);
   gluLookAt(eye.x, eye.y + HGT, eye.z,
             eye.x+eye.facing.x, eye.y + HGT + eye.facing.y, eye.z+eye.facing.z,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
   drawfloor();
   drawme();

   glPopMatrix();
   glutSwapBuffers();
}
void dostuff()
{
  GLfloat tx,ty,tz;

  if(eye.speed > 0){
    eye.speed *= FRICTION;
    tx = eye.x + eye.speed * eye.velocity.x;
    ty = eye.y + eye.speed * eye.velocity.y;
    tz = eye.z + eye.speed * eye.velocity.z;
    eye.x = tx;
    eye.y = ty;
    eye.z = tz;
  }
  glutPostRedisplay();
}
