
#include "main.h"

#define BOT  0.900
#define TOP  0.300

extern EYE eye;
extern GLuint paneltex, badguytex;

void drawplayer(MUGR *p)
{
  GLfloat x,y,z,h,e,r;

  glBindTexture(GL_TEXTURE_2D, badguytex);
  glPushMatrix();
  h = 0.1;
  e = 0.0;
  r = 0.1;
  x = p->pos.x;
  z = p->pos.z;
  glTranslatef(x, 0, z);
  glBegin(GL_QUADS);
    glTexCoord2f( 0.125,  TOP); glVertex3f(-r, h,-r);    /* left */
    glTexCoord2f( 0.125,  BOT); glVertex3f(-r, e,-r);
    glTexCoord2f( 0.375,  BOT); glVertex3f( r, e,-r);
    glTexCoord2f( 0.375,  TOP); glVertex3f( r, h,-r);

    glTexCoord2f( 0.375,  TOP); glVertex3f( r, h,-r);    /* front */
    glTexCoord2f( 0.375,  BOT); glVertex3f( r, e,-r);
    glTexCoord2f( 0.625,  BOT); glVertex3f( r, e, r);
    glTexCoord2f( 0.625,  TOP); glVertex3f( r, h, r);

    glTexCoord2f( 0.625,  TOP); glVertex3f( r, h, r);    /* right */
    glTexCoord2f( 0.625,  BOT); glVertex3f( r, e, r);
    glTexCoord2f( 0.875,  BOT); glVertex3f(-r, e, r);
    glTexCoord2f( 0.875,  TOP); glVertex3f(-r, h, r);

    glTexCoord2f( 0.875,  TOP); glVertex3f(-r, h, r);    /* back */
    glTexCoord2f( 0.875,  BOT); glVertex3f(-r, e, r);
    glTexCoord2f( 1.125,  BOT); glVertex3f(-r, e,-r);
    glTexCoord2f( 1.125,  TOP); glVertex3f(-r, h,-r);
  glEnd();
  glPopMatrix();
}
void drawbody()
{
  GLfloat e,h,r,z;

  r = 0.25;
  e = 0.01;
  h = 0.25;
  z = 0.25;
  glBindTexture(GL_TEXTURE_2D, paneltex);
  glBegin(GL_QUADS);

    glTexCoord2f( 0.125,  TOP); glVertex3f(-r, h,-z);    /* left */
    glTexCoord2f( 0.125,  BOT); glVertex3f(-r, e,-z);
    glTexCoord2f( 0.375,  BOT); glVertex3f( r, e,-z);
    glTexCoord2f( 0.375,  TOP); glVertex3f( r, h,-z);

    glTexCoord2f( 0.375,  TOP); glVertex3f( r, h,-z);    /* front */
    glTexCoord2f( 0.375,  BOT); glVertex3f( r, e,-z);
    glTexCoord2f( 0.625,  BOT); glVertex3f( r, e, z);
    glTexCoord2f( 0.625,  TOP); glVertex3f( r, h, z);

    glTexCoord2f( 0.625,  TOP); glVertex3f( r, h, z);    /* right */
    glTexCoord2f( 0.625,  BOT); glVertex3f( r, e, z);
    glTexCoord2f( 0.875,  BOT); glVertex3f(-r, e, z);
    glTexCoord2f( 0.875,  TOP); glVertex3f(-r, h, z);

    glTexCoord2f( 0.875,  TOP); glVertex3f(-r, h, z);    /* back */
    glTexCoord2f( 0.875,  BOT); glVertex3f(-r, e, z);
    glTexCoord2f( 1.125,  BOT); glVertex3f(-r, e,-z);
    glTexCoord2f( 1.125,  TOP); glVertex3f(-r, h,-z);

  glEnd();
}
void drawme()
{
  int j,k;

  glPushMatrix();
    glTranslatef(eye.x, eye.y, eye.z);
    glRotatef(-RAD2DEG(eye.velocity.theta), 0, 1, 0);
    drawbody();
  glPopMatrix();
}

