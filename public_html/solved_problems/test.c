// REVERSE ROT


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//void reverse(char string[]);
int main() {

int i,j=0,k,invalid=1;
char string[40],final[40];

printf("Enter String\n");

scanf("%s",&string);

k=strlen(string);
j=k-1;

for(i=0;i<k;i++)
{
if(isupper(string[i]) ||  string[i]=='_' || string[i]=='.')
invalid=0;

else
{
invalid=1;
break;
}
}


if(invalid==0)
{
for(i=0;i<k;i++)
 {
      final[j]=string[i];
          j=j-1;
   }
}
printf("\n%s\n",final);
}





