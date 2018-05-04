//1. Decimal -> Binary
// 2. Binary -> Decimal

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<string.h>

void decimal_binary (int n);
void binary_decimal (int n);

int
main ()
{
  int choice, dno;
  int bno;
  printf ("Welcome! Select an option:\n");
  printf ("1:Decimal to Binary.\n");
  printf ("2:Binary to Decimal.\n");
  printf ("Enter Choice:");
  scanf ("%d", &choice);
  //do
//  {
  if (choice == 1)
    {
      printf ("Enter a Decimal number: ");
      scanf ("%d", &dno);
      decimal_binary (dno);
//    break;
    }
  if (choice == 2)
    {
      printf ("Enter a Binary  number: ");
      scanf ("%d", &bno);
      binary_decimal (bno);
      //  break;
    }


}

//while(choice!=1 && choice!=2)
//{
//printf("Invalid choice. Re-enter the choice :\n");
//printf("1. Decimal to Binary.\n");
//printf("2.Binary to Decimal.\n");
//scanf("%d",&choice);
//}

//}


void
decimal_binary (int n)
{
  int q, i, d = 0, x, a, count = 0;
  int remainder[10], binary[10];
  for (i = 0; n != 1; i++)
    {
      a = n / 2;
      remainder[i] = n % 2;
      n = a;
      count = count + 1;
    }
  binary[0] = n;
  d = count + 1;
  q = count - 1;
  for (i = 1; i < d; i++)
    {
      binary[i] = remainder[q];
      q = q - 1;
    }
printf ("Equivalent binary number for %d is",n);

  for (i = 0; i < d; i++)
    {
    printf ("%d", binary[i]);
    }
    printf("\n");
}

void
binary_decimal (int bno)
{
  int temp = 0, i, j, x = 1, decimal = 0, z;
//j=strlen(m);
//for(i=0;i<j;i++)
  z = bno;
  while (z > 0)
    {
//temp=((pow(2,i)*m[j])+temp);
//j=j-1;

      temp = z % 10;
      decimal = decimal + temp * x;
      z = z / 10;
      x = x * 2;
    }
  printf ("Equivalent decimal number for %d is %d\n", bno, decimal);
}
