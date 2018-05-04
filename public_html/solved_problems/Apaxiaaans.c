// APAXIAAAANS! PRGRAM


#include<stdio.h>
#include<string.h>


int main()  {

char str[250],final[250];
int i,j=0;

scanf("%s",str);

//printf("%s",str);

for(i=0;i<strlen(str);i++)
{

if(str[i]!=str[i+1])
{
final[j]=str[i];
final[j+1]=str[i+1];
j=j+1;
}
}
printf("%s\n",final);
}
