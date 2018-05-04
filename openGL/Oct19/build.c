
#include "main.h"

#define NB       256

#define MINHGT     1.0
#define MAXHGT     2.0

#define ZERO       0.00
#define ONE        1.00

#define REP        1.00
#define FEP        2.00

int map[MAP][MAP][MAP];

GLuint walltex, floortex, rooftex;
GLUquadric *wheel, *side1, *side2;

void initbuild()
{
  makemaze();
}
int cango(GLfloat x, GLfloat y, GLfloat z)
{
  int ix,iy,iz;

  ix = x;
  iy = y;
  iz = z;
  if(ix < 0) return 1;
  if(ix >= MAP) return 1;
  if(iy < 0) return 1;
  if(iy >= MAP) return 1;
  if(iz < 0) return 1;
  if(iz >= MAP) return 1;
  fprintf(stderr,"(%d,%d,%d)  %d\n",ix,iy,iz, map[ix][iy][iz]);
  return (map[ix][iy][iz] == 1);
}
int canfall(GLfloat x, GLfloat y, GLfloat z)
{
  int ix,iy,iz;

  ix = x;
  iy = y;
  iz = z;
  if(ix < 0) return 1;
  if(ix >= MAP) return 1;
  if(iy < 0) return 1;
  if(iy >= MAP) return 1;
  if(iz < 0) return 1;
  if(iz >= MAP) return 1;
  if(y - (GLfloat) iy > EPSILON){
    return 1;
  }
  if(map[ix][iy-1][iz] == 1){
    return 1;
  }
  return 0;
}
void drawcube()
{
  int i;

  glPushMatrix();

  glBindTexture(GL_TEXTURE_2D, walltex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0,0,0 );
    glTexCoord2f(REP, 0.0);
    glVertex3f( 1,0,0 );
    glTexCoord2f(REP, REP);
    glVertex3f( 1,1,0 );
    glTexCoord2f(0.0, REP);
    glVertex3f( 0,1,0 );

    glTexCoord2f(0.0, 0.0);
    glVertex3f( 1,0,0 );
    glTexCoord2f(REP, 0.0);
    glVertex3f( 1,0,1 );
    glTexCoord2f(REP, REP);
    glVertex3f( 1,1,1 );
    glTexCoord2f(0.0, REP);
    glVertex3f( 1,1,0 );

    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0,0,1 );
    glTexCoord2f(REP, 0.0);
    glVertex3f( 1,0,1 );
    glTexCoord2f(REP, REP);
    glVertex3f( 1,1,1 );
    glTexCoord2f(0.0, REP);
    glVertex3f( 0,1,1 );

    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0,0,0 );
    glTexCoord2f(0.0, REP);
    glVertex3f( 0,1,0 );
    glTexCoord2f(REP, REP);
    glVertex3f( 0,1,1 );
    glTexCoord2f(REP, 0.0);
    glVertex3f( 0,0,1 );
  glEnd();

  glBindTexture(GL_TEXTURE_2D, floortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0,1,0 );
    glTexCoord2f(FEP, 0.0);
    glVertex3f( 0,1,1);
    glTexCoord2f(FEP, FEP);
    glVertex3f( 1,1,1 );
    glTexCoord2f(0.0, FEP);
    glVertex3f( 1,1,0 );
  glEnd();

//  glBindTexture(GL_TEXTURE_2D, floortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0,0,0 );
    glTexCoord2f(FEP, 0.0);
    glVertex3f( 0,0,1);
    glTexCoord2f(FEP, FEP);
    glVertex3f( 1,0,1 );
    glTexCoord2f(0.0, FEP);
    glVertex3f( 1,0,0 );
  glEnd();
  glPopMatrix();
}
void drawmaze()
{
  int i,j,k,n;

  glPushMatrix();
  for(i=0;i<MAP;i++){
    for(j=0;j<MAP;j++){
      for(k=0;k<MAP;k++){
        if(map[i][j][k] == 1) continue;
        glPushMatrix();
          glTranslatef((GLfloat) i, (GLfloat) j, (GLfloat) k);
          drawcube();
        glPopMatrix();
      }
    }
  }
  glPopMatrix();
}
