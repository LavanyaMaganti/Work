
#include "main.h"

GLUquadric *body, *lleg, *rleg;
GLuint floortex,bodytex;
extern MONSTER me;

int bdy[5];
int left[5];
int right[5];

GLUquadric *initquadric()
{
  GLUquadric *p;

  p = gluNewQuadric();
  gluQuadricDrawStyle(p,GLU_FILL);
  gluQuadricTexture(p, GLU_TRUE);
  return p;
}
void initme()
{
  body = initquadric();
  lleg = initquadric();
  rleg = initquadric();
}
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

void angles()
{
  FILE *fd;
  fd = fopen("angles","r");
  int i =0;
    if(fd == NULL)
      fprintf(stderr,"could not open file");
    else 
      {
	     while((fscanf(fd,"%d %d %d",&bdy[i],&left[i],&right[i])!=EOF))
	        {
	        	fprintf(stderr,"body: %d, left: %d, right: %d \n",&bdy[i],&left[i],&right[i]);
            i++;
	        }
      }
    fclose(fd);
}

void drawme()
{
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, bodytex);
    glTranslatef(me.x, me.y, me.z);
    glRotatef(-90.0, 1, 0, 0);
    glRotatef(me.heading, 0, 0, 1);
    angles();
    glPushMatrix();
      glTranslatef(0, 0,  me.leglen);
      glRotatef(me.leftlegangle, 1, 0, 0);
      glTranslatef(-1.5*me.legrad, 0.00, -me.leglen);
      gluCylinder(rleg, me.legrad, me.legrad, me.leglen, 16, 16);
      angles();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0,  me.leglen);
      glRotatef(me.rightlegangle, 1, 0, 0);
      glTranslatef( 1.5*me.legrad, 0.00, -me.leglen);
      gluCylinder(rleg, me.legrad, me.legrad, me.leglen, 16, 16);
      angles();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0, me.bodylen);
      glRotatef(me.bodyangle, 1, 0, 0);
      glTranslatef( 0.0, 0.0,  me.leglen - me.bodylen);
      gluCylinder(body, me.bodyrad, me.bodyrad, me.bodylen, 16, 16);
      angles();
    glPopMatrix();
//      angles();
  glPopMatrix();
}