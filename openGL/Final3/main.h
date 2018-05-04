
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#include <mug.h>

// #define SEAMLESS

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI )
#define DEG2RAD(X)   ((X * M_PI )/180.0)

#define EPSILON    0.01   // margin of error for y coordinate when falling
#define MAXSPEED   5.00   // maximum speed

#define POWER      0.025
#define FRICTION   0.995

#define INIT_HGT   0.18

#define MAP       13    // must be odd
#define K       1024
#define NUSERS    16

typedef struct vector {
   GLfloat x,y,z;
   GLfloat theta,phi;
} VEC;

typedef struct eye {
   int faceforward;
   GLfloat hgt;
   GLfloat x,y,z;
   GLfloat speed;
   VEC facing;          // direction "pilot" is looking
   VEC velocity;        // direction "ship" is moving
} EYE;

void init();
void initall();
void drawme();
void drawfloor();
void drawhills();
void drawplayer(MUGR *p);
void display();
void display2();
void animate();
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);
GLuint readppm(char *filename, int wrap);
GLuint readtransppm(char *filename, int wrap);
GLuint makeppm();
GLfloat length(VEC *v);
void setdirection(VEC *v);
void setangles(VEC *v);

