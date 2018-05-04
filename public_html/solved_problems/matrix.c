// matrix multiplication, addition and subtraction

#include<stdio.h>
#include<math.h>


int main()  {

int first[2][2],second[2][2],final[2][2];
int i,j,k,temp=0,choice;

printf("Enter elements of first mtrix:\n");
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
scanf("%d",&first[i][j]);
}
}


printf("Enter elements of second matrix:\n");
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
scanf("%d",&second[i][j]);
}
}


printf("1: ADD\n2: SUB\n3: MUL \n");
printf("Enter Choice:");
scanf("%d",&choice);


if(choice==1)
{

for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
final[i][j]=first[i][j]+second[i][j];
}
}
printf("Resultant Matrix after addition:\n");
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
printf("%d",final[i][j]);
printf("\t");
}
printf ("\n");
}
}


if(choice==2)
{
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
final[i][j]=first[i][j]-second[i][j];
}
}
printf("Resultant Matrix after subtraction:\n");
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
printf("%d",final[i][j]);
printf("\t");
}
printf ("\n");
}
}

if(choice==3)
{
// matrix multiplication
for(i=0;i<2;i++) {
temp=0;
for(j=0;j<2;j++) {
temp=0;
for(k=0;k<2;k++) {

temp=temp+first[i][k]*second[k][j];
}

final[i][j]=temp;
}
}

printf("Resultant Matrix after multiplication:\n");
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
printf("%d",final[i][j]);
printf("\t");
}
printf ("\n");
}
}


}
