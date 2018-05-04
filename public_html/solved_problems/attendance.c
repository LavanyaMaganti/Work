#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CMD "finger > out.txt"
#define MAX 1024

int main(int argc, char *argv[])  
{
system(CMD);          //EXECUTE THE COMMAND

FILE *fd;
char buffer[MAX];
char c,*p;
int x=0;

fd=fopen("out.txt","r");              //OPEN THE OUTPUT FILE

if(fd==NULL)
{
fprintf(stderr,"something went wrong!\n");
exit(0);
}

while((c=fgetc(fd))!=EOF)
{
buffer[x++]=c;
p=strtok(buffer," " );
printf("%s",p);
}

}
