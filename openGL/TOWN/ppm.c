
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

  fd = fopen(filename, "rb");
  if(fd == NULL){
    fprintf(stderr,"Cannot open %s\n",filename);
    exit(0);
  }
  fgets(b,K,fd);   // reads the P6 line
  if(strncmp(b,"P6",2)){
    fprintf(stderr,"%s is not a P6 file\n", filename);
    exit(0);
  }
  fgets(b,K,fd);   // reads the width-height line
  sscanf(b,"%d %d",&width,&height);
  fgets(b,K,fd);   // reads the max line
  data = (unsigned char *) malloc(width * height * 3);
  k = fread(data, width * height * 3, 1, fd);
  fclose(fd);

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );

  free(data);
  return texture;
}
