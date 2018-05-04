

// file operation

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main (int argc, char *argv[])
{
  char filename[100];
  char sentence[200];
  FILE *fd;
  printf ("Enter Filename followed by text: ");
  scanf ("%s", filename);

// READ OPERATION

  fd = fopen (filename, "r");
  if (fd == NULL)
    {
      printf ("File Does not Exist.\n");
    exit (0);
    }
else {
// WRITE OPERATION
fd = fopen (filename, "w");
fgets(sentence,200,stdin);
fputs(sentence,fd);
}
if (ferror (stdin))
    printf ("There was an error reading from stdin");
  
  

  fclose (fd);



}

