#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 1024

long hash (int c);
void selection_sort();

struct node
{
  int key;
  int count;
} htable[TABLE_SIZE];

void print_table ();

int main (int argc, char *argv[])
{
  FILE *fd;
  char c;
  int hval;
  int i;
  int ch;
  /*if (argc < 2)
    {
      fprintf (stderr, "Expected Filename.\n");
      exit (0);
    }*/
  fd = fopen ("sample.txt", "r");

  if (fd == NULL)
{
      fprintf (stderr, "File Does not Exist.\n");
      exit (0);
    }
  while ((c = fgetc (fd)) != EOF)
    {
      //chcount++;
      ch = c;
      hval = hash (ch);
//  printf("%c",ch);
//  printf ("%d \t %c\t%d\n",c, c, htable[hval].count);
      if (htable[hval].count == 0)
  {
    htable[hval].key = ch;
    htable[hval].count++;
  }
      else if (htable[hval].key == ch)
  {
    htable[hval].count++;
  }

    }

selection_sort();
print_table ();
//printf("%c %d\n",htable[hval].key,htable[hval].count);

}

long hash (int c)
{
  long x, i, result = 0;
  long a = 1, inc = 2;
  x = c - 96;
  result = (result + c * a);
  a = a * inc;
  result = result % TABLE_SIZE;
  return result;
}


void selection_sort ()
{
  int temp, i, j, position;
  int temp_char;
  for (i = 0; i < TABLE_SIZE; i++)
    {

      for (j = i + 1; j < TABLE_SIZE; j++)
  {
    if (htable[i].count < htable[j].count)
  {
    temp = htable[i].count;
   temp_char=htable[i].key;
    htable[i].count = htable[j].count;
    htable[i].key=htable[j].key;
   htable[j].count = temp;
   htable[j].key=temp_char;
  }
}
    }
}

void print_table ()
{

  int i;
  for (i = 0; i < TABLE_SIZE; i++)
    {
      if (htable[i].key == 32)
        {
          printf ("sp\t%d\n", htable[i].count);
        }
      else if (htable[i].key == 10)
        printf ("nl\t%d\n", htable[i].count);
      else if (htable[i].count != 0)
        printf ("%c\t%d\n", htable[i].key, htable[i].count);
    }
}
