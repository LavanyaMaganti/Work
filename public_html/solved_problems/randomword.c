#include<stdio.h>
main ()
{
  srand ((unsigned) getpid ());
  char x;
  int i, n, k;
  char randomword[11];
  char list[10][11];		//My list of words for (k = 0; k < 10; k++){
  for (n = 0; n < 10; n++)
    {
      i = 'a' + rand () % 26;
      x = i;
      list[k][n] = x;
    }
  list[k][n] = '\0';
  printf ("%s\n", list[k]);
}

for (n = 0; n < 10; n++)
  printf ("%s\n", list[n]);
}
