#include<stdio.h>
#include<string.h>


int main()  {

char a;
int x,y;
float z;
double b;

a = 'C';
x = 89;
y = 70;
b = 70.890000;
z = 89.70;

printf("char- %c\nint - %d %d\nfloat - %f\ndouble - %lf\n", a,x,y,b,z);

scanf("%d %d",&x,&y);
printf("HELLO\n");
printf("int - %d %d\n", x,y);
scanf("%c\n", &a);
printf("char - %c\n",a);

}
