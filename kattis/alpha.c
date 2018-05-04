#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 10000
int main()
{

char s[MAX],c,l,wrd;
int i=0;


char *buffer;
size_t bufsize = 32;
size_t characters;
buffer = (char *)malloc(bufsize * sizeof(char));
if( buffer == NULL)
 {
   perror("Unable to allocate buffer");
   exit(1);
 }
 characters = getline(&buffer,&bufsize,stdin);

for(i=0;i<strlen(buffer);i++) {
if(isupper(buffer[i]))
{
buffer[i]=tolower(buffer[i]);
}
switch(buffer[i]){
case 'a':
printf("%c",'@');
break;
case 'b':
printf("%c",'8');
break;
case 'c':
printf("%c",'(');
break;
case 'd':
printf("|)");
break;
case 'e':
printf("%c",'3');
break;
case 'f':
printf("%c",'#');
break;
case 'g':
printf("%c",'6');
break;
case 'h':
printf("[-]");
break;
case 'i':
printf("%c",'|');
break;
case 'j':
printf("_|");
break;
case 'k':
printf("|<");
break;
case 'l':
printf("%c",'1');
break;
case 'm':
printf("[]\\/[]");
break;
case 'n':
printf("[]\\[]");
break;
case 'o':
printf("%c",'0');
break;
case 'p':
printf("|D");
break;
case 'q':
printf("(,)");
break;
case 'r':
printf("|Z");
break;
case 's':
printf("%c",'$');
break;
case 't':
printf("']['");
break;
case 'u':
printf("|_|");
break;
case 'v':
printf("\\/");
break;
case 'w':
printf("\\/\\/");
break;
case 'x':
printf("}{");
break;
case 'y':
printf("`/");
break;
case 'z':
printf("%c",'2');
break;
default:
printf("%c",buffer[i]);
break;
}
}

}

