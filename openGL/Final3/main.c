
#include "main.h"

#define  FLOORFILE     "PPM/ground1.ppm"
#define  PANELFILE     "PPM/kia.ppm"
#define  HILLSFILE     "PPM/hills.ppm"
#define  BODYFILE      "PPM/metal4.ppm"

GLuint floortex, hillstex, paneltex, badguytex;

MUGR mug;

EYE eye;

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE |  GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(128,64);
   glutCreateWindow("November 21, 2016");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(animate);

   init();

   glutMainLoop();
}
void init()
{
  int i;
  char fname[K];
  unsigned char white[]={255,255,255,255};

  srand48(getpid());

  if(mug_login(&mug, &playerlist, "alice", "aaa") < 0)
    exit(0);

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  floortex = readppm(FLOORFILE,1);
  hillstex = readppm(HILLSFILE,1);
  paneltex = readtransppm(PANELFILE,1);
  badguytex = readppm(BODYFILE,1);

  eye.x =  0.0;
  eye.y =  0.0;
  eye.z =  0.0;

  eye.hgt = INIT_HGT;

  eye.facing.theta = DEG2RAD( 0.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD( 0.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);
}
void display()
{
   int i;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, 4.0/3.0, 0.001, 5000.0);
   gluLookAt(eye.x, eye.y + eye.hgt, eye.z,
             eye.x+eye.facing.x, eye.y + eye.hgt + eye.facing.y, eye.z+eye.facing.z,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
   drawfloor();
   drawhills();
//   drawme();
   glPopMatrix();
   glutSwapBuffers();
}
void animate()
{
  GLfloat tx,ty,tz;
  int i,j,k;
  static int tick = 0;

  if(eye.speed > 0){
    eye.speed *= FRICTION;
    tx = eye.x + eye.speed * eye.velocity.x;
    ty = eye.y; // + eye.speed * eye.velocity.y;
    tz = eye.z + eye.speed * eye.velocity.z;
    eye.x = tx;
    eye.y = ty;
    eye.z = tz;
  }
  if(tick == 0){
    mug.pos.x = eye.x;
    mug.pos.y = eye.y;
    mug.pos.z = eye.z;
    mug.pos.h = eye.facing.theta;
    mug_report(&mug);
  } else {
    k = mug_update(&playerlist);
    fprintf(stderr,"%d players\n", k);
    for(i=0;i<k;i++){
      drawplayer(&playerlist[i]);
    }
  }
  tick = 1 - tick;
  glutPostRedisplay();
}
