#include<stdio.h>


int main(int argc, char *argv[])  {

/* int argc ---> no. of arguments passed.   

argumnets are seperated by space.
char *argv---> array of char pointers
argv[0]---> always contain file name

*/

int x;

if(argc==1) {

printf("No Argumetns passed\n");
exit(0);
}

for(x=0;x<argc;x++)
{
printf("argv[%d] is %s",x,*argv[x]);
}

}
