#include<stdio.h>
#include<math.h>
#include<file.h>

#define MAX_LEN 10

FILE *fd;

int main()
{

int numerator,denominator,remainder,quotient;
char sWord,*line;

fd = fopen("input.txt","r");
while(!feof(fd))
   {
while(fgets(line,MAX_LEN,fd)!=NULL);
{
        printf("%s \n",line);
               }
                   fclose(fd);

/*
scanf("%d %d",&numerator,&denominator);

//scanf("%d",&denominator);

while(numerator !=0 && denominator !=0)
{

  if ( numerator >=  denominator)
    {
      
      remainder = numerator%denominator;
      quotient = numerator/denominator;
      printf("%d %d / %d\n",quotient,remainder,denominator);
      break;
    }
    
  else
    {
    
    printf("%d %d / %d\n",0,numerator,denominator);
    break;
    }
}*/
}
}
