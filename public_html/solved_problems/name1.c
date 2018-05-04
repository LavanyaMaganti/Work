#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
 int main(){
 char num[12],num1[12],ch;
 int num_len,llen, i,j;
  int invalid = 0; // Set valid as 0
 printf("Enter Phone number in below format: ");
  printf ("Format: xxx-xxx-xxxx\n");
  scanf("%s",&num);
  //fgets(num,12,stdin);
      //Removing the \n at the end
  printf("entered num:%s\n",num);
  num_len = strlen(num);

 printf("num:%s\n",num);

for (i=0;i<strlen(num);i++) { if(num[i] != '-') { ch=num[i]; num1[j]=ch; j++; } } num1[j]='\0';
  do{
    
    invalid = 0;

//printf("new num:\n %s\n",num1);
    for(i=0;i<strlen(num);i++)
    {
    if(strlen(num1)==12 && isdigit(num1[i]) && num[3]=='-' && num[7]=='-') { 

    invalid = 0;

   }

   else invalid=1;
    
     if(invalid ==0)
  break;
}
  
    fflush(stdin);
   
    printf("Invalid format.Enter Number in xxx-xxx-xxxx format: ");
  scanf("%s",&num);  
//   fgets(num,11,stdin);
    num_len = strlen(num); //Removing the \n at the end.

  }
  while(1);
  {
   printf("Number %s is valid",num);
  }
  }

