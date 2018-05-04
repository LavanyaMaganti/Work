
// AREAL PROGRM

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void calc(double area);

int main()  {

long area;
double side,a;

scanf("%lf",&a);
area=(double)a;
calc(area);
}


void calc(double area)
{
float side;
float len;
side=pow(area,0.5);
//printf("Area= %d\n",side);
len=4*side;
printf("%f\n",len);
}

