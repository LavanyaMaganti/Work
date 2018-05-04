#include<stdio.h>
#include<string.h>

void string_comparee(char a[],char b[]);
void string_compare1(char a[],char b[]);

int main(){

char a[50],b[50];

printf("Enter string 'A'\n");
scanf("%s",&a);

printf("Enter string 'B'\n");
scanf("%s",&b);

printf("Entered strings:\n");
printf("a: %s \nb: %s\n",a,b);

string_compare1(a,b);
string_compare2(a,b);

return 0;
}


void string_compare1(char a[], char b[]){

if(strcmp(a,b)==0)
        printf("yes\n");
else
        printf("no\n");
}

void string_compare2(char a[],char b[]){

int i=0;

if(strlen(a)!=strlen(b))
        printf("*no\n");
else {
        while(a[i]!='\0'){
          if(a[i]!=b[i]){
            printf("**no\n");
            break;
         }
          i++;
        }
  } 
   
if(i==strlen(a)){
        printf("*yes\n");
}

}
