// Recursion function



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void swap(char *x,char *y)  {

char temp;

temp=*x;

*x=*y;

*y=temp;

}


void permute(char *a,int i,int n) {

int j;

if(i==n)
{
printf("%s\n",a);
}

else {
for(j=1;j<n;j++)
{
swap(a+i,a+j) ;
permute(a,i+1,n);
swap(a+i,a+j);
}
}
}


int main() {

char a[MAX];

int i,len;

char temp;

i=0;

while((temp=getc(stdin))!='\n')
{
if(temp != ' ')
a[i++]=temp;
}

a[i]=0;     //a[i]='\0'

len=strlen(a);

permute(a,0,len-1);

return;
}
