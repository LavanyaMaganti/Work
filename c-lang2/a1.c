#include<stdio.h>
#include<string.h>

int main()
{
  int number,count=1;

  printf("Enter the number\n");
  scanf("%d",&number);

  for(int i=2;i<number-1;i++)
  {
    if(number%i==0)
    {
      count++;
    }
  }
  if(count>1)
    printf("not prime\n",number);
  else
    printf("prime\n",number);
return 0;
}
