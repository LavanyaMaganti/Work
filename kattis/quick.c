#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 100000
int main()
{

    int N,n,count=0,j,a[100];
    char buf[MAX];
    int len[MAX],x[MAX];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
    scanf("%s",&buf);
    len[i] = atoi(buf);
    x[i]=strlen(buf);
    }
    for(int i=0;i<N;i++)
    {
    printf("%d\n",x[i]);
    }
}
