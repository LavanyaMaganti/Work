
#include "main.h"

#define  FLOORFILE "floor.ppm"
#define  BOXFILE  "box.ppm"
#define  ROCKETFILE  "rocket2.ppm"
#define  WALL1FILE "wall7.ppm"
#define  WALL2FILE "wall2.ppm"
#define  WALL3FILE "wall1.ppm"
#define  WALL5FILE "wall3.ppm"
#define  SKYFILE "sky1.ppm"
#define  GROUNDFILE "ground.ppm"
#define  GWALL1FILE "gwall1.ppm"
#define  GWALL2FILE "gwall2.ppm"
#define  GWALL3FILE "gwall3.ppm"
#define  REDTEX  "rocket1.ppm"

extern GLuint floortex, walltex, sidetex,bodytex,roc1tex,wall1,wall2,wall3,skytex,wall5,groundtex,gwall1tex,gwall2tex,gwall3tex,redtex;
EYE eye,tank;

unsigned int kaboomflag;
int wizard;
EYE eye;
MAP map;

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE |  GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(WINWIDTH,WINHEIGHT);
   glutInitWindowPosition(128,64);
   glutCreateWindow("December 30, 2016");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(animate);


   init();

   wizard = (getuid() == 11);
   glutMainLoop();
}
void init()
{
  int i, ix, iz;
  char fname[K];
  unsigned char white[]={255,255,255,255};

  srand48(getpid());

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT, GL_FILL);
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 floortex  = readppm(FLOORFILE,1);
 walltex   = readppm(BOXFILE,1);
 roc1tex   = readppm(ROCKETFILE,1);
 wall1     = readppm(WALL1FILE,1);
 wall2     = readppm(WALL2FILE,1);
 wall3     = readppm(WALL3FILE,1);
 wall5     = readppm(WALL5FILE,1);
 skytex    = readppm(SKYFILE,1);
 groundtex = readppm(GROUNDFILE,1);
 gwall1tex = readppm(GWALL1FILE,1);
 gwall2tex = readppm(GWALL2FILE,1);
 gwall3tex = readppm(GWALL2FILE,1);
 redtex    = readppm(REDTEX,1);

  if(!readmap(&map))
    exit(0);
  fprintf(stderr,"read map\n");

  do {
    ix = lrand48() % map.cols;
    iz = lrand48() % map.rows;
  } while(map.map[iz][ix]);
  eye.x = 0.5 + (GLfloat) ix;
  eye.y = 0.0;
  eye.z = 0.5 + (GLfloat) iz;

  eye.hgt = INIT_HGT;

  eye.facing.theta = DEG2RAD( 0.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD( 0.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);
}
void display()
{
   int i;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, 4.0/3.0, 0.001, 5000.0);
   gluLookAt(eye.x, eye.y + eye.hgt, eye.z,
             eye.x+eye.facing.x, eye.y + eye.hgt + eye.facing.y, eye.z+eye.facing.z,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
   drawground();                      //ground
   drawblock();                       //blocks
 //  drawwall();
   drawworld();   
   drawmissile();
   if(kaboomflag)
     kaboom();
   glPopMatrix();

//   glClear(GL_DEPTH_BUFFER_BIT);  not required in this case, but in general
//                                  this is for drawing a top layer, it means ignore
//                                  depth info already computed
   drawcrosshairs();

   glutSwapBuffers();
}
void animate()
{
  GLfloat tx,ty,tz,rr,fric;
  int i,j,k;

  if(eye.speed > 0){
    eye.speed *= FRICTION;
    tx = eye.x + eye.speed * eye.velocity.x;
    ty = eye.y; // + eye.speed * eye.velocity.y;
    tz = eye.z + eye.speed * eye.velocity.z;
    if(!wizard && map.map[(int)tz][(int)tx]){
      eye.speed = 0;
    } else {
      eye.x = tx;
      eye.y = ty;
      eye.z = tz;
    }
  }
  movemissile();
  if(kaboomflag)
    kaboomflag = animate_kaboom();
  glutPostRedisplay();
}
