#include "main.h"

extern int eyebouncing,tankbouncing;


extern EYE eye,tank;

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

void turnup(GLfloat delta)
{
  eye.facing.phi += delta;
  setdirection(&eye.facing);
}
void turndown(GLfloat delta)
{
  eye.facing.phi -= delta;
  setdirection(&eye.facing);
}
void turnleft(GLfloat delta)
{
  eye.facing.theta -= delta;
  setdirection(&eye.facing);
}
void turnright(GLfloat delta)
{
  eye.facing.theta += delta;
  setdirection(&eye.facing);
}

void mousemotion(int x, int y)
{
  static int px = -1;

  if(px < 0){
    px = x;
    return;
  }
  if(x < px){
    turnleft(0.01);
    glutPostRedisplay();
  } else if(x > px){
    turnright(0.01);
    glutPostRedisplay();
  }
  px = x;
}


void keyboard(unsigned char c, int x, int y)
{
   int i;
   
      switch(c){
          case 'w':
            eye.velocity = eye.facing;
            eye.speed += POWER;
            break;
          case 's':
            eye.speed = 0;
            break;
          case 27:
             exit(0);
       }
 glutPostRedisplay();
}

void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
        case GLUT_KEY_UP:
         //      eye.hgt += 0.001;
           turnup(0.1);
           break;
        case GLUT_KEY_DOWN:
         //      eye.hgt -= 0.001;
           turndown(0.1);
           break;
        case GLUT_KEY_RIGHT:
           turnright(0.1);
           break;
        case GLUT_KEY_LEFT:
           turnleft(0.1);
           break;
  }
 glutPostRedisplay();
}
