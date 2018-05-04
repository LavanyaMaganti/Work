
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// #define SEAMLESS

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

#define EPSILON    0.01   // margin of error for y coordinate when falling

#define MAXSPEED   0.050  // maximum speed
#define POWER      0.010
#define FRICTION   0.975

#define WHT        0.50
#define INIT_HGT   0.18

#define MAPFILE "world25x25.map"

#define K       1024
#define NUSERS    16

typedef struct maptype {
   int rows,cols;
   int **map;
} MAP;

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
void firemissile();
void movemissile();
void drawmissile();

int readmap(MAP *p);

void make_kaboom(GLfloat x, GLfloat y, GLfloat z);
int animate_kaboom();
int kaboom();

void drawcrosshairs();

