
#include "main.h"

GLuint floortex;

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
