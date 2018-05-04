#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX 1000000
int numbers[MAX];
void populate_numbers (int n);
void print_numbers (int n);
void selection_sort (int n);

int main ()
{

  int n;
  srand ((unsigned) getpid ());

  printf ("Enter number of elements:");
  scanf ("%d", &n);

  while (n > MAX)
    {
      printf ("n should be less than a million.Enter n:");
      scanf ("%d", n);
    }

  populate_numbers (n);		//which populates my array with numbers

  selection_sort (n);

  print_numbers (n);

}


void populate_numbers (int n)
{
  int i;
  printf("Random Numbers generated\n");
   for (i = 0; i < n; i++)
    {
       numbers[i] = rand () % MAX;	// Random numbers
      printf ("%d\n", numbers[i]);
     }
//     printf("random numbers generated %s\n",numbers);
}


void print_numbers (int n)
{
  int i;
printf("Sorted list after selection sort:\n");
  for (i = 0; i < n; i++)
    {
      printf ("%d", numbers[i]);
     printf ("\n");

    }
}



void selection_sort (int n)
{
  int temp,i, j, position;
  for (i = 0; i < (n - 1); i++)
    {
      position = i;

      for (j = i + 1; j < n; j++)
	{
	  if (numbers[position] > numbers[j])
	    position = j;
	}
      if (position != i)
	{
	  temp = numbers[i];
	  numbers[i] = numbers[position];
	  numbers[position] = temp;
	}
    }

}
