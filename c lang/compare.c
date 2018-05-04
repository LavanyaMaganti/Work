#include<stdio.h>

int main(){
  int a,b;
  
  //Statements missing in the slide
  printf("Enter two numbers: ");
  scanf("%d %d",&a,&b);
  
  if(a < b)
    printf("%d\n", -1);
  else if(a > b)
    printf("%d\n", 1);
  else
    printf("%d\n", 0);
}