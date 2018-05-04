#include<stdio.h>

int main()      {

int a;

printf("Enter the number\n");

scanf("%d", &a);

if (a>0)
{
printf("%d is +ve\n",a);

}

else if (a<0)
{
printf("%d is -ve\n",a);
}
else
printf("%d is 0\n");
}

