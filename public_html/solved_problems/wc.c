#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define MAX_LEN 50
void line_number (char);
void word_number (char);
void char_number (char);
FILE *fd;
int main (int argc, char *argv[])
{
      int lno = 0, ch = 0,wno=0,invalid=1;;
      char c;

  if (argc < 2)
    {
      printf ("Expexted file name\n");
      exit (0);
    }
    else if(argc>2)
{    printf("Expected only one argument\n");
exit(0);
}
  fd = fopen (argv[1], "r");
  if (fd == 0)
    {
      printf ("Couldnot open file");
    }

  else
    {
    c=fgetc(fd);
      while (c!=EOF)
	{
	  ch++;
 if(c=='\n'){
     lno++;
     }
     
	  if(c==' '||c=='\t' || c=='\n')
  {
  wno++;
c=fgetc(fd);	  
ch++;
if(c==' ')
wno--;
 if(c=='\n'){
      lno++;
           }
           
}
    c=fgetc(fd);

	}
      printf (" %d %d %d %s\n", lno,wno,ch,argv[1]);
c='\0';

    }
  fclose (fd);
}

