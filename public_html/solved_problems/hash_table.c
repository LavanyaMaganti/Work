// Writing and implementing the Hash Function and creating and storing them in a Hash table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node
{
  char key;
  int count;
} NODE;


int
main (int argc, char *argv[])
{
  FILE *fd;
  if (argc < 2)
    {
      fprintf (stderr, "Expected Filename.\n");
      exit (0);
    }
  fd = fopen (argv[1], "r");

  if (fd == NULL)
    {
      fprintf (stderr, "File Does not Exist.\n");
      exit (0);
    }



}
