
#include "main.h"

extern EYE eye;
//extern int wizard;
extern int win1,win2;
extern MISSILE miss;
extern unsigned int missileflag;
extern unsigned int kaboomflag;
extern int wizard;

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
  eye.facing.phi += delta;
  fprintf(stderr,"%f\n", eye.facing.phi);
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
void keyboard(unsigned char c, int x, int y)
{
   int i;

   switch(c){
     case 'w':
       eye.velocity = eye.facing;
       eye.speed += POWER;
       if(eye.speed > MAXSPEED)
         eye.speed = MAXSPEED;
       break;
     case 's':
       eye.speed = 0;
       break;
     case 'x':
       missileflag = 0;
       kaboomflag = 1;
       make_kaboom(miss.x,miss.y + miss.vy,miss.z);
       break;
     case ' ':
       firemissile();
       break;
     case 27:
       exit(0);
   }
   glutPostRedisplay();
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_PAGE_UP:
     if(wizard){
         eye.hgt += 0.01;
       }
       break;
     case GLUT_KEY_PAGE_DOWN:
      if(wizard){
         eye.hgt -= 0.01;
       }
       break;
     case GLUT_KEY_UP:
       turnup(0.025);
       break;
     case GLUT_KEY_DOWN:
       turndown(0.025);
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
