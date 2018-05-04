
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define EPSILON    0.01   // margin of error for y coordinate when falling
#define HGT        0.40   // height of player
#define MAXSPEED   5.00   // maximum speed

#define POWER      0.005
#define FRICTION   0.995

#define MAP       13    // must be odd
#define K       1024

typedef struct vector {
   GLfloat x,y,z;
   GLfloat theta,phi;
} VEC;

typedef struct eye {
   int faceforward;
   GLfloat x,y,z;
   GLfloat speed;
   VEC facing;          // direction "pilot" is looking
   VEC velocity;        // direction "ship" is moving
} EYE;

typedef struct monster {
  GLfloat bodyrad, legrad;
  GLfloat bodylen, leglen;
  GLfloat leftlegangle, rightlegangle, bodyangle;
  GLfloat x,y,z;
  GLfloat heading;
} MONSTER;

void init(char *fname);
void initme();
void drawme();
void drawfloor();
void display();
void dostuff();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);
GLuint readppm(char *filename, int wrap);
GLfloat length(VEC *v);
void setdirection(VEC *v);
void setangles(VEC *v);
