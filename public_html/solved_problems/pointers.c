#include<stdio.h>
void swap(int *a,int *b);

int main() {

int a,b,*p,*q;

//char c='x';
//char *r;

a=10;
b=20;

swap(&a,&b);

printf("a:%d,b:%d",a,b);

}

void swap(int *p,int *q)
{

int temp;

temp=*p;
*p=*q;
*q=temp;

}



/*
void swap(int a,int b)
{

int temp;

temp=a;
a=b;
b=temp;

}
*/

