
#include "main.h"

#define  FLOORFILE     "PPM/metal2.ppm"
#define  BODYFILE      "PPM/metal1.ppm"

extern GLuint floortex, bodytex;

EYE eye;
MONSTER me[NMON];

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("Terre Haute");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(animate);

   init(argv[1]);

   glutMainLoop();
}
void init(char *fname)
{
  int i;

  srand48(getpid());

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

  floortex  = readppm(FLOORFILE,1);
  bodytex   = readppm(BODYFILE ,1);

  initall();
}
void display()
{
   int i;

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
   for(i=0;i<NMON;i++)
     drawme(&me[i]);

   glPopMatrix();
   glutSwapBuffers();
}
void animate()
{
  GLfloat tx,ty,tz;
  int i,j,k;

  if(eye.speed > 0){
    eye.speed *= FRICTION;
    tx = eye.x + eye.speed * eye.velocity.x;
    ty = eye.y + eye.speed * eye.velocity.y;
    tz = eye.z + eye.speed * eye.velocity.z;
    eye.x = tx;
    eye.y = ty;
    eye.z = tz;
  }
  movemonsters();
}
