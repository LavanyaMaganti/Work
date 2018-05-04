
#include "main.h"

GLUquadric *body, *lleg, *rleg;
GLuint floortex,bodytex;
extern MONSTER me;

GLUquadric *initquadric()
{
  GLUquadric *p;

  p = gluNewQuadric();
  gluQuadricDrawStyle(p,GLU_FILL);
  gluQuadricTexture(p, GLU_TRUE);
  return p;
}
void initme()
{
  body = initquadric();
  lleg = initquadric();
  rleg = initquadric();
}
void drawfloor()
{
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, floortex);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-10.0,  0.01, -10.0);
      glTexCoord2f(40.0,  0.0);
      glVertex3f( 10.0,  0.01, -10.0);
      glTexCoord2f(40.0, 40.0);
      glVertex3f( 10.0,  0.01,  10.0);
      glTexCoord2f( 0.0, 40.0);
      glVertex3f(-10.0,  0.01,  10.0);
    glEnd();
  glPopMatrix();
}
void drawme()
{
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, bodytex);
    glRotatef(-90.0, 1, 0, 0);
    glPushMatrix();
      glTranslatef(0, 0,  me.leglen);
      glRotatef(me.leftlegangle, 1, 0, 0);
      glTranslatef(-1.5*me.legrad, 0.00, -me.leglen);
      gluCylinder(rleg, me.legrad, me.legrad, me.leglen, 16, 16);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0,  me.leglen);
      glRotatef(me.rightlegangle, 1, 0, 0);
      glTranslatef( 1.5*me.legrad, 0.00, -me.leglen);
      gluCylinder(rleg, me.legrad, me.legrad, me.leglen, 16, 16);
    glPopMatrix();
    glPushMatrix();
      glTranslatef( 0.0, 0.0,  me.leglen);
      gluCylinder(body, me.bodyrad, me.bodyrad, me.bodylen, 16, 16);
    glPopMatrix();
  glPopMatrix();
}
