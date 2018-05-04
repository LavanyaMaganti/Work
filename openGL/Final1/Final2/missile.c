
#include "main.h"

unsigned int missileflag = 0;

MISSILE miss;

extern GLuint redtex;
extern unsigned int kaboomflag;
extern EYE eye;
extern MAP map;

void firemissile()
{
  GLfloat th;

  if(missileflag)
    return;
  missileflag = 1;
  th = eye.facing.theta;
  miss.len = 5.00;
  miss.x = eye.x; 
  miss.y = eye.y + eye.hgt; 
  miss.z = eye.z; 
  miss.vx = 0.025 * cos(th);
  miss.vy = 0.025 * sin(eye.facing.phi);
  miss.vz = 0.025 * sin(th);
}
void movemissile()
{
  int ix,iz;
  GLfloat tx,tz,minhgt;

  if(!missileflag)
    return;
  miss.vy -= 0.00002;
  tx = miss.x + miss.vx;
  tz = miss.z + miss.vz;
 
  ix = (int) tx;
  iz = (int) tz;
  if(ix < 0 || iz < 0 || ix >= map.cols || iz >= map.rows)
    minhgt = 0.0;
  else
    minhgt = map.map[iz][ix] ? WHT : 0.0;
  if(miss.y < minhgt){
    missileflag = 0;
    kaboomflag = 1;
    make_kaboom(miss.x,miss.y + miss.vy,miss.z);
    return;
  }
  miss.x += miss.vx;
  miss.y += miss.vy;
  miss.z += miss.vz;
}
void drawmissile()
{
  GLfloat xperp, zperp;
  int i;

  if(!missileflag)
    return;
  fprintf(stderr,"%f  %f  %f\n", miss.x, miss.y, miss.z);
  glPushMatrix();
  glTranslatef(miss.x, miss.y, miss.z);
  glBindTexture(GL_TEXTURE_2D, redtex);
  xperp =  miss.vz/4.0;
  zperp = -miss.vx/4.0;
  for(i=0;i<3;i++){
    glRotatef(60.0,miss.vx,miss.vy,miss.vz);
    glBegin(GL_TRIANGLES);
    glTexCoord2f( 0.0,  0.0);
    glVertex3f(0,0,0);
    glTexCoord2f( 1.0,  0.0);
    glVertex3f(-miss.len*(miss.vx + xperp),
               -miss.len*miss.vy,
               -miss.len*(miss.vz + zperp));
    glTexCoord2f( 0.5,  1.0);
    glVertex3f(-miss.len*(miss.vx - xperp),
               -miss.len*miss.vy,
               -miss.len*(miss.vz - zperp));
    glEnd();
  }
  glPopMatrix();
}
