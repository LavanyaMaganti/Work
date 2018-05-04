
#include "main.h"

#define NB       256

#define MINHGT     1.0
#define MAXHGT     2.0

#define XMAP       7
#define ZMAP       7

#define ZERO       0.01
#define ONE        0.99

int map[XMAP][ZMAP]={
 { 1,1,1,1,1,1,1},
 { 1,0,1,0,1,0,1},
 { 1,1,1,1,1,1,1},
 { 1,0,1,0,1,0,1},
 { 1,1,1,1,1,1,1},
 { 1,0,1,0,1,0,1},
 { 1,1,1,1,1,1,1}
};

GLfloat bhgt[NB];
int bctr;

GLuint groundtex, walltex;

void initbuild()
{
  int i;

  for(i=0;i<NB;i++)
    bhgt[i] = MINHGT + (MAXHGT - MINHGT) * drand48();
}
int cango(GLfloat x, GLfloat y, GLfloat z)
{
  int ix,iy,iz;

  if(y > MAXHGT) return 1;
  ix = x;
  iz = z;
  if(ix < 0) return 1;
  if(ix >= XMAP) return 1;
  if(iz < 0) return 1;
  if(iz >= ZMAP) return 1;
  return map[ix][iz];
}
void drawbuilding(GLfloat hgt, int towerflag)
{
  int i;

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, walltex);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,ZERO);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(ONE ,-ZERO,ZERO);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(ONE ,ONE ,ZERO);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(ZERO,ONE ,ZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(ONE ,-ZERO,ZERO);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(ONE ,-ZERO,ONE );
    glTexCoord2f(5.0, 5.0);
    glVertex3f(ONE ,ONE ,ONE );
    glTexCoord2f(0.0, 5.0);
    glVertex3f(ONE ,ONE ,ZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,ONE );
    glTexCoord2f(5.0, 0.0);
    glVertex3f(ONE ,-ZERO,ONE );
    glTexCoord2f(5.0, 5.0);
    glVertex3f(ONE ,ONE ,ONE );
    glTexCoord2f(0.0, 5.0);
    glVertex3f(ZERO,ONE ,ONE );

    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,ZERO);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(ZERO,ONE ,ZERO);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(ZERO,ONE ,ONE );
    glTexCoord2f(0.0, 5.0);
    glVertex3f(ZERO,-ZERO,ONE );
  glEnd();
  glPopMatrix();
}
void drawblock()
{
  int i,j,k;

  bctr = 0;
  glPushMatrix();
  k = 0;
  for(i=1;i<XMAP;i+=2){
    for(j=1;j<ZMAP;j+=2){
      glPushMatrix();
      glTranslatef((GLfloat) i, 0.0, (GLfloat) j);
      drawbuilding(bhgt[k++], 0);
      glPopMatrix();
    }
  }
  glPopMatrix();
}
void drawground()
{
  glBindTexture(GL_TEXTURE_2D, groundtex);
  glBegin(GL_QUADS);
    glTexCoord2f( 0.0, 0.0); glVertex3f(-10.0, 0.0,-10.0);
    glTexCoord2f(96.0, 0.0); glVertex3f( 10.0, 0.0,-10.0);
    glTexCoord2f(96.0,96.0); glVertex3f( 10.0, 0.0, 10.0);
    glTexCoord2f( 0.0,96.0); glVertex3f(-10.0, 0.0, 10.0);
  glEnd();
}
