
#include "main.h"

GLuint readppm(char *filename, int wrap)
{
  GLuint texture;
  int i,j,k;
  int width, height, max;
  char b[K];
  char vers[K];
  unsigned char *data;
  FILE *fd;
  char *rv;

  fd = fopen(filename, "rb");
  if(fd == NULL){
    fprintf(stderr,"Cannot open %s\n",filename);
    exit(0);
  }
  rv = fgets(b,K,fd);   // reads the P6 line
  if(strncmp(b,"P6",2)){
    fprintf(stderr,"%s is not a P6 file\n", filename);
    exit(0);
  }
  rv = fgets(b,K,fd);   // reads the width-height line
  sscanf(b,"%d %d",&width,&height);
  rv = fgets(b,K,fd);   // reads the max line
  data = (unsigned char *) malloc(width * height * 3);
  k = fread(data, width * height * 3, 1, fd);
  fclose(fd);

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );

  free(data);
  return texture;
}
void readsequence(char *fname, SEQ *p)
{
  FILE *fd;
  int i,m,n;
  GLfloat t1,t2,t3,t4,t5;
  char buffer[K];

  fd = fopen(fname,"r");
  if(!fd){
    fprintf(stderr,"cannot open %s\n", fname);
    exit(0);
  }
  do fgets(buffer,K,fd); while(*buffer == '#');
  sscanf(buffer,"%d %d", &n, &m);
  fprintf(stderr,"seq: %d %d\n", n, m);
  p->lla = malloc(n * sizeof(GLfloat));
  p->rla = malloc(n * sizeof(GLfloat));
  p->ba  = malloc(n * sizeof(GLfloat));
  p->ds  = malloc(n * sizeof(GLfloat));
  p->dy  = malloc(n * sizeof(GLfloat));
  for(i=0;i<n;i++){
    do fgets(buffer,K,fd); while(*buffer == '#');
    sscanf(buffer,"%f %f %f %f %f", &t1, &t2, &t3, &t4, &t5);
    p->lla[i] = t1;
    p->rla[i] = t2;
    p->ba[i]  = t3;
    p->ds[i]  = t4;
    p->dy[i]  = t5;
    fprintf(stderr,"seq: %f %f %f %f %f\n", t1, t2, t3, t4, t5);
  }
  p->nframes = n;
  p->tpf     = m;
  fclose(fd);
}
