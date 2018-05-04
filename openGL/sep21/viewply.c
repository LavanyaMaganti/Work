
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RAD2DEG(X)   ((X * 180.0)/M_PI)

//#define DFILE  "A2.ply"
#define CHUNK  4
#define MAX 2048
typedef struct thing {
   double x, y, z;     // position
   double vx, vy, vz;  // velocity
   double theta, phi;  // heading (orientation) angles
   double len;
} THING;

typedef struct eye {
   double x,y,z;
} EYE;

typedef struct line {
  double x1,y1,z1;
  double x2,y2,z2;
} LINE;

typedef struct linelist {
  LINE *lines;
  int nlines;
  int size;
} LINELIST;

typedef struct vertex
 {
  float x, y, z;
 } VERTEX;
  

EYE eye;
THING it;
LINELIST linelist;
VERTEX vertex[MAX];


void init(char *f1, char *f2);
void display();
void readfile(char *f1,char *f2);
void keyboard(unsigned char c, int x, int y);
void specialkeyboard(int c, int x, int y);

int main(int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(80,60);
   glutCreateWindow("First Program Today");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialkeyboard);

   init(argv[1],argv[2]);
//   readfile(argv[1],argv[2]);
   glutMainLoop();
}
void init(char *f1,char *f2)
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  it.x  = it.y  = it.z  = 0.0; 
  it.vx = it.vy = it.vz = 0.0; 
  it.theta = 0.0;                    // this is used
  it.phi   = 0.0;
  it.len   = 0.25;

  eye.x =  0.0;
  eye.y =  0.1;
  eye.z = -1.0;

  readfile(f1,f2);
}
void drawcar()
{

  int i;

  glPushMatrix();
  glColor3f(1.0,1.0,0.0);          // yellow
  glBegin(GL_LINES);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f( 50.0, 0.0, 0.0);    // x-axis
    glVertex3f(0.0, -50.0, 0.0);
    glVertex3f(0.0,  50.0, 0.0);    // y-axis
    glVertex3f(0.0, 0.0, -50.0);
    glVertex3f(0.0, 0.0,  50.0);    // z-axis
  glEnd();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
    for(i=0;i<linelist.nlines;i++){
      glVertex3f(linelist.lines[i].x1,linelist.lines[i].y1,linelist.lines[i].z1);
      glVertex3f(linelist.lines[i].x2,linelist.lines[i].y2,linelist.lines[i].z2);
    }
  glEnd();
  glPopMatrix();
}
void display()
{
   double xzlen;
   double dx,dy,dz;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2.0, 2.0,-2.0, 2.0,-2.0, 2.0);
   gluLookAt(eye.x,eye.y,eye.z,
             0.0, 0.1, 0.0,
             0.0, 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glLoadIdentity();
   glTranslatef(it.x, it.y, it.z);
   glRotatef(RAD2DEG(it.theta), 0.0, 1.0, 0.0);

   drawcar();
   
   glPopMatrix();
   glutSwapBuffers();
}
void keyboard(unsigned char c, int x, int y)
{
   switch(c){
     case 27: exit(0);
   }
}
void specialkeyboard(int kno, int x, int y)
{
   switch(kno){
     case GLUT_KEY_DOWN : eye.y -= 0.05; break;
     case GLUT_KEY_UP   : eye.y += 0.05; break;
     case GLUT_KEY_LEFT : it.theta += 0.05; break;
     case GLUT_KEY_RIGHT: it.theta -= 0.05; break;
   }
//   fprintf(stderr,"eye.y = %lf\n", eye.y);
   glutPostRedisplay();
}
void readfile(char *f1,char *f2)
{
FILE *fd1,*fd2;

  char *buf;
  int linecount = 1;
  double x,y,z;
  int i,v1,v2;
  size_t len = 0;
  ssize_t line;
  char *token;
  int nvertices;
  linelist.nlines = 0;
linelist.lines = malloc(CHUNK * sizeof(LINE));
  linelist.size = CHUNK;
    fd1 = fopen(f1,"r");
        if(fd1 == NULL)
           fprintf(stderr,"couldnot open .ply file for reading\n");
         else
           {
              while((line = getline(&buf,&len,(FILE*)fd1)) != -1)
                {
                fprintf(stderr,"Error %s",buf);
                     if(linecount == 3)
                     {
                     
                      token = strtok(buf," ");
                      if(token)
                      {
                        if(strcmp(token,"element") == 0)
                        {
                          token = strtok(0," ");
                          if(strcmp(token,"vertex") == 0)
                          {
                            token = strtok(0," ");
                            nvertices = atoi(token);
  //                fprintf(stdout,"token = %s",token);
  //                fprintf(stdout,"no of vertices = %d",nvertices);

                          }
                        }
                      }
                     }
                     if (linecount < 9) linecount++;
                     else if(linecount == 9) 
                      {

                            for(i = 0;i< nvertices; i++)
                              {
                                  fscanf(fd1,"%lf %lf %lf",&x,&y,&z);
                                  vertex[i].x = x;
                                  vertex[i].y = y;
                                  vertex[i].z = z;                                  
//fprintf(stdout,"****%lf,%lf,%lf\n",vertex[i].x,vertex[i].y,vertex[i].z);
                              }
                        linecount++;
                      }
                     else
                      {
                        break;
                      }   
                }
           }
            fclose(fd1);
            
       fd2 = fopen(f2,"r");
          if(fd2 == NULL)
              fprintf(stderr,"could not open f2 file\n");
          else 
            {
              while(fscanf(fd2,"%d %d",&v1,&v2) == 2) 
                {
                  if(linelist.nlines >= linelist.size) {
                    linelist.size += CHUNK;;
                    linelist.lines = realloc(linelist.lines, linelist.size * sizeof(LINE));
                   }
                   linelist.lines[linelist.nlines].x1 = vertex[v1].x;
                   linelist.lines[linelist.nlines].y1 = vertex[v1].y;
                   linelist.lines[linelist.nlines].z1 = vertex[v1].z;
                   linelist.lines[linelist.nlines].x2 = vertex[v2].x;
                   linelist.lines[linelist.nlines].y2 = vertex[v2].y;
                   linelist.lines[linelist.nlines].z2 = vertex[v2].z;
                   linelist.nlines++;
                fprintf(stdout,"real %lf\n",linelist.lines[linelist.nlines].x1);            

                fprintf(stdout,"vertices %lf\n",vertex[v1].x);
               }
             fclose(fd2);
           }
  }
