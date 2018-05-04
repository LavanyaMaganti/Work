#include<stdio.h>

int main(){
  int n,i;
        printf("Enter n value\n");
        scanf("%d",&n);
        printf("Enter array values\n");
int arr[n];
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

int smallest;

   for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
          smallest=arr[i];
          arr[i]=arr[j];
          arr[j]=smallest;
        }
      }
    }
        for(i=0;i<n;i++)
        printf("%d\t",arr[i]);

        printf("Third largest number %d \n",arr[n-3]);
return 0;
}
