#include "main.h"

#define NB       256

#define MINHGT     1.0
#define MAXHGT     2.0

#define XMAP       11
#define ZMAP       10

#define REP        2.0
#define ZERO       0.0
#define ONE        1.0
#define TWO        2.0
#define THREE      3.0

#define INZERO     0.02
#define INONE      0.08
#define INTWO      1.98 
#define INTHREE    2.98 


int map[XMAP][ZMAP]={
 { 1,1,1, 1,1, 1,1, 1,1,1},
 { 1,14,8,11,1,14,4,11,1,1},
 { 1,1,14,11,1,14,8,11,1,1},
 { 1, 0,1, 1,1, 1,1, 1,1,1},
 { 1,14,8,11,1,14,8,11,1,1},
 { 1,14,4,11,1,14,4,11,1,1},
 { 1, 1,1, 1,1, 1,1, 1,1,1},
 { 1,14,8,11,1,14,8,11,1,1},
 { 0,14,4,11,1,14,4,11,1,1},
 { 1, 1,1, 1,1, 1,1, 1,1,1}
};


/*int map[XMAP][ZMAP]={
 { 1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1},
 { 1,14,8,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,1},
 { 1,1,1,1,1,1,1,1,1,1},
};
*/

/*
int map[XMAP][ZMAP]={
 { 1,1,1,1,1,1,1,1,1,1},
/* { 1,14,4,11,1,14,4,11,1,1},
 { 1,1,1,1,1,1,1,1,1,1,1},
 { 1,14,8,11,1,14,8,11,1,1},
 { 1,1,1,1,1,1,1,1,1,1},
 { 1,14,4,11,1,14,4,11,1,1},
 { 1,14,8,11,1,14,8,11,1,1},
 { 1,1,1,1,1,1,1,1,1,1},
 { 1,14,4,11,1,14,4,11,1,1},
 { 1,14,8,11,1,14,8,11,1,1},

 { 1,1,1,1,1,1,1,1,1,1},
 { 1,1,1,1,1,1,1,1,1,1}
};
*/

GLfloat bhgt[NB];
int bctr,i;
double x;

GLuint groundtex, walltex1, walltex2, windowtex,doortex,star,manhole,ghost,inner1,yellowwall,sidedoortex,builfloor,builwall,builwall1;

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

void drawbuilding(GLfloat hgt, int texflag)
{
  int i;

  glPushMatrix();
  if(texflag)
    glBindTexture(GL_TEXTURE_2D, walltex1);
  else
    glBindTexture(GL_TEXTURE_2D, windowtex);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,ZERO);
    glTexCoord2f(REP, 0.0);
    glVertex3f(THREE ,-ZERO,ZERO);
    glTexCoord2f(REP, REP);
    glVertex3f(THREE ,ONE ,ZERO);
    glTexCoord2f(0.0, REP);
    glVertex3f(ZERO,ONE ,ZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(THREE ,-ZERO,ZERO);
    glTexCoord2f(REP, 0.0);
    glVertex3f(THREE ,-ZERO,TWO );
    glTexCoord2f(REP, REP);
    glVertex3f(THREE ,ONE ,TWO );
    glTexCoord2f(0.0, REP);
    glVertex3f(THREE ,ONE ,ZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,TWO );
    glTexCoord2f(REP, 0.0);
    glVertex3f(THREE ,-ZERO,TWO );
    glTexCoord2f(REP, REP);
    glVertex3f(THREE ,ONE ,TWO );
    glTexCoord2f(0.0, REP);
    glVertex3f(ZERO,ONE ,TWO );

    glTexCoord2f(0.0, 0.0);
    glVertex3f(ZERO,-ZERO,ZERO);
    glTexCoord2f(0.0, REP);
    glVertex3f(ZERO,ONE ,ZERO);
    glTexCoord2f(REP, REP);
    glVertex3f(ZERO,ONE ,TWO );
    glTexCoord2f(REP, 0.0);
    glVertex3f(ZERO,-ZERO,TWO );
  glEnd();

  glPopMatrix();

  glBindTexture(GL_TEXTURE_2D, builwall1);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(INZERO,-ZERO,INZERO);
    glTexCoord2f(ONE, ONE);
    glVertex3f(INTHREE ,-ZERO,INZERO);
    glTexCoord2f(ONE, 0.0);
    glVertex3f(INTHREE ,ONE ,INZERO);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(INZERO,ONE ,INZERO);
glEnd();
glPopMatrix();

  glBindTexture(GL_TEXTURE_2D, builwall);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(INTHREE ,-ZERO,INZERO);
    glTexCoord2f(ONE, ONE);
    glVertex3f(INTHREE ,-ZERO,INTWO );
    glTexCoord2f(ONE, 0.0);
    glVertex3f(INTHREE ,ONE ,INTWO );
    glTexCoord2f(0.0, 0.0);
    glVertex3f(INTHREE ,ONE ,INZERO);
glEnd();
glPopMatrix();

  glBindTexture(GL_TEXTURE_2D, inner1);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(INZERO,-ZERO,INTWO );
    glTexCoord2f(ONE, ONE);
    glVertex3f(INTHREE ,-ZERO,INTWO );
    glTexCoord2f(ONE, 0.0);
    glVertex3f(INTHREE ,ONE ,INTWO );
    glTexCoord2f(0.0, 0.0);
    glVertex3f(INZERO,ONE ,INTWO );
glEnd();
glPopMatrix();

/*  glBindTexture(GL_TEXTURE_2D, builwall1);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(INZERO,-ZERO,INZERO);
    glTexCoord2f(ONE,ONE);
    glVertex3f(INZERO,ONE ,INZERO);
    glTexCoord2f(ONE, 0.0);
    glVertex3f(INZERO,ONE ,INTWO );
    glTexCoord2f(0.0, 0.0);
    glVertex3f(INZERO,-ZERO,INTWO );
  glEnd();
  glPopMatrix();
*/


  glBindTexture(GL_TEXTURE_2D,builfloor);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(ZERO,0.01,ZERO);
    glTexCoord2f(ONE,ONE);
    glVertex3f(ZERO,0.01 ,TWO);
    glTexCoord2f(ONE, 0.0);
    glVertex3f(THREE,0.01 ,TWO );
    glTexCoord2f(0.0, 0.0);
    glVertex3f(THREE,0.01,ZERO );
  glEnd();
  glPopMatrix();

  glBindTexture(GL_TEXTURE_2D,yellowwall);
  glPushMatrix();
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, ONE);
    glVertex3f(ZERO,ONE,ZERO);
    glTexCoord2f(ONE,ONE);
    glVertex3f(ZERO,ONE ,TWO);
    glTexCoord2f(ONE, 0.0);
    glVertex3f(THREE,ONE ,TWO );
    glTexCoord2f(0.0, 0.0);
    glVertex3f(THREE,ONE,ZERO );
  glEnd();
  glPopMatrix();
    

}

void drawblock()
{
  int i,j,k;

  bctr = 0;
  glPushMatrix();
  k = 0;
  for(i=1;i<XMAP;i+=4){
    for(j=2;j<ZMAP;j+=4){
      glPushMatrix();
      glTranslatef((GLfloat) i, 0.0, (GLfloat) j);
      drawbuilding(bhgt[k], k % 2);
      drawdoor();
//      drawmanhole();
//           drawinnerview();
      k++;
      glPopMatrix();
    }
  }
  glPopMatrix();
}
/*
void drawinnerblock()
{
  int i,j,k;
  
    bctr = 0;
    glPushMatrix();
    k = 0;
    for(i=0;i<XMAP;i+=4){
      for(j=2;j<ZMAP;j+=4){
           glPushMatrix();
           glTranslatef((GLfloat) i, 0.0, (GLfloat) j);
           drawinnerview();
           k++;
           glPopMatrix();
         }
    }
  glPopMatrix();
 }

*/
void drawdoor()
{
  glBindTexture(GL_TEXTURE_2D,doortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0); glVertex3f(-0.02,-0.0,1.0);
    glTexCoord2f(1,1.0); glVertex3f(-0.02,-0.0,0.5);
    glTexCoord2f(1,0.0); glVertex3f(-0.02,0.3,0.5);
    glTexCoord2f(0.0,0.0); glVertex3f(-0.02,0.3,1.0);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,sidedoortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0); glVertex3f(-0.02,-0.0,0.5);
    glTexCoord2f(1,1.0); glVertex3f(-0.02,0.3,0.5);
    glTexCoord2f(1,0.0); glVertex3f(0.0,0.3,0.5);
    glTexCoord2f(0.0,0.0); glVertex3f(0.0,-0.0,0.5);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,sidedoortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0); glVertex3f(-0.02,-0.0,1.0);
    glTexCoord2f(1,1.0); glVertex3f(-0.02,0.3,1.0);
    glTexCoord2f(1,0.0); glVertex3f(0.0,0.3,1.0);
    glTexCoord2f(0.0,0.0); glVertex3f(0.0,-0.0,1.0);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,sidedoortex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0); glVertex3f(-0.02,0.3,0.5);
    glTexCoord2f(1,1.0); glVertex3f(0.0,0.3,0.5);
    glTexCoord2f(1,0.0); glVertex3f(0.0,0.3,1.0);
    glTexCoord2f(0.0,0.0); glVertex3f(-0.02,0.3,1.0);
  glEnd();
}
void drawground()
{
  glBindTexture(GL_TEXTURE_2D, groundtex);
  glBegin(GL_QUADS);
    glTexCoord2f( 0.0, 0.0); glVertex3f(-15.0, 0.0,-10.0);
    glTexCoord2f(96.0, 0.0); glVertex3f( 15.0, 0.0,-10.0);
    glTexCoord2f(96.0,96.0); glVertex3f( 15.0, 0.0, 10.0);
    glTexCoord2f( 0.0,96.0); glVertex3f(-15.0, 0.0, 10.0);


  glEnd();
}

void drawfloor()
{
glPushMatrix();
drawground();
for(i=-0;i<10;i+=5) {
x = (double)i;
glTranslatef(x, 0.0,0.0);
drawmanhole();
}
glPopMatrix();
}


void drawstarworld()
{
//glClearColor(1.0, 1.0, 0.0, 1.0);
glBindTexture(GL_TEXTURE_2D,star);
glBegin (GL_QUADS);
//glColor3f(1.0,0.0,0.0);
glTexCoord2f(0.0,0.0);
glVertex3f(-20.0,-20.0,0.0);
glTexCoord2f(10.0,0.0);
glVertex3f(20.0,-20.0,0.0);
glTexCoord2f(10.0,10.0);
glVertex3f(20.0,20.0,0.0);
glTexCoord2f(0.0,10.0);
glVertex3f(-20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(20.0,-20.0,0.0);
glTexCoord2f(10.0,0.0);
glVertex3f(20.0,-20.0,20.0);
glTexCoord2f(10.0,10.0);
glVertex3f(20.0,20.0,20.0);
glTexCoord2f(0.0,10.0);
glVertex3f(20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(20.0,-20.0,20.0);
glTexCoord2f(10.0,0.0);
glVertex3f(-20.0,-20.0,20.0);
glTexCoord2f(10.0,10.0);
glVertex3f(-20.0,20.0,20.0);
glTexCoord2f(0.0,10.0);
glVertex3f(20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(-20.0,-20.0,20.0);
glTexCoord2f(10.0,0.0);
glVertex3f(-20.0,-20.0,0.0);
glTexCoord2f(10.0,10.0);
glVertex3f(-20.0,20.0,0.0);
glTexCoord2f(0.0,10.0);
glVertex3f(-20.0,20.0,20.0);
glEnd();
}

void drawmanhole()
{
  glBindTexture(GL_TEXTURE_2D,manhole);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(2.9,0.01,1.0);
    glTexCoord2f(1.0,0.0); glVertex3f(3.5,0.01,1.0);
    glTexCoord2f(1.0,1.0); glVertex3f(3.5,0.01,1.5);
    glTexCoord2f(0.0,1.0); glVertex3f(2.9,0.01,1.5);
  glEnd();
}

void manholeworld()
{
//glClearColor(1.0, 1.0, 0.0, 1.0);
glBindTexture(GL_TEXTURE_2D,ghost);
glBegin (GL_QUADS);
//glColor3f(1.0,0.0,0.0);
glTexCoord2f(0.0,0.0);
glVertex3f(-20.0,-20.0,0.0);
glTexCoord2f(10.0,0.0);
glVertex3f(20.0,-20.0,0.0);
glTexCoord2f(10.0,10.0);
glVertex3f(20.0,20.0,0.0);
glTexCoord2f(0.0,10.0);
glVertex3f(-20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(20.0,-20.0,0.0);
glTexCoord2f(10.0,0.0);
glVertex3f(20.0,-20.0,20.0);
glTexCoord2f(10.0,10.0);
glVertex3f(20.0,20.0,20.0);
glTexCoord2f(0.0,10.0);
glVertex3f(20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(20.0,-20.0,20.0);
glTexCoord2f(10.0,0.0);
glVertex3f(-20.0,-20.0,20.0);
glTexCoord2f(10.0,10.0);
glVertex3f(-20.0,20.0,20.0);
glTexCoord2f(0.0,10.0);
glVertex3f(20.0,20.0,0.0);


glTexCoord2f(0.0,0.0);
glVertex3f(-20.0,-20.0,20.0);
glTexCoord2f(10.0,0.0);
glVertex3f(-20.0,-20.0,0.0);
glTexCoord2f(10.0,10.0);
glVertex3f(-20.0,20.0,0.0);
glTexCoord2f(0.0,10.0);
glVertex3f(-20.0,20.0,20.0);


glTexCoord2f(0.0,0.0);
glVertex3f(-20.0,20.0,20.0);
glTexCoord2f(10.0,0.0);
glVertex3f(-20.0,20.0,0.0);
glTexCoord2f(10.0,10.0);
glVertex3f(20.0,20.0,0.0);
glTexCoord2f(0.0,10.0);
glVertex3f(20.0,20.0,20.0);





glEnd();
}


