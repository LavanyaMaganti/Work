#include<stdio.h>
#include<stdlib.h>


int  main() 
{

    int n,m,i,j;
    char T[50][50];

    scanf("%d",&n);
    scanf("%d",&m);

      for (i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
         scanf("%d",&T[i][j]);
        }
      }

      for (int i=0;i<n;i++)
      {
        for(int j==0;j<m;j++)
        {
         printf("%d",T[i][j]);
        }
      }
      
      
}
