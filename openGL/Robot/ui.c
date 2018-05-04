
#include "main.h"

extern EYE eye;
extern MONSTER me;

GLfloat length(VEC *v)
{
   GLfloat vx,vy,vz;

   vx = v->x;
   vy = v->y;
   vz = v->z;
   return sqrt(vx*vx+vy*vy+vz*vz);
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
  eye.velocity.phi += delta;
  setdirection(&eye.velocity);
  eye.facing.phi += delta;
  setdirection(&eye.facing);
}
void turndown(GLfloat delta)
{
  eye.velocity.phi -= delta;
  setdirection(&eye.velocity);
  eye.facing.phi -= delta;
  setdirection(&eye.facing);
}
void turnleft(GLfloat delta)
{
  eye.velocity.theta -= delta;
  setdirection(&eye.velocity);
  eye.facing.theta -= delta;
  setdirection(&eye.facing);
}
void turnright(GLfloat delta)
{
  eye.velocity.theta += delta;
  setdirection(&eye.velocity);
  eye.facing.theta += delta;
  setdirection(&eye.facing);
}
void keyboard(unsigned char c, int x, int y)
{
   switch(c){
     case 'w':
       eye.speed += POWER;
       break;
     case 's':
       eye.speed = 0;
       break;
     case 'j':
       me.leftlegangle += 5.0;
       break;
     case 'k':
       me.rightlegangle += 5.0;
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
       turnup(0.1);
       break;
     case GLUT_KEY_DOWN:
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