#include "main.h"
#define WALLFILE1   "windowfile1.ppm"
#define GROUNDFILE "grass-floor.ppm"
#define WALLFILE2 "color-brick.ppm"
#define WINDOWFILE "window.ppm"
#define DOORFILE "door1.ppm"
#define SIDEDOORFILE "sidedoor.ppm"
#define STARFILE "star.ppm"
#define MANHOLEFILE "manhole.ppm"
#define GHOSTFILE "ghost.ppm"
#define INNERWALLFILE "yellowwall.ppm"
#define INNERWALL "inner1.ppm"
#define BUILFLOOR "buildingfloor.ppm"
#define BUILWALL "builwall.ppm"
#define BUILWALL1 "builwall1.ppm"

extern GLuint groundtex, walltex1, walltex2, windowtex,doortex,star,manhole,ghost,inner1,yellowwall,sidedoortex,builfloor,builwall,builwall1;

EYE eye;
int bouncing = 0,current=0;
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
   glutPassiveMotionFunc(mousemotion);

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
glClearColor(0.4, 0.6, 0.7, 1.0);
//  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);

  eye.x =  2.5;
  eye.y =  0.1;
  eye.z =  0.0;

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
  walltex1 = readppm(WALLFILE1,1);
  walltex2 = readppm(WALLFILE2,1);
  doortex = readppm(DOORFILE,1);
  windowtex = readppm(WINDOWFILE,1);
  star = readppm(STARFILE,1);
  manhole = readppm(MANHOLEFILE,1);
  ghost = readppm(GHOSTFILE,1);
  inner1 = readppm(INNERWALL,1);
  yellowwall = readppm(INNERWALLFILE,1);
  sidedoortex = readppm(SIDEDOORFILE,1);
  builfloor = readppm(BUILFLOOR,1);
  builwall = readppm(BUILWALL,1);
  builwall1 = readppm(BUILWALL1,1);
repo();
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
 //  drawground();
 // drawmanhole();
   drawfloor();
   drawblock();
//   drawinnerview();
   glPopMatrix();
   glutSwapBuffers();
}


void starworlddisplay()
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
   drawstarworld();
   glPopMatrix();
   glutSwapBuffers();

}


void manholeworlddisplay()
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
   manholeworld();
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
  if(current==1) {
    starworlddisplay();
    eye.facing.x = -8.0;
    eye.facing.y = -3.0;
    eye.facing.z = 0.0;
    }
    else if(current == 2)
    {
    manholeworlddisplay();
    eye.facing.x = -8.0;
    eye.facing.y = -3.0;
    eye.facing.z = 0.0;
    }
//     glutPostRedisplay();
   } else {
     if(eye.speed > 0){
     fprintf(stderr,"eye.x %lf eye.y %lf  eye.z %lf %d\n",eye.x,eye.y,eye.z,cango(tx,ty,tz));
       eye.speed *= FRICTION;
       tx = eye.x + eye.speed * eye.velocity.x;
       ty = eye.y + eye.speed * eye.velocity.y;
       tz = eye.z + eye.speed * eye.velocity.z;
       if(cango(tx,ty,tz) == 1 || cango(tx,ty,tz) == 8){
         eye.x = tx;
         eye.y = ty;
         fprintf(stderr,"cango: %lf %lf %lf %d",tx,ty,tz,cango(tx,ty,tz));
         eye.z = tz;
       } else if(cango(tx,ty,tz)==14 || cango(tx,ty,tz) == 11 || cango(tx,ty,tz) == 4) {
         fprintf(stderr,"cango: %lf %lf %lf %d",tx,ty,tz,cango(tx,ty,tz));
         eye.speed = 0;
        current = 1;
         bouncing = 60;
       } else if(cango(tx,ty,tz)==0)
       {
         eye.x = tx;
         eye.y = ty;
         eye.z = tz;
         eye.speed = 0;
         fprintf(stderr,"cango: %lf %lf %lf %d",tx,ty,tz,cango(tx,ty,tz));
         bouncing = 60;
        current = 2;
       }
       glutPostRedisplay();
     }
   }
/*    if((eye.facing.x == 0.8  && eye.facing.y == 0.0 && eye.facing.z==0.0)|| (eye.facing.x == 1.0 && eye.facing.y==0.0 && eye.facing.z==0.0) || (eye.facing.x == 1.0 && 
    eye.facing.y==0.0 && eye.facing.z==0.2) || (eye.facing.x == 0.8 && eye.facing.y==0.0 && eye.facing.z == 0.2))
    {
      manholeworlddisplay();
    eye.facing.x = -8.0;
    eye.facing.y = -3.0;
    eye.facing.z = 0.0;
      
    }*/
}
