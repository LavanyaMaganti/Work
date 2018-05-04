#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
void main(){
 char num[12],num1[12],ch;
  int num_len,llen, i,j=0;
    int invalid = 0,v; // Set valid as 0
     printf("Enter Phone number in below format: ");
       printf ("Format: xxx-xxx-xxxx\n");
         scanf("%s",&num);
           //fgets(num,12,stdin);
                 //Removing the \n at the end
                   printf("entered num:%s\n",num);
                     num_len = strlen(num);
                      printf("num:%s\n",num);
		       
		       do{
			                                   invalid = 0;
							   for(i=0;i<strlen(num1);i++)
								    {
									     if(isdigit (num1[i]) )
										      {
											        if(strlen(num)==12 && num[3]=='-' && num[7]=='-') {
													    invalid = 0;
													          }
												           else invalid=1;
													          if(invalid ==0)
															           break;
														        fflush(stdin);
															   printf("Invalid format.Enter Number in xxx-xxx-xxxx format: ");
															       scanf("%s",&num);
															         //   fgets(num,11,stdin);
																 //          }while(1);
																 //           {
																 //              printf("Number %s is valid",num);
																 //                }Y
																 //
