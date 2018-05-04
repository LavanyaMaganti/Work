#include<stdio.h>
int main(){
  //n is missing in the slide
  int i, n, j;
  printf("Enter an integer number :");
  scanf("%d", &n);
  
  for(i = 1; i <= n; i++){
    for(j = 0; j <= n - i; j++)
      printf(" %d", j+1);
    printf("\n");
  }
  
  for(i = 1; i <= n; i++){
    for(j = 0; j <= n - i; j++)
      printf("* ");
    printf("\n");
  }
}