#include<stdio.h>
int main(){
  float total_val = 0.0;
  int n, i, temp;
  
  printf("enter number of integers : ");
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &temp);
    total_val += temp; // Same as total_val = total_val + temp
  }
  
  printf("The average is %f \n", total_val/n);
  
  //for Double value
  printf("The average is %lf \n", total_val/n);
}