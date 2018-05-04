#include<stdio.h>

int main()  {

//int i;

//for (i=0;i<10;i++)
//{

//printf (" Hello World\n");
//}


int i;

char arr[10];

for (i=0;i<10;i++)
{
printf("Enter the array:\n");
scanf("%c",&arr[i]);
}

for(i=0;i<10;i++)
{
printf("the array is:\n");
printf("%c",arr[i]);
}



}
