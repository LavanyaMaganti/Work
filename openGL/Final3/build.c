
#include "main.h"

extern GLuint floortex;
extern GLuint hillstex;

void drawfloor()
{
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, floortex);
    glBegin(GL_QUADS);
      glTexCoord2f(   0.0,   0.0);
      glVertex3f(-50.0,  0.01, -50.0);
      glTexCoord2f( 200.0,   0.0);
      glVertex3f( 50.0,  0.01, -50.0);
      glTexCoord2f( 200.0, 200.0);
      glVertex3f( 50.0,  0.01,  50.0);
      glTexCoord2f(   0.0, 200.0);
      glVertex3f(-50.0,  0.01,  50.0);
    glEnd();
  glPopMatrix();
}

#define BOT  1.0
#define TOP  0.0

void drawhills()
{
  GLfloat e,h,r,z;

  r =  50.0;
  z =  50.0;
  h =  40.0;
  e = -15.0;
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, hillstex);
    glBegin(GL_QUADS);
#ifdef SEAMLESS
      glTexCoord2f( 0.000,  TOP); glVertex3f(-r, h,-z);    /* left */
      glTexCoord2f( 0.000,  BOT); glVertex3f(-r, e,-z);
      glTexCoord2f( 0.250,  BOT); glVertex3f( r, e,-z);
      glTexCoord2f( 0.250,  TOP); glVertex3f( r, h,-z);

      glTexCoord2f( 0.250,  TOP); glVertex3f( r, h,-z);    /* front */
      glTexCoord2f( 0.250,  BOT); glVertex3f( r, e,-z);
      glTexCoord2f( 0.500,  BOT); glVertex3f( r, e, z);
      glTexCoord2f( 0.500,  TOP); glVertex3f( r, h, z);

      glTexCoord2f( 0.500,  TOP); glVertex3f( r, h, z);    /* right */
      glTexCoord2f( 0.500,  BOT); glVertex3f( r, e, z);
      glTexCoord2f( 0.750,  BOT); glVertex3f(-r, e, z);
      glTexCoord2f( 0.750,  TOP); glVertex3f(-r, h, z);

      glTexCoord2f( 0.750,  TOP); glVertex3f(-r, h, z);    /* back */
      glTexCoord2f( 0.750,  BOT); glVertex3f(-r, e, z);
      glTexCoord2f( 1.000,  BOT); glVertex3f(-r, e,-z);
      glTexCoord2f( 1.000,  TOP); glVertex3f(-r, h,-z);
#else
      glTexCoord2f( 0.000,  TOP); glVertex3f(-r, h,-z);    /* left */
      glTexCoord2f( 0.000,  BOT); glVertex3f(-r, e,-z);
      glTexCoord2f( 1.000,  BOT); glVertex3f( r, e,-z);
      glTexCoord2f( 1.000,  TOP); glVertex3f( r, h,-z);

      glTexCoord2f( 1.000,  TOP); glVertex3f( r, h,-z);    /* front */
      glTexCoord2f( 1.000,  BOT); glVertex3f( r, e,-z);
      glTexCoord2f( 0.000,  BOT); glVertex3f( r, e, z);
      glTexCoord2f( 0.000,  TOP); glVertex3f( r, h, z);

      glTexCoord2f( 0.000,  TOP); glVertex3f( r, h, z);    /* right */
      glTexCoord2f( 0.000,  BOT); glVertex3f( r, e, z);
      glTexCoord2f( 1.000,  BOT); glVertex3f(-r, e, z);
      glTexCoord2f( 1.000,  TOP); glVertex3f(-r, h, z);

      glTexCoord2f( 1.000,  TOP); glVertex3f(-r, h, z);    /* back */
      glTexCoord2f( 1.000,  BOT); glVertex3f(-r, e, z);
      glTexCoord2f( 0.000,  BOT); glVertex3f(-r, e,-z);
      glTexCoord2f( 0.000,  TOP); glVertex3f(-r, h,-z);
#endif
    glEnd();
  glPopMatrix();
}
