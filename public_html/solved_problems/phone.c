#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int
main ()
{
  char num[12], num1[10], ch;
  int i = 0, j = 0;
  int invalid = 1, c = 0;

//phone number

  printf ("Enter Phone number in this format 'xxx-xxx-xxxx':\n");
  scanf ("%s", &num);		//fgets(num,12,stdin);
  // printf ("entered num:%s\n", num);
  do
    {
      j = 0;
      invalid = 1;
      i = 0;
      for (i = 0; i < strlen (num); i++)
	{
	  if (num[i] != '-')
	    {
	      ch = num[i];
	      num1[j] = ch;
	      j++;
	    }
	}
      num1[j] = '\0';

      for (i = 0; i < strlen (num1); i++)
	{

	  if (isdigit (num1[i]))
	    {
	      c = c + 1;
	    }
	}
      // printf ("c:%d", c);
      for (i = 0; i < strlen (num1); ++i)
	{

	  if (strlen (num) == 12 && c == 10 && num[3] == '-' && num[7] == '-')
	    invalid = 0;


	}
      if (invalid == 0)
	break;

      fflush (stdin);
      printf ("Invalid format.Enter Number in xxx-xxx-xxxx format: ");
      scanf ("%s", &num);	//  fgets(num,12,stdin);

      c = 0;
    }
  while (1);

  printf ("Entered phone number %s is valid", num);


// SSN number

  printf ("\n Enter SSN number in xxx-xx-xxxx:\n");
  char ssn[11], ssn1[9], ch1;
  int f = 0, k = 0, valid = 1;
  scanf ("%s", ssn);
//fgets(ssn,10,stdin);

//printf("SSN number %s is valid:\n",ssn);
  do
    {
      k = 0;
      for (i = 0; i < strlen (ssn); i++)
	{
	  if (ssn[i] != '-')
	    {
	      ch1 = ssn[i];
	      ssn1[k] = ch1;
	      k++;
	    }
	}



      for (i = 0; i < strlen (ssn1); i++)
	{
	  if (isdigit (ssn1[i]))
	    {
	      f = f + 1;
	    }
	}

      for (i = 0; i < strlen (ssn1); ++i)
	{

	  if (strlen (ssn) == 11 && f == 9 && ssn[3] == '-' && ssn[6] == '-')
	    valid = 0;

	}
      if (valid == 0)
	break;

      fflush (stdin);
      printf ("Invalid format.Enter SSN in xxx-xx-xxxx format: ");
      scanf ("%s", &ssn);	//  fgets(num,12,stdin);

      f = 0;

    }
  while (1);

  printf ("Entered SSN Number %s is valid", ssn);



// ZIP code


  printf ("\nEnter 5 digit ZIP code:\n");

  char zip[5];
  int l, z;

  scanf ("%s", zip);

  do
    {
      z = 0;
      for (l = 0; l < strlen (zip); l++)
	{

	  if (isdigit (zip[l]))
	    {
//	      printf ("z:%d", z);
	      z = z + 1;
	    }
	}
      if (z == 5)
	break;
      //  printf ("Entered %s Valid ZIP code:\n",zip);

      //fflush(stdin);
      printf ("Invalid format. Enter 5 digit number:");
      scanf ("%s", &zip);

    }
  while (1);
  printf ("Entered %s Valid ZIP code:\n", zip);





// e-mail id


  printf ("Enter mail id in this format'xxxx@xxx.com'\n");
  char x[100];
  scanf ("%s", &x);
  int count = 0;
  int countp = 0;
  int a, b;
  int t, t2;
  int e = 0;
  do
    {


      for (a = 0; a < strlen (x); a++)
	{
	  if (x[a] == '@')
	    {
	      count++;
	      t = a;
	    }
	}



      if (count == 1)
	{

	  for (b = 0; b < t; b++)
	  {

	      if ((x[b] == '_' || isalpha (x[b]) || isdigit (x[b])))
	  	{
		  e = 0;
		  printf ("\nValid e-mail\n");
		  break;
		  }

	      else
		  printf ("Invalid e-mail\n");
	
	 }
//}


	  if (e == 0)
	    {
	
	      for (a = t; a < strlen(x) ; a++)
		{
	
		  if (x[a] == '.' && x[a + 1] == 'c' && x[a + 2] == 'o' && x[a + 3] == 'm')
		    {
		      t2 = a;
		      countp++;
		    }
	
		}
	//}
	
	      if (countp == 1)
		{
		
		  for (a = t; a < t2 ; a++)
		    {
		
		      if (isalpha(x[a]))
			{
			  e = 1;
			  printf ("\nValid e-mail\n");
			  break;
			}
		
		      else
			  e = -1;
			
	    }
	//}
		  if (e == 1)
   {
		      if (x[t2 + 4] != '\0')
			{
			  e = -1;
			  printf ("\nInvalid e-mail\n");
			break;
			}
   }

	}
	        else
	          {
	       e = -1;
	         printf ("\nInvalid e-mail\n");
	      break;
	        }
	    }
	}
      //  else
        //{
        //k = -1;
      if (c == 0 || c == 1)
	break;
      else
	{
	  printf("\nInvalid e-mail. Enter mail id in 'xxx@xxx.com' format\n");
	  //}
	  scanf ("%s", x);
	}
	//else break;
    }
  while (1);
}
