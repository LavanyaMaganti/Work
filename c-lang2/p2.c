#include<stdio.h>
#include<string.h>

int mystrcmp(char *s1,char *s2);

int main()
{
  char s1[4096],s2[4096];

  scanf("%s",s1);
  scanf("%s",s2);
  
int  retval = mystrcmp(&s1[0],&s2[0]);

  printf("%d\n",retval);
/*  if(retval==0)
    printf("strings are equal\n");
 else if(retval==-1)
  printf("s1 is less than s2\n");
 else
   printf("s1 is greater than s2\n");
  */
}



int mystrcmp(char *s1,char *s2)
{
  int i=0;
  
  while(s1[i]!='\0' || s2[i]!='\0')
  {
  if(s1[i]==s2[i])
    return 0;
  else if(s1[i]<s2[i])
    return -1;
 else
  return 1;

i++;
}
}
