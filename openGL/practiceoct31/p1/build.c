
#include "main.h"

GLuint floortex,archtex,archtex2;

int map[MAP][MAP];

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
    glBindTexture(GL_TEXTURE_2D,archtex);
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
    glBindTexture(GL_TEXTURE_2D,archtex);
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
    glBindTexture(GL_TEXTURE_2D,archtex2);
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

/*
void arch()
{

int i,j;
for(i=0;i<MAP;i++) {
for(j=0;j<MAP;j++) {
 if(((i>=5 && i<=6) && (j>=7 && j<=8))||((i>=5 && i<=6)&& (j>=11 && j<=12))) 
{
  map[i][j]=1;
}
else 
  map[i][j]=0;

 printf("%d",map[i][j]);
 }
}
}

int cango(GLfloat x, GLfloat y, GLfloat z)
{
  int ix,iy,iz;

  //if(y > MAXHGT) return 1;
    ix = x;
    iz = z;
    if(ix < 0) return 1;
      if(ix >= MAP) return 1;
        if(iz < 0) return 1;
          if(iz >= MAP) return 1;
  return map[ix][iz];
}
*/
