#include<stdio.h> include<string.h> define MAX_WORDS 10 define WORDS_LEN 5
char list[MAX_WORDS][WORDS_LEN + 1];	//My list of words void selection_sort(); void word_generator(); void main () {
int i, k, n, low, mid, high, found;
char key[WORDS_LEN + 1];
word_generator ();		//Generating Random Words printf("Sorted Array\n"); for (n = 0; n < 
MAX_WORDS;
n++) printf ("%s\n", list[n]);
printf ("Enter Key to Search: ");
scanf ("%s", key);
low = 0;
high = MAX_WORDS - 1;
found = 0;
while (found == 0)
  {
    mid = (low + high) / 2;
    if (strcmp (key, list[mid]) == 0)
      {
	printf ("Key Found\n");
	found = 1;		// Or use break
      }
    else if (strcmp (key, list[mid]) < 0)
      {
	high = mid - 1;
      }
    else
      {
	low = mid + 1;
      }
    if (low > high)
      {
	printf ("Key Not Found\n");
	return;
      }
  }				//End of While
}

void word_generator ()
{
  int i, k, n;
  char x;
  srand ((unsigned) getpid ());
  for (k = 0; k < MAX_WORDS; k++)
    {
      for (n = 0; n < WORDS_LEN; n++)
	{
	  i = 'a' + rand () % 26;
	  x = i;
	  list[k][n] = x;
	}
      list[k][n] = '\0';
    }
}

void selection_sort ()
{
  int i, j;
  int n_min = 0;
  char c_min[WORDS_LEN + 1];
  char temp[WORDS_LEN + 1];
  strcpy (c_min, list[0]);
  for (i = 0; i < MAX_WORDS - 1; i++)
    {
      for (j = i + 1; j < MAX_WORDS; j++)
	{
	  if (strcmp (list[i], list[j]) > 0)
	    {
	      strcpy (temp, list[i]);
	      strcpy (list[i], list[j]);
	      strcpy (list[j], temp);
	    }
	}
    }
}
