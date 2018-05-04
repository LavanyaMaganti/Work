#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define W_COUNT 23800
#define MAX_LEN 50
#define STA_LEN 2096

char *dict[W_COUNT];
char buffer[MAX_LEN];
int num_words;      //No of Words
char statement[STA_LEN];
void read_dictionary(char *);
void read_file(char *);
void spell_check ();
int word_search (char *),j=1;
int lno=1,wno=1;
int main (int argc, char *argv[])
{
  int i, c;
  if (argc < 2)
    {
      printf ("Expexted file name and dictionary filename\n");
      exit (0);
    }

  read_dictionary (argv[2]);
  read_file (argv[1]);
}

void read_dictionary (char *dictname)
{
  FILE *fd;
  int i = 0;
  fd = fopen (dictname, "r");
  while (fscanf (fd, "%s", buffer) != EOF)
    dict[i++] = strdup (buffer);
  num_words = i;
  fclose (fd);
}

void read_file (char *filename)
{
  FILE *fd;
  int j=1,i=0;
char a;
char line[MAX_LEN];

  fd = fopen (filename, "r");
  if (fd == 0)
    {
      printf ("Couldnot open file\n");
    }
/*
  else
    {
      while (fgets (buff, bufsize, fd) != NULL)
//      while (fgetc(fd) != NULL)
	{
///puts (buff);
	  a = strtok (buff, " ");
	  while (a != NULL)
	    {
	      //      spell_check (a);
	      printf ("%s\n", a);

	      while (a != '\n')
		{
		if (!}
		    a = strtok (0, " ");}
		    }
		    fclose (fd);
//    printf("\n");
		    }*/
else
{
while(a=(fgets(line,MAX_LEN,fd)!=NULL))
{
  printf("line: %s",line);
strcat(statement,line);
printf("STATEMENT:****** %s",statement);
//statement[i++]=tolower(a);
//statement[i]=0;
//printf("%s\n",line);
spell_check();
lno++;
//statement[strlen(statement)]=0;
memset(statement,0,strlen(statement));
}
}
}

		    void spell_check ()
		    {
		    char *str;
		    printf("STATEMENT %s",statement);
		    str = strtok (statement, " .,!-"); 
	      wno=0;
		    while (str != NULL)
		    {
		    wno++;
		    printf("STRING: %s\n",str);
		    if (!word_search (str))
		   {
		    printf("STR when not found %s",str);
		    printf ("line: %d \t word: %d \t %s \t Not found \n",lno,wno, str);
		   }
		    str = strtok (0, " .?,!-");
//		    wno=0;
		    }
		    }

		    int word_search (char *word)
		    {
		    int high, low, mid;
		     high = num_words - 1;
		    low = 0; 
		    int found = 0; 
//printf("word******** %s",word);
		    printf("found %d\n",found);

		    while (found == 0)
		    {
		    mid = (low + high) / 2;
//printf("word111111111111111111******** %s\n",word);
//printf("dict: %s\n",dict[mid]);
		    if (strcmp (word, dict[mid]) == 0) 
{        //found=1;
		    printf("STR when found %s\n",word);
  //      printf("dict:**** %s\n",dict[mid]);
//		    return 1;
        break;
}
		    else if (strcmp (word, dict[mid]) < 0) 
		    high = mid - 1;
		    else
		    low = mid + 1; 
		    if (low > high) 
		    return 0;
//		  break;  
		          
		  }
		    }

