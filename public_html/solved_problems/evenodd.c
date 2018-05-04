#include<stdio.h>

int
main ()
{
  int a, b, x[50], max;
  int c = 0, d = 0, z;

  printf ("Enter positive number\n");
  scanf ("%d", &a);

  while (a != 1)
    {

      for (int i = 0; a != 1; ++i)
	{

	  if (a % 2 == 0)
	    {
	      x[i] = a;
	      a = a / 2;
	      printf ("%d\n", a);
	      c = c + 1;
	    }
	  else
	    {
	      a = (a * 3) + 1;
	      x[i] = a;
	      printf ("%d\n", a);
	      d = d + 1;
	    }
	}

      z = c + d;
      max = x[0];

      for (int j = 0; j < z; j++)
	{

	  if (x[j] > max)
	    {
	      max = x[j];
	    }
	}

      printf ("Maximum Number=%d\n", max);

    }

}
