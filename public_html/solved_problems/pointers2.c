#include<stdio.h>


int main()  {

int x=1,y=2,z[10];

int *ip,*iq,*ir;

ip=iq=ir=&x;
y=*ip;
*ip=0;
ip=&z[0];

*ir=10;
*iq=20;

}
