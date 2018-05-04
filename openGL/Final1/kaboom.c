
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <math.h>
#include <GL/glut.h>

#define NTJUNK       200

typedef struct tjunktype {
  float coord[3];
  float speed[3];
  float rotaxis[3];         /* Rotation angles around x, y, and z axes */
  float rotspeed[3];
  float color[3];
  float scale[3];
} TJUNK;

/* Globals */

TJUNK maxijunk[NTJUNK];
int timer = 0;                   /* "timer" of the explosion */
float angle = 0.0;              /* camera rotation angle */

GLfloat xx,yy,zz;

void setspeed (GLfloat v[3])
{
  v[0] = (drand48() - 0.5)/2.0;
  v[1] = (drand48()/2.0);
  v[2] = (drand48() - 0.5)/2.0;
}
void make_kaboom(GLfloat x, GLfloat y, GLfloat z)
{
  int i;

  xx = x; yy = y; zz = z;
  memset(maxijunk,0,NTJUNK*sizeof(TJUNK));
  for (i = 0; i < NTJUNK; i++) {
    maxijunk[i].color[0] = 0.90 + drand48()/10.0;
    maxijunk[i].color[1] = (lrand48() & 3) * 0.25;
    maxijunk[i].color[2] = drand48()/5.0;
    maxijunk[i].scale[0] = 0.4 * drand48() - 0.1;
    maxijunk[i].scale[1] = 0.4 * drand48() - 0.1;
    maxijunk[i].scale[2] = 0.4 * drand48() - 0.1;
    setspeed (maxijunk[i].speed);
    setspeed (maxijunk[i].rotspeed);
  }
  timer = 180;  // 3 seconds?
}
int kaboom()
{
  int i;

  if(timer <= 0)
    return 0;
  glPushMatrix ();
  glTranslatef(xx,yy,zz);

  glNormal3f (0.0, 0.0, 1.0);
  for(i = 0; i < NTJUNK; i++) {
    glColor3fv(maxijunk[i].color);
    glPushMatrix();
    glTranslatef(maxijunk[i].coord[0],
                  maxijunk[i].coord[1], maxijunk[i].coord[2]);
    glRotatef(maxijunk[i].rotaxis[0], 1.0, 0.0, 0.0);
    glRotatef(maxijunk[i].rotaxis[1], 0.0, 1.0, 0.0);
    glRotatef(maxijunk[i].rotaxis[2], 0.0, 0.0, 1.0);
    glScalef(maxijunk[i].scale[0], maxijunk[i].scale[1], maxijunk[i].scale[2]);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(-0.25, 0.0, 0.0);
    glVertex3f(0.25, 0.0, 0.0);
    glEnd();
    glPopMatrix();
  }
  glPopMatrix();
  glColor3f(1,1,1);
  return 1;
}
int animate_kaboom()
{
  int i;

  if(timer > 0){
    for(i = 0; i < NTJUNK; i++) {
      maxijunk[i].coord[0] += maxijunk[i].speed[0] * 0.1;
      maxijunk[i].coord[1] += maxijunk[i].speed[1] * 0.1;
      maxijunk[i].coord[2] += maxijunk[i].speed[2] * 0.1;

      maxijunk[i].rotaxis[0] += maxijunk[i].rotspeed[0] * 15;
      maxijunk[i].rotaxis[1] += maxijunk[i].rotspeed[1] * 15;
      maxijunk[i].rotaxis[2] += maxijunk[i].rotspeed[2] * 15;
    }
    --timer;
  }
  return (timer > 0);
}
