#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//int valid_mail (char x[]);
int main ()
{
 
    
 printf ("Enter mail id in this format'xxxx@xxx.com'\n");
  char x[100];
  scanf ("%s", &x);
  int count = 0;
  int countp = 0;
  int i, j;
  int t, t2;
  int k = 0;
do {

  for (i = 0; i < strlen (x); i++)
    {
      if (x[i] == '@')
	{
	  count++;
	  t = i;
	}
    }


  if (count == 1)
    {
      for (j = 0; j < t; j++)
	{
	  if ((x[j] == '_' || x[j] == '.' || isalpha (x[j]) || isdigit (x[j])))
	    {
	      k = 0;
	      printf ("\nValid e-mail\n");
	      break;
	    }else printf("Invalid e-mail\n");
	}
      if (k == 0)
	{
	  for (i = 0; i > t; i++)
	    {
	      if (x[i] == '.' && x[i+1] == 'c' && x[i+2] == 'o' && x[i+3] =='m')
		{
		  t2 = i;
		  countp++;
		}
	    }
	  if (countp == 1)
	    {
	      for (i = 0; i < t2 && i > t2; i++)
		{
		  if (x[t2]=='.')
		    {
		      k = 1;
		      printf ("\nValid e-mail\n");
		      break;
		    }
		  else
		    {
		      k = -1;
		    }
		}
	      if (k == 1)
		{
		  if (x[t2 + 4] != '\0')
		    {
		      k = -1;
		      printf ("\nInvalid e-mail\n");
		    }

		}
	    }
//	  else
	//    {
	     // k = -1;
	   //   printf ("\nInvalid e-mail\n");
	  ///  }
	}
   }
//  else
  //  {
    //  k = -1;
 if(k==0 || k==1)
  break;
else {     printf ("\nInvalid e-mail. Enter mail id in 'xxx@xxx.com' format\n");
    //}
    scanf("%s",x);}
}
while(1);  
  }

  
