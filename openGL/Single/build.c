#include "main.h"

#define NB       256

#define MINHGT     1.0
#define MAXHGT     2.0

#define BLOCKONE        0.91
#define BLOCKZERO       0.09
#define BLOCKZEROH       0.01 //base height of building
#define BLOCKHEIGHT     0.50

#define GROUND     0.01
#define REP        1.00

#define ZERO       0.00
#define SIZE       12.00

#define TANK0       0.0
#define TANK1       0.25
#define TANKH       0.25

GLfloat txx[]={0.00, 0.00, 1.00,  1.00};   // texture coordinates
GLfloat txz[]={0.00, 1.00, 1.00,  0.00};

GLfloat bhgt[NB];
int bctr;
extern EYE eye,tank;

GLuint floortex, walltex, sidetex, bodytex,roc1tex,wall1,wall2,wall3,skytex,wall5,groundtex,gwall1tex,gwall2tex,gwall3tex,box1tex;


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
//fprintf(stdout,"MAP CO-OR %d %d",ix,iz);
  return map[ix][iz];
}



void drawbuilding(GLfloat hgt, int towerflag)
{

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, walltex);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(BLOCKZERO,BLOCKZEROH,BLOCKZERO);
    glTexCoord2f(REP, 0.0);
    glVertex3f(BLOCKONE ,BLOCKZEROH,BLOCKZERO);
    glTexCoord2f(REP, REP);
    glVertex3f(BLOCKONE ,BLOCKHEIGHT ,BLOCKZERO);
    glTexCoord2f(0.0, REP);
    glVertex3f(BLOCKZERO,BLOCKHEIGHT ,BLOCKZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(BLOCKONE ,BLOCKZEROH,BLOCKZERO);
    glTexCoord2f(REP, 0.0);
    glVertex3f(BLOCKONE ,BLOCKZEROH,BLOCKONE );
    glTexCoord2f(REP, REP);
    glVertex3f(BLOCKONE ,BLOCKHEIGHT,BLOCKONE );
    glTexCoord2f(0.0, REP);
    glVertex3f(BLOCKONE ,BLOCKHEIGHT,BLOCKZERO);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(BLOCKZERO,BLOCKZEROH,BLOCKONE );
    glTexCoord2f(REP, 0.0);
    glVertex3f(BLOCKONE ,BLOCKZEROH,BLOCKONE );
    glTexCoord2f(REP, REP);
    glVertex3f(BLOCKONE ,BLOCKHEIGHT ,BLOCKONE );
    glTexCoord2f(0.0, REP);
    glVertex3f(BLOCKZERO,BLOCKHEIGHT ,BLOCKONE );

    glTexCoord2f(0.0, 0.0);
    glVertex3f(BLOCKZERO,BLOCKZEROH,BLOCKZERO);
    glTexCoord2f(REP, 0.0);
    glVertex3f(BLOCKZERO,BLOCKZEROH ,BLOCKONE);
    glTexCoord2f(REP, REP);
    glVertex3f(BLOCKZERO,BLOCKHEIGHT ,BLOCKONE );
    glTexCoord2f(0.0, REP);
    glVertex3f(BLOCKZERO,BLOCKHEIGHT,BLOCKZERO );
  glEnd();
  glPopMatrix();
}



void drawblock()
{
  int i,j,k;
  int x=0;
  bctr = 0;

  glPushMatrix();

  k = 0;
  for(i=0;i<XMAP;i++){
    for(j=0;j<ZMAP;j++){
      if(!map[i][j]) continue;
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
  glBindTexture(GL_TEXTURE_2D,floortex);
  glBegin(GL_QUADS);
    glTexCoord2f( 0.0, 0.0); glVertex3f(ZERO, 0.001,ZERO);
    glTexCoord2f(5.0, 0.0); glVertex3f(ZERO, 0.001,SIZE);
    glTexCoord2f(5.0,5.0); glVertex3f(SIZE, 0.001,SIZE);
    glTexCoord2f( 0.0,5.0); glVertex3f(SIZE, 0.001,ZERO);
  glEnd();
}




void readMAPFILE()
{

FILE *fd;
int i,j,k;
fd = fopen(MAPFILE,"r");

if(!fd){
  fprintf(stderr,"cannot open file\n");
  exit(0);
 }

else {
 for(i=0;i<XMAP;i++){
  for(j=0;j<ZMAP;j++){
   fscanf(fd,"%d",&k);
   map[i][j] = k;
   }
  }
 }
 fclose(fd);

}



void drawTankbody()
{

  glPushMatrix();


  glBindTexture(GL_TEXTURE_2D, box1tex);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0, REP);
    glVertex3f(TANK0,0.0,TANK0);
    glTexCoord2f(REP, REP);
    glVertex3f(TANK1,0.0,TANK0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(TANK1,TANKH,TANK0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(TANK0,TANKH,TANK0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(TANK1,0.0,TANK0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(TANK1,0.0,TANK1);
    glTexCoord2f(REP, REP);
    glVertex3f(TANK1,TANKH,TANK1);
    glTexCoord2f(0.0, REP);
    glVertex3f(TANK1,TANKH,TANK0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(TANK1,0.0,TANK1);
    glTexCoord2f(REP, 0.0);
    glVertex3f(TANK0,0.0,TANK1);
    glTexCoord2f(REP, REP);
    glVertex3f(TANK0,TANKH,TANK1);
    glTexCoord2f(0.0, REP);
    glVertex3f(TANK1,TANKH,TANK1);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(TANK0,0.0,TANK1);
    glTexCoord2f(REP, 0.0);
    glVertex3f(TANK0,0.0,TANK0);
    glTexCoord2f(REP, REP);
    glVertex3f(TANK0,TANKH,TANK0);
    glTexCoord2f(0.0, REP);
    glVertex3f(TANK0,TANKH,TANK1);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(TANK0,TANKH,TANK0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(TANK1,TANKH,TANK0);
    glTexCoord2f(REP, REP);
    glVertex3f(TANK1,TANKH,TANK1);
    glTexCoord2f(0.0, REP);
    glVertex3f(TANK0,TANKH,TANK1);

  glEnd();
  glPopMatrix();
}




void drawTank(GLfloat x,GLfloat y,GLfloat z)
{
 int i;
//fprintf(stdout,"tank co-ordinates: %lf %lf %lf\n",x,y,z);
 //for(i=0;i<NMON;i++){
 glPushMatrix();
// glTranslatef(me[i].x,me[i].y,me[i].z);
 glTranslatef(x,0.0,z);
 drawTankbody();
 //glRotatef(-RAD2DEG(tank.velocity.theta), 0, 1, 0);
 glPopMatrix();
 //}
}


void drawwall() {

  glPushMatrix();


  glBindTexture(GL_TEXTURE_2D, wall5);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,3.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,3.0,0.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,0.0,0.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,0.0,0.0);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, wall3);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(12.0,3.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,3.0,12.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,0.0,12.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(12.0,0.0,0.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(12.0,3.0,12.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(0.0,3.0,12.0);
    glTexCoord2f(REP, REP);
    glVertex3f(0.0,0.0,12.0);
    glTexCoord2f(0.0,REP);
    glVertex3f(12.0,0.0,12.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, wall2);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,3.0,12.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(0.0,3.0,0.0);
    glTexCoord2f(REP,REP);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2f(0.0,REP);
    glVertex3f(0.0,0.0,12.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, skytex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,3.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,3.0,0.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,3.0,12.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,3.0,12.0);
  glEnd();
  glPopMatrix();


}
 
 
 void drawworld() {
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, gwall3tex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,-5.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,-5.0,0.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,-5.0,12.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,-5.0,12.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, gwall1tex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,0.0,0.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,-5.0,0.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,-5.0,0.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, gwall1tex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(12.0,0.0,0.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,-5.0,0.0);
    glTexCoord2f(REP, REP);
    glVertex3f(12.0,-5.0,12.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(12.0,0.0,12.0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, gwall1tex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(12.0,0.0,12.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(12.0,-5.0,12.0);
    glTexCoord2f(REP, REP);
    glVertex3f(0.0,-5.0,12.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,0.0,12.0);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, gwall1tex);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0,0.0,12.0);
    glTexCoord2f(REP, 0.0);
    glVertex3f(0.0,-5.0,12.0);
    glTexCoord2f(REP, REP);
    glVertex3f(0.0,-5.0,0.0);
    glTexCoord2f(0.0, REP);
    glVertex3f(0.0,0.0,0.0);
  glEnd();
  glPopMatrix();

 
 }
