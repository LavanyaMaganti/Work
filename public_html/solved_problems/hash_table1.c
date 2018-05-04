

// Writing and implementing the Hash Function and crating and storing them in a Hash table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 25
long hash (long c);
void selection_sort();
typedef struct node
{
  long key;
  int count;
} NODE;

NODE htable[TABLE_SIZE];
void print_table ();

int main (int argc, char *argv[])
{
  FILE *fd;
  char c;
  long hval = 0;
  int i, ch;
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
  while ((c = fgetc (fd)) != EOF)
    {
      //chcount++;
      ch = (long) c;
      hval = hash (ch);
//  printf("%d\n",ch);
//  printf ("%d \t %c\t%d\n",c, c, htable[hval].count);
      if (htable[hval].count == 0)
	{
	  htable[hval].key = ch;
	  htable[hval].count = 1;
	}
      else if (htable[hval].key == ch)
	{
	  htable[hval].count++;
	}

//printf("%c \n",htable[hval].key);

    }

//selection_sort();
  print_table ();
}

long hash (long c)
{
  long x, i, result = 0;
  long a = 1, inc = 2;
//      x = c - 96;
  result = (result + c * a);
  a = a * inc;
  result = result % TABLE_SIZE;
  return result;
}


void selection_sort ()
{
  int temp, i, j, position;
  for (i = 0; i < TABLE_SIZE-1; i++)
    {
      position = i;

      for (j = i + 1; j < TABLE_SIZE; j++)
	{
	  if (htable[position].count > htable[j].count)
	    position = j;
	}
      if (position != i)
	{
	  temp = htable[i].count;
	  htable[i].count = htable[position].count;
	 htable[position].count = temp;
	}
    }
for(i=0;i<TABLE_SIZE;i++)
{
if(htable[i].count!=0)
	printf("%c %d\n",htable[i].key,htable[i].count);
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
