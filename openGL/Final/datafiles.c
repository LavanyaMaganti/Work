
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

  glGenTextures(1, &texture );
  glBindTexture(GL_TEXTURE_2D, texture );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );
  free(data);
  return texture;
}

int istransparent(unsigned char b[])
{
  if(b[0] >  32) return 0;
  if(b[1] < 160) return 0;
  if(b[2] >  32) return 0;
  return 1;
}

GLuint readtransppm(char *filename, int wrap)
{
  GLuint texture;
  int i,j,k;
  int width, height, max;
  char vers[K];
  unsigned char b[K];
  unsigned char *data;
  int f;
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
  data = (unsigned char *) malloc(width * height * 4);
  k = 0;
  while(fread(b,3,1,fd) > 0){
    for(i=0;i<3;i++)
      data[k++] = b[i];
    if(istransparent(b))
      data[k++] =   0;
    else
      data[k++] = 255;
  }
  fclose(fd);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
  free(data);
  
  return texture;
}
