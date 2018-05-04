
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
      printf ("Expected file name\n");
      exit (0);
    }
    else if(argc < 3)
    {
    printf ("Expexted dictionary filename\n");
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
else
{
while(a=(fgets(line,MAX_LEN,fd)!=NULL))
{
//printf("line: %s",line);
strcat(statement,line);
spell_check();
lno++;
memset(statement,0,strlen(statement));
}
}
}

		    void spell_check ()
		    {
		    char *str,*str1,ch,ch1;
		    int len=0,i;
		    str = strtok (statement, " .?,!-"); 
	      wno=0;

		    while (str != NULL)
		    {
		    wno++;
		    len=strlen(str);
for(i=0;i<len-1;i++)
{
ch1=str[i];
if(isupper(ch1))
{
str[i]=tolower(ch1);
}

}
ch=str[len-1];
if(!isalnum(ch))
	{
str[len-1]=0;
	}
		    if (!word_search (str))
		   {
		    printf ("word:%s line:%d word:%d\n",str,lno,wno);
		   }
		    str = strtok (0, " .?,!-");
		    }
   }


  int word_search (char *word)
		    {
		    int high, low, mid;
		    high = num_words ;
		    low = 0; 
		    int found = 0; 
 

        while (found == 0)
		    {
         mid=(low + high)/2;
   
          if(strcmp (word ,dict[mid])== 0)
          return 1;
          
      
          else  if (strcmp( word,dict[mid])<0)
                high = mid-1;
                else
                low = mid+1;
              		    
           if(low>high) return 0;
 
          } 
     }


