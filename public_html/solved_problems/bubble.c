// Bubble Sort

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


#define MAX 1000000
int numbers[MAX];
void populate_numbers(int n);
void print_numbers(int n);
void bubble_sort(int n);

int main() {

  int n;
  srand((unsigned) getpid());


  printf("Enter number of elements:");
  scanf("%d",&n);
//printf("%d\n",n);
  while (n>MAX) {
  printf("n should be less than a million.Enter n:");
  scanf("%d",n);
  
  }
  populate_numbers(n);    //which populates my array with numbers
//printf("hi %d\n",n);


  bubble_sort(n);
//printf("hii %d\n",n);

print_numbers(n);
//printf("hii %d\n",n);

}





void populate_numbers(int n)
{
 int i;
//printf("MAX %d \n",MAX); 
 for (i=0;i<n;i++)  {
//printf("i=%d\n",i); 
 numbers[i]=rand()%MAX; // Random numbers
printf("rand  numbers %d\n",numbers[i]); 
//printf("i=%d\n",i);

 }
}


void print_numbers(int n)
{
int i;
//printf("%d\n",numbers[0]);
//printf("%d\n",numbers[0]);
//printf("%d\n",numbers[1]);
//printf("%d\n",numbers[2]);

for (i=0;i<n;i++)
{
printf("%d",numbers[i]);
printf("\n");

}
}



void bubble_sort(int n)
{

int i,j,temp;

for (i=0;i<n-1;i++)
{

  for(j=0;j<n-1;j++)
    {
    if(numbers[j]>numbers[j+1])
      {
    temp=numbers[j];
    numbers[j]=numbers[j+1];                            //Swap function
    numbers[j+1]=temp;
      }
    }
 }


}
