
#include "main.h"

GLuint bodytex1,bodytex2,headtex1;
SEQ seq[NSEQ];

extern MONSTER me[];
extern seqlist[];

void initone(int k)
{
  me[k].x       = 5.0 * drand48();
  me[k].y       = 0.0;
  me[k].z       = 5.0 * drand48();
  me[k].heading = 360.0 * drand48();
  me[k].leftarmangle  = 360.0 * drand48();
  me[k].rightarmangle = 360.0 * drand48();
  me[k].bodyrad = 0.05 + 0.03 * drand48();
  me[k].legrad  = 0.01 + 0.02 * drand48();
  me[k].bodylen = 0.10 + 0.20 * drand48();
  me[k].leglen  = 0.10 + 0.20 * drand48();
  me[k].seqno   = k % NSEQ;
  me[k].moving  = 1;
}
void initall()
{
  int i;

  memset(me,0,NMON*sizeof(MONSTER));
  for(i=0;i<NMON;i++)
    initone(i);
}
void drawhead(MONSTER *p)
{
  GLfloat r;

  r = p->bodyrad/1.5;
  glTranslatef(0.0, 0.0, p->bodylen + r);
  glBindTexture(GL_TEXTURE_2D, headtex1);
  glBegin(GL_QUADS);
    glTexCoord2f(0.38,  1.0); glVertex3f(-r, r,-r);
    glTexCoord2f(0.38,  0.0); glVertex3f(-r, r, r);
    glTexCoord2f(0.62,  0.0); glVertex3f( r, r, r);
    glTexCoord2f(0.62,  1.0); glVertex3f( r, r,-r);

    glTexCoord2f(-0.12,  1.0); glVertex3f(-r,-r,-r);
    glTexCoord2f(-0.12,  0.0); glVertex3f(-r,-r, r);
    glTexCoord2f( 0.12,  0.0); glVertex3f( r,-r, r);
    glTexCoord2f( 0.12,  1.0); glVertex3f( r,-r,-r);

    glTexCoord2f(0.62,  1.0); glVertex3f( r, r,-r);
    glTexCoord2f(0.62,  0.0); glVertex3f( r, r, r);
    glTexCoord2f(0.87,  0.0); glVertex3f( r,-r, r);
    glTexCoord2f(0.87,  1.0); glVertex3f( r,-r,-r);

    glTexCoord2f(0.38,  0.0); glVertex3f(-r, r, r);
    glTexCoord2f(0.38,  1.0); glVertex3f(-r, r,-r);
    glTexCoord2f(0.12,  1.0); glVertex3f(-r,-r,-r);
    glTexCoord2f(0.12,  0.0); glVertex3f(-r,-r, r);
  glEnd();
}
void drawarm(MONSTER *p)
{
  GLfloat r,z;

  r = p->bodyrad/3.0;
  z = p->bodylen;
  glBindTexture(GL_TEXTURE_2D, bodytex2);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r, r, 0);
    glTexCoord2f(0.0,  0.5); glVertex3f(-r, r, z);
    glTexCoord2f(0.1,  0.5); glVertex3f( r, r, z);
    glTexCoord2f(0.1,  0.0); glVertex3f( r, r, 0);

    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-r, 0);
    glTexCoord2f(0.0,  0.5); glVertex3f(-r,-r, z);
    glTexCoord2f(0.1,  0.5); glVertex3f( r,-r, z);
    glTexCoord2f(0.1,  0.0); glVertex3f( r,-r, 0);

    glTexCoord2f(0.0,  0.0); glVertex3f( r, r, 0);
    glTexCoord2f(0.0,  0.5); glVertex3f( r, r, z);
    glTexCoord2f(0.1,  0.5); glVertex3f( r,-r, z);
    glTexCoord2f(0.1,  0.0); glVertex3f( r,-r, 0);

    glTexCoord2f(0.1,  0.5); glVertex3f(-r, r, z);
    glTexCoord2f(0.1,  0.0); glVertex3f(-r, r, 0);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-r, 0);
    glTexCoord2f(0.0,  0.5); glVertex3f(-r,-r, z);
  glEnd();
}
void drawbody(MONSTER *p)
{
  GLfloat h,r,z;

  r = p->bodyrad;
  h = r/2.0;
  z = p->bodylen;
  glBindTexture(GL_TEXTURE_2D, bodytex2);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-h, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r,-h, z);
    glTexCoord2f(0.5,  1.0); glVertex3f( r,-h, z);
    glTexCoord2f(0.5,  0.0); glVertex3f( r,-h, 0);

    glTexCoord2f(0.0,  0.0); glVertex3f( r, h, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, h, z);
    glTexCoord2f(0.5,  1.0); glVertex3f( r,-h, z);
    glTexCoord2f(0.5,  0.0); glVertex3f( r,-h, 0);

    glTexCoord2f(0.5,  1.0); glVertex3f(-r, h, z);
    glTexCoord2f(0.5,  0.0); glVertex3f(-r, h, 0);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-h, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r,-h, z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, h, 0);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, h, z);
    glTexCoord2f(0.0,  0.0); glVertex3f( r, h, z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, h, 0);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, bodytex2);

  glPushMatrix();
    glTranslatef( r+h, 0, 0);
    glTranslatef(0, 0, p->bodylen);
//    glRotatef(p->leftarmangle, 1, 0, 0);
    glRotatef(p->rightlegangle, 1, 0, 0);
    glTranslatef(0, 0,-p->bodylen);
    drawarm(p);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(-r-h, 0, 0);
    glTranslatef(0, 0, p->bodylen);
//    glRotatef(p->rightarmangle, 1, 0, 0);
    glRotatef(p->leftlegangle, 1, 0, 0);
    glTranslatef(0, 0,-p->bodylen);
    drawarm(p);
  glPopMatrix();

  glPushMatrix();
    drawhead(p);
  glPopMatrix();
}
void drawleg(MONSTER *p)
{
  GLfloat r,z;

  glBindTexture(GL_TEXTURE_2D, bodytex1);
  r = p->legrad;
  z = p->leglen;
  glBegin(GL_QUADS);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-r, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r,-r, z);
    glTexCoord2f(1.0,  1.0); glVertex3f( r,-r, z);
    glTexCoord2f(1.0,  0.0); glVertex3f( r,-r, 0);

    glTexCoord2f(0.0,  0.0); glVertex3f( r, r, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, r, z);
    glTexCoord2f(1.0,  1.0); glVertex3f( r,-r, z);
    glTexCoord2f(1.0,  0.0); glVertex3f( r,-r, 0);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, r, z);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, r, 0);
    glTexCoord2f(0.0,  0.0); glVertex3f(-r,-r, 0);
    glTexCoord2f(0.0,  1.0); glVertex3f(-r,-r, z);

    glTexCoord2f(1.0,  1.0); glVertex3f(-r, r, 0);
    glTexCoord2f(1.0,  0.0); glVertex3f(-r, r, z);
    glTexCoord2f(0.0,  0.0); glVertex3f( r, r, z);
    glTexCoord2f(0.0,  1.0); glVertex3f( r, r, 0);
  glEnd();
}
void drawme(MONSTER *p)
{
  int j,k;

  j = p->seqno;
  k = p->fno;
  glPushMatrix();
    glTranslatef(p->x, p->y, p->z);
    glTranslatef(0.0, seq[j].dy[k], 0.0);
    glRotatef(-90.0, 1, 0, 0);
    glRotatef(p->heading, 0, 0, 1);
//
// this puts the monster in the correct location, heading, angles, etc.
//
    glPushMatrix();
      glTranslatef(0, 0,  p->leglen);
      glRotatef(seq[j].lla[k], 1, 0, 0);
      glTranslatef(-1.5*p->legrad, 0.00, -p->leglen);
      drawleg(p);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0,  p->leglen);
      glRotatef(seq[j].rla[k], 1, 0, 0);
      glTranslatef( 1.5*p->legrad, 0.00, -p->leglen);
      drawleg(p);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0, p->bodylen);
      glRotatef(seq[j].ba[k], 1, 0, 0);
      glTranslatef( 0.0, 0.0,  p->leglen - p->bodylen);
      drawbody(p);
    glPopMatrix();
  glPopMatrix();
}


void movemonsters()
{
  int i,j,k;

  for(i=0;i<NMON;i++){
    if(me[i].moving){
      j = me[i].seqno;
      me[i].tick++;
      if(me[i].tick == seq[j].tpf){
        me[i].tick = 0;
        me[i].fno++;

    if(me[i].fno == seq[j].nframes){
          me[i].heading += 30.0 * (drand48() - 0.1);
          me[i].fno = 0;
        }
//        me[i].x += seq[j].ds[me[i].fno] * sin(DEG2RAD(me[i].heading));
//        me[i].z += seq[j].ds[me[i].fno] * cos(DEG2RAD(me[i].heading));

 if((me[i].x >= -3.09 && me[i].x <= -1.91)|| (me[i].x <= 2.09 && me[i].x >= 0.91)) {
  if(me[i].z>=4.91 && me[i].z <=6.09){ 
    me[i].heading += 180.0;
      me[i].x += seq[j].ds[me[i].fno] * sin(DEG2RAD(me[i].heading));
      me[i].z += seq[j].ds[me[i].fno] * cos(DEG2RAD(me[i].heading));
       printf("TURN\n");
    }
  }

 me[i].x +=seq[j].ds[me[i].fno] * sin(DEG2RAD(me[i].heading));
 me[i].z += seq[j].ds[me[i].fno] * cos(DEG2RAD(me[i].heading));

      }
      k = me[i].fno;
      me[i].leftlegangle  = seq[j].lla[k];
      me[i].rightlegangle = seq[j].rla[k];
    }
  }
  glutPostRedisplay();
}
