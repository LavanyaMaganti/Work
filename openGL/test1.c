#include<stdio.h>
#include<stdlib.h>

#define CHUNK   4

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

LINELIST linelist;
VERTEX vertex[8];

int main(int argc, char *argv[])
{

char *buf;
int lcount = 1;
double x,y,z;
int i,v1,v2;
size_t len = 0;
ssize_t line;
FILE *fd1,*fd2;
linelist.nlines = 0;
linelist.lines = malloc(CHUNK * sizeof(LINE));
linelist.size = CHUNK;
  fd1 = fopen(argv[1],"r");
 if(fd1 == NULL)
   fprintf(stderr,"couldnot open .ply file for reading\n");
 else
   {
     while(line = getline(&buf,&len,(FILE*)fd1) != -1)
       {
          fprintf(stderr,"buf = %s.\n",buf);
          if(lcount < 9) { lcount++; }
          else if(lcount==9) 
            {
              if(linelist.nlines >= linelist.size){
                   linelist.size += CHUNK;
                   linelist.lines = realloc(linelist.lines, linelist.size * sizeof(LINE));
                }
              for(i = 0 ; i < 8 ; i++)
                {
                   fscanf(fd1,"%lf %lf %lf",&x,&y,&z);
                   vertex[i].x = x;
                   vertex[i].y = y;
                   vertex[i].z = z;
                   fprintf(stdout,"%lf %lf %lf\n",vertex[i].x,vertex[i].y,vertex[i].z);
                }
            }
          else { break;}
          fclose(fd1);
       }
   }
 fd2 = fopen(argv[2],"r");
    if(fd2 == NULL)
          fprintf(stderr,"couldnot open .ply file for reading\n");
     else
         {
           while(fscanf(fd2,"%d %d",&v1,&v2)== 2)
               {
                  linelist.lines[linelist.nlines].x1 = vertex[v1].x;
                  linelist.lines[linelist.nlines].y1 = vertex[v1].y;
                  linelist.lines[linelist.nlines].z1 = vertex[v1].z;
                  linelist.lines[linelist.nlines].x2 = vertex[v2].x;
                  linelist.lines[linelist.nlines].y2 = vertex[v2].y;
                  linelist.lines[linelist.nlines].z2 = vertex[v2].z;
                  linelist.nlines++;
                  fprintf(stdout,"%lf %lf %lf",linelist.lines[linelist.nlines].x1,linelist.lines[linelist.nlines].y1,linelist.lines[linelist.nlines].z1);
                  fprintf(stdout,"%lf %lf %lf\n",linelist.lines[linelist.nlines].x2,linelist.lines[linelist.nlines].y2,linelist.lines[linelist.nlines].z2);
               }
         }
 fclose(fd2);
 }
