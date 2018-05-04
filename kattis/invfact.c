#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100000

int main()
{
  char n[MAX];
  long num,i=2,len;
  scanf("%s",&n);
len =strlen(n);
    num = atoi(n);

if(len < 11)
{
while(num !=1)
//for(i=2;num!=1;i++)
{
    num = num/i;
    i +=1;

  }
}
else
{
while(num !=1)
{
num = num/i;
i +=5;
}

}
printf("%d",i-1);  

}
