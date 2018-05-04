// Fermat's Theorem

#include<stdio.h>
#include<math.h>


int
main ()
{

  int p, x;

  printf ("Enter the number\n");
  scanf ("%d", &p);

//Formula: a^(p-1) mod p=1
//let a=2 and p=entered number
  x = pow (2, p - 1);

  if ((x % p) == 1)
    {
      printf ("%d is PRIME NUMBER\n", p);

    }

  else
    {
      printf ("%d is NOT PRIME\n", p);
    }

}
