
#include "main.h"

GLuint floortex,archtex,archtex2;

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



void drawarch()
{
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,archtex2);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -3.0,  2.0, 5.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( -2.0,  2.0,  5.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-2.0,  0.01,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -3.0,  0.01, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( -3.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-3.0,  2.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-2.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -2.0,  0.01, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( -2.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-2.0,  2.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,0.01,6.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -3.0,  2.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( -2.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-2.0,  0.01,  6.0);
  
     glEnd();
  glPopMatrix();

  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,archtex2);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(1.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( 1.0,  2.0, 5.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 2.0,  2.0,  5.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(2.0,  0.01,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(1.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( 1.0,  0.01, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 1.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(1.0,  2.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(2.0,0.01,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f(2.0,  0.01, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(2.0, 2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(2.0,  2.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(1.0,0.01,6.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( 1.0,  2.0, 6.0);
        glTexCoord2f(1.0, 2.0);
        glVertex3f( 2.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 2.0);
        glVertex3f(2.0,  0.01,  6.0);
  
     glEnd();
  glPopMatrix();


  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,archtex);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(2.0,2.0,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( 2.0,  3.0, 5.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( -3.0,  3.0,  5.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-3.0,  2.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(2.0,2.0,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( 2.0,  2.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 2.0,  3.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(2.0,  3.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,2.0,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f(-3.0,  2.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-3.0,  3.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(-3.0,  3.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,2.0,6.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -3.0,  3.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 2.0,  3.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(2.0,  2.0,  6.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-3.0,3.0,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -3.0,  3.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 2.0,  3.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(2.0,  3.0,  5.0);


        glTexCoord2f(0.0,0.0);
        glVertex3f(-2.0,2.0,5.0);
        glTexCoord2f(1.0,  0.0);
        glVertex3f( -2.0,  2.0, 6.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 1.0,  2.0,  6.0);
        glTexCoord2f( 0.0, 1.0);
        glVertex3f(1.0,  2.0,  5.0);
  
     glEnd();
  glPopMatrix();

}
