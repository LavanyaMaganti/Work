
#include "main.h"

#define  FLOORFILE "floor.ppm"
#define  BOXFILE  "box.ppm"
#define  ROCKETFILE  "rocket2.ppm"
//#define  ROCKETFILE  "/u1/junk/cs440/Game/cs44013/cs44013.ppm"
#define  WALL1FILE "wall7.ppm"
#define  WALL2FILE "wall2.ppm"
#define  WALL3FILE "wall1.ppm"
#define  WALL5FILE "wall3.ppm"
#define  SKYFILE "sky1.ppm"
#define  GROUNDFILE "ground.ppm"
#define  GWALL1FILE "gwall1.ppm"
#define  GWALL2FILE "gwall2.ppm"
#define  GWALL3FILE "gwall3.ppm"

extern GLuint floortex, walltex, sidetex, bodytex,roc1tex,wall1,wall2,wall3,skytex,wall5,groundtex,gwall1tex,gwall2tex,gwall3tex;
EYE eye,tank;
int eyebouncing=0,tankbouncing=0;

int main(int argc, char *argv[])
{  
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);
   glutIdleFunc(dostuff);
   glutMotionFunc(mousemotion);

   init(argv[1]);

   glutMainLoop();
}

void init(char *fname)
{
  srand48(getpid());
  
  mug_setup("cs.indstate.edu");
int  seconds = time(0);

  glClearColor(0.0,0.0,0.0, 1.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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

//  inittank();  //tank initialization
  initeye();   //eye initialization
 // initbuild();
readMAPFILE();
}


void display()
{
   GLfloat xzlen;
   int i;
   static int tick=0;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 4.0/3.0, 0.001, 5000.0);
/*   gluLookAt(tank.x, tank.y, tank.z,
             tank.x+tank.facing.x, tank.y+tank.facing.y, tank.z+tank.facing.z,
             0.0, 1.0, 0.0);
*/
   gluLookAt(eye.x,eye .y, eye.z,
             eye.x+eye.facing.x, eye.y+eye.facing.y, 
             eye.z+eye.facing.z,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//   drawTank(tank.x,tank.y,tank.z);    //tank
   drawground();                      //ground
   drawblock();                       //blocks
   drawwall();
   drawworld();

  if(tick == 0){
    mug_send(eye.x, eye.y, eye.z, eye.facing.theta);
   } else {
     mug_receive();
    }
    tick = 1 - tick;
    for(i=0;i<MAXPLAYERS;i++){
      if(i != myId){
         if(players[i]->online == 1)
           {
              fprintf(stderr,"Player co-ordinates: %lf %lf %lf",players[i]->x,players[i]->y,players[i]->z);
              drawTank(players[i]->x,players[i]->y,players[i]->z);
           }
         }
       }
      for(i=0;i<MAXPLAYERS;i++)
         putchar(players[i]->online ? '1' : '0');
   putchar('\n');

   glPopMatrix();
   glutSwapBuffers();
}


void dostuff()
{
  eyestuff();     //eye reading map file
//  tankstuff();  //tank reading map file
}


void eyestuff()
{
   GLfloat txeye,tyeye,tzeye;
   if(eyebouncing){
     eye.facing.theta += 0.1 * (drand48() - 0.5);
     eye.facing.phi   += 0.1 * (drand48() - 0.5);
     setdirection(&eye.facing);
     if(eyebouncing > 0)
       --eyebouncing;

     glutPostRedisplay();

     } else {

     if(eye.speed > 0){
       eye.speed *= FRICTION;
       txeye = eye.x + eye.speed * eye.velocity.x;
       tyeye = eye.y;// + eye.speed * eye.velocity.y;
       tzeye = eye.z + eye.speed * eye.velocity.z;
       if(!cango(txeye,tyeye,tzeye)){
//     fprintf(stdout,"MAP %d\n",cango(txeye,tyeye,tzeye));
         eye.x = txeye;
         eye.y = tyeye;
         eye.z = tzeye;
       } else {
//   fprintf(stdout,"MAP %d\n",cango(txeye,tyeye,tzeye));
         eye.speed = 0;
         eyebouncing = 60;
       }
      }//if
     glutPostRedisplay();
    }//else
}


void tankstuff()
{
   GLfloat txtank,tytank,tztank;
   if(tankbouncing){
     tank.facing.theta += 0.1 * (drand48() - 0.5);
     tank.facing.phi   += 0.1 * (drand48() - 0.5);
     setdirection(&tank.facing);
     if(tankbouncing > 0)
       --tankbouncing;

     glutPostRedisplay();

   } else {

if(tank.speed > 0){
       tank.speed *= FRICTION;
       txtank = tank.x + tank.speed * tank.velocity.x;
       tytank = tank.y + tank.speed * tank.velocity.y;
       tztank = tank.z + tank.speed * tank.velocity.z;
//    fprintf(stdout,"tank co-ords changed\n");
       if(!cango(txtank,tytank,tztank)){
//         fprintf(stdout,"MAP %d\n",cango(txtank,tytank,tztank));
         tank.x = txtank;
         tank.y = tytank;
         tank.z = tztank;
       } else {
//         fprintf(stdout,"MAP %d\n",cango(txtank,tytank,tztank));
         tank.speed = 0;
         tankbouncing =100;
       }
     }
     glutPostRedisplay();
}
}

void inittank() 
{

  tank.x =5.3;
  tank.y =0.2;
  tank.z =5.0;

  tank.speed = 0;
  tank.facing.theta = DEG2RAD(270.0);
  tank.facing.phi   = 0.0;
  setdirection(&tank.facing);

  tank.velocity.theta = DEG2RAD(270.0);
  tank.velocity.phi   = 0.0;
  setdirection(&tank.velocity);

  tank.faceforward = 1;


}
 void initeye()
 {
  eye.x=5.0;
  eye.y=0.3;
  eye.z=5.0;

  eye.facing.theta = DEG2RAD(0.0);
  eye.facing.phi   = 0.0;
  setdirection(&eye.facing);

  eye.velocity.theta = DEG2RAD(0.0);
  eye.velocity.phi   = 0.0;
  setdirection(&eye.velocity);

  eye.faceforward = 1;
}
