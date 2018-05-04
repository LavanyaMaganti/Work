
#include "main.h"

#define  FLOORFILE     "metal2.ppm"
#define  WALLFILE      "metal5.ppm"
#define  ROOFFILE      "metal2.ppm"

extern GLuint walltex, floortex, rooftex;
extern GLUquadric *wheel, *side1, *side2;

EYE eye;
int bouncing = 0, falling = 0;

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
  eye.y = 10.5;
  eye.z =  2.5;

  eye.facing.theta = DEG2RAD(0.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD(0.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  eye.faceforward = 1;

  srand48(getpid());

  initbuild();

  walltex   = readppm(WALLFILE,1);
  rooftex   = readppm(ROOFFILE,1);
  floortex  = readppm(FLOORFILE,1);

  wheel = gluNewQuadric();
  gluQuadricDrawStyle(wheel,GLU_FILL);
  gluQuadricTexture(wheel, GLU_TRUE);

  side1 = gluNewQuadric();
  gluQuadricDrawStyle(side1,GLU_FILL);
  gluQuadricTexture(side1, GLU_TRUE);

  side2 = gluNewQuadric();
  gluQuadricDrawStyle(side2,GLU_FILL);
  gluQuadricTexture(side2, GLU_TRUE);
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
 
   drawmaze();

   glPopMatrix();
   glutSwapBuffers();
}
void dostuff()
{
   GLfloat tx,ty,tz;

   if(falling){
     eye.y -= EPSILON;
     eye.speed /= 1.1;
     tx = eye.x + eye.speed * eye.velocity.x;
     ty = eye.y + eye.speed * eye.velocity.y;
     tz = eye.z + eye.speed * eye.velocity.z;
     if(cango(tx,ty,tz)){
       eye.x = tx;
       eye.y = ty;
       eye.z = tz;
     }
     falling = canfall(eye.x, eye.y, eye.z);
     glutPostRedisplay();
   } else if(bouncing){
     eye.facing.theta += 0.1 * (drand48() - 0.5);
     eye.facing.phi   += 0.1 * (drand48() - 0.5);
     setdirection(&eye.facing);
     if(bouncing > 0){
       --bouncing;
       if(!bouncing){
         eye.facing.phi   = eye.velocity.phi;
         eye.facing.theta   = eye.velocity.theta;
         setdirection(&eye.facing);
         setdirection(&eye.velocity);
       }
     }
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
         if(canfall(tx,ty,tz)){
           falling = 1;
         }
       } else {
         eye.speed = 0;
         bouncing = 10;
       }
     }
     glutPostRedisplay();
   }
}
