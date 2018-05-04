#include<stdio.h>

int main()
{

srand((unsigned)getpid());
char x;
int i,n,k,j;
char randomword[11];
char list[10][10];

for(k=0;k<10;k++)
{
for(j=0;j<10;j++)
{
 
i='a'+rand()%26;
x=i;
list[k][j]=x;
}
}
list[10][10]='\n';

for(k=0;k<10;k++)
{
for(j=0;j<10;j++)
{
printf("%c",list[k][j]);
}
printf("\n");
}

}
