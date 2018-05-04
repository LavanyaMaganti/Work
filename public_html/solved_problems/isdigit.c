#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()   {
int i,valid=0;
char num[12];
printf("Enter number\n");
scanf("%s",&num);

for (i=0;i<strlen(num);i++)
{
if(!isdigit(num[i]) || num[3]!='-')
{
valid=1;
break;
}
}
if(valid==0)
printf("number is valid\n");
else
printf("number is invalid");

}
