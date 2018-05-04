#include<stdio.h>

int main(){
  int a,b,c;
  printf("Enter three numbers : \n");
  scanf("%d%d%d",&a,&b,&c);
  
  if(a < b)
    if(b < c)
      printf("Ordering %d,%d,%d\n", a, b, c);
    else if(c < a)
      printf("Ordering %d,%d,%d\n", c, a, b);
    else
      printf("Ordering %d,%d,%d\n", a, c, b);
  else if(c < b)
    printf("Ordering %d,%d,%d\n", c, b, a);
  else if(c < a)
    printf("Ordering %d,%d,%d\n", b, c, a);
  else
    printf("Ordering %d,%d,%d\n", b, a, c);
}