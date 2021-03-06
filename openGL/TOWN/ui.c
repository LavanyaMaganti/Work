
#include "main.h"

extern int bouncing;

extern EYE eye;

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

//   fprintf(stderr,"uchar = %3d\n", c);
   if(bouncing) return;
   switch(c){
     case 'w':
       eye.speed += POWER;
       break;
     case 's':
       eye.speed = 0;
       break;
     case 'e':
       turnright(0.1);
       break;
     case 'q':
       turnleft(0.1);
       break;
     case 27:
       exit(0);
   }
   glutPostRedisplay();
}
void specialkeyboard(int kno, int x, int y)
{
  // fprintf(stderr,"kno   = %3d\n", kno);
   if(bouncing) return;
   switch(kno){
     case GLUT_KEY_PAGE_DOWN:
       eye.y -= 0.1;
       break;
     case GLUT_KEY_PAGE_UP:
       eye.y += 0.1;
       break;
     case GLUT_KEY_HOME:
       eye.facing.phi += 0.1;
       setdirection(&eye.facing);
       break;
     case GLUT_KEY_END:
       eye.facing.phi -= 0.1;
       setdirection(&eye.facing);
       break;
     case GLUT_KEY_UP:
       eye.speed += POWER;
       break;
     case GLUT_KEY_DOWN:
       eye.speed = 0.0;
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
