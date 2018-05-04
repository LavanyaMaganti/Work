#include<stdio.h>

int main(){
  unsigned long int total_Val = 1;
  int x, y;
  
  printf("Enter two non-negative numbers x, y \n");
  scanf("%d%d", &x, &y);
  
  int i;
  for(i = 1; i <= y; i++){
    total_Val *= x;
  }
  
  //Statement missing in the slide
  printf("Total Value : %lu \n", total_Val); 
}