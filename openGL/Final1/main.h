#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include<time.h>
//#include <mug07.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#define WINWIDTH   2400
#define WINHEIGHT  1800

#else

#include <GL/glut.h>

#define WINWIDTH   1600
#define WINHEIGHT  1200

#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)
#define WHT        0.50
#define INIT_HGT   0.18


#define POWER      0.005
#define FRICTION   0.995
#define NUSERS    16

#define K       1024
#define XMAP 12
#define ZMAP 12
#define MAPFILE "MAPFILE"
#define MAXSPEED   0.050  // maximum speed

int map[XMAP][ZMAP];

typedef struct vector {
   GLfloat x,y,z;
   GLfloat theta,phi;
} VEC;

typedef struct missile {
   GLfloat len;
   GLfloat x,y,z;
   GLfloat vx,vy,vz;
} MISSILE;

typedef struct eye {
   int faceforward;
   GLfloat x,y,z;
  GLfloat hgt;
   GLfloat speed;
   VEC facing;          // direction "pilot" is looking
   VEC velocity;        // direction "ship" is moving
} EYE;


void init(char *fname);
void drawblock();
void drawground();
void display();
void dostuff();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);
void repo();
GLuint readppm(char *filename, int wrap);
int cango(GLfloat x, GLfloat y, GLfloat z);
GLfloat length(VEC *v);
void setdirection(VEC *v);
void setangles(VEC *v);
void initbuild();
void inittank();
//void mousemotion(int x, int y);
void readMAPFILE();
void drawTank(GLfloat x, GLfloat y, GLfloat z);
void animate();
void accelerate(double ds);
void drawTankbody();
void eyestuff();
void tankstuff();
void initeye();
void drawwall();
void drawworld();
void firemissile();
void movemissile();
void drawmissile();
void make_kaboom(GLfloat x, GLfloat y, GLfloat z);
int animate_kaboom();
int drawkaboom();
int kaboom();
void drawcrosshairs();

