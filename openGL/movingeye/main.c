
#include "main.h"

#define  FLOORFILE     "PPM/metal2.ppm"
#define  BODYFILE1     "PPM/denim.ppm"
#define  BODYFILE2     "PPM/plaid.ppm"
#define  FACEFILE1     "PPM/head2.ppm"
#define  ARCHFILE      "brick.ppm"

static char *seqfile[]={
  "SEQ/bob.seq",
  "SEQ/beb.seq",
  "SEQ/bab.seq"
};

extern GLuint floortex, bodytex1, bodytex2, headtex1, archtex;
extern SEQ seq[NSEQ];

EYE eye;
MONSTER me[NMON];

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("The World Series");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(dostuff);

   init(argv[1]);

   glutMainLoop();
}
void init(char *fname)
{
  int i;

  srand48(getpid());

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);

  eye.x =  0.0;
  eye.y =  0.0;
  eye.z =  2.0;

  eye.facing.theta = DEG2RAD(270.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD(270.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  floortex  = readppm(FLOORFILE,1);
  bodytex1  = readppm(BODYFILE1,1);
  bodytex2  = readppm(BODYFILE2,1);
  headtex1  = readppm(FACEFILE1,1);
  archtex  = readppm(ARCHFILE,1);

  for(i=0;i<NSEQ;i++)
    readsequence(seqfile[i], &seq[i]);
  initall();
  for(i=0;i<NMON;i++){
    printf("%f  %f  %f\n",
      me[i].x,
      me[i].y,
      me[i].z);
    printf("%f  %f  %f  %f\n",
      me[i].bodylen,
      me[i].leglen,
      me[i].bodyrad,
      me[i].legrad);
    printf("%d  %d\n",
      me[i].seqno,
      me[i].bodytex);
  }
}
void display()
{
   int i,j;
   GLfloat dx,dy,dz;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 4.0/3.0, 0.001, 5000.0);
   dx = -sin(DEG2RAD(me[0].heading));
   dz = -cos(DEG2RAD(me[0].heading));
   j = me[0].seqno;
   dy = seq[j].dy[me[0].fno];

   gluLookAt(me[0].x + dx  , me[0].y + dy + 0.5, me[0].z + dz,
             me[0].x + 2.0*dx, me[0].y + dy + 0.5, me[0].z + 2.0*dz,
             0,       1,        0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
   drawfloor();
   drawArch();
   for(i=0;i<NMON;i++)
     drawme(&me[i]);

   glPopMatrix();
   glutSwapBuffers();
}
void dostuff()
{
  GLfloat tx,ty,tz;
  int i,j,k;

  if(eye.speed > 0){
    eye.speed *= FRICTION;
    tx = eye.x + eye.speed * eye.velocity.x;
    ty = eye.y + eye.speed * eye.velocity.y;
    tz = eye.z + eye.speed * eye.velocity.z;
    eye.x = tx;
    eye.y = ty;
    eye.z = tz;
  }
  movemonsters();
}
