#include<stdio.h>
#include<string.h>

void strrev(char *str);

int main()
{
  char str[4096];

//  printf("ENter the string\n");

  while(fgets(str,sizeof str,stdin)!=NULL)
  {
    strrev(str);
  }

}


void strrev(char *str)
{
  int i=strlen(str)-1;
  
    while(i>=0)
    {
     printf("%c",str[i]);
     i--;
    }
printf("\n");  
}
