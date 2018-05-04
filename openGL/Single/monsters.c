
#include "main.h"

GLuint bodytex;

extern MONSTER me[];

void initone(int k)
{
  me[k].x       = 5.0 * drand48();
  me[k].y       = 0.0;
  me[k].z       = 5.0 * drand48();
  me[k].heading = 360.0 * drand48();
  me[k].bodylen = 0.10 + 0.10 * drand48();
  me[k].bodywid = 0.10 + 0.10 * drand48();
  me[k].bodyhgt = 0.10 + 0.90 * drand48();
  me[k].speed   = 0.01 + 0.01 * drand48();
  me[k].moving  = 1;
}
void initall()
{
  int i;

  memset(me,0,NMON*sizeof(MONSTER));
  for(i=0;i<NMON;i++)
    initone(i);
}
void drawbody(MONSTER *p)
{
  GLfloat e,h,r,z;

  r = p->bodywid;
  e = 0.02;
  h = p->bodyhgt;
  z = p->bodylen;
  glBindTexture(GL_TEXTURE_2D, bodytex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r, e,-z);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r, e, z);
    glTexCoord2f(1.0,  1.0); glVertex3f( r, e, z);
    glTexCoord2f(1.0,  0.0); glVertex3f( r, e,-z);

    glTexCoord2f(0.0,  0.0); glVertex3f( r, h,-z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, h, z);
    glTexCoord2f(1.0,  1.0); glVertex3f( r, e, z);
    glTexCoord2f(1.0,  0.0); glVertex3f( r, e,-z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, h, z);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, h,-z);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r, e,-z);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r, e, z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, h,-z);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, h, z);
    glTexCoord2f(0.0,  0.0); glVertex3f( r, h, z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, h,-z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, e,-z);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, h,-z);
    glTexCoord2f(0.0,  0.0); glVertex3f( r, h,-z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, e,-z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, e, z);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, h, z);
    glTexCoord2f(0.0,  0.0); glVertex3f( r, h, z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, e, z);
  glEnd();
}
void drawme(MONSTER *p)
{
  int j,k;

  glPushMatrix();
    glTranslatef(p->x, p->y, p->z);
    glRotatef(p->heading, 0, 1, 0);
    drawbody(p);
  glPopMatrix();
}
void movemonsters()
{
  int i;

  for(i=0;i<NMON;i++){ 
    me[i].x += me[i].speed * sin(DEG2RAD(me[i].heading));
    me[i].z += me[i].speed * cos(DEG2RAD(me[i].heading));
    me[i].heading += (drand48() - 0.3);
  }
  glutPostRedisplay();
}
