// SPAVANAC PROGRAM

#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {

int H,M,min,hr,d;


if (scanf("%d", &H) != 1) {
                    printf("failed to read integer.\n");
                        }
                        if (scanf("%d", &M) != 1) {
                                            printf("failed to read integer.\n");
                                                }
if((0<=H<=23) && (0<=M<=59))
{
if(M<=45)
{
d=45-M;
M=60;
min=M-d;
if(min==60)
{

min=0;
}
if(H==0)
{

H=24;
hr=H-1;
}

else if(H>0)
{

hr=H-1;

}
}
}
printf("%d",hr);

printf(" %d\n", min);
return 0;
}
