
#include "main.h"

#define WALLFILE   "blue-brick.ppm"
#define GROUNDFILE "floor.ppm"
#define WINDOWFILE "color-brick.ppm"

extern GLuint groundtex, walltex, windowtex;

EYE eye;
int bouncing = 0;

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
   glutMotionFunc(mousemotion);
//   glutPassiveMotionFunc(mousemotion);

   init(argv[1]);

   glutMainLoop();
}
void repo()
{
  fprintf(stderr,"speed = %f\n", eye.speed);
  fprintf(stderr,"facing:   %9.2f %9.2f %9.2f\n",
    eye.facing.x, eye.facing.z, eye.facing.theta);
  fprintf(stderr,"velocity: %9.2f %9.2f %9.2f\n",
    eye.velocity.x, eye.velocity.z, eye.velocity.theta);
}
void init(char *fname)
{
  int i;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);

  eye.x =  2.5;
  eye.y =  0.1;
  eye.z =  2.5;

  eye.facing.theta = DEG2RAD(90.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD(90.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  eye.faceforward = 1;

  srand48(getpid());

  initbuild();

  groundtex = readppm(GROUNDFILE,1);
  walltex = readppm(WALLFILE,1);
  windowtex = readppm(WINDOWFILE,1);
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
 
   drawground();
   drawblock();

   glPopMatrix();
   glutSwapBuffers();
}
void dostuff()
{
   GLfloat tx,ty,tz;

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
       if(cango(tx,ty,tz)){
         eye.x = tx;
         eye.y = ty;
         eye.z = tz;
       } else {
         eye.speed = 0;
         bouncing = 60;
       }
       glutPostRedisplay();
     }
   }
}
