#include<stdio.h>
#include<string.h>

int finalstring(char s[], char z[],int len1,int len2);


void main()
{

char s[]="ATCGGTT";

char z[]="TCGTA";

int len1=strlen(s);

int len2=strlen(z);

if(finalstring(s,z,len1,len2)==len2)
  printf("z is a sub-str of s");

else
  printf("z is not a sub-str of s");

}

int finalstring(char s[], char z[],int len1,int len2)
{
int flen=len1-len2;
int a,b,ch;

for(a=0;a<=flen;a++)

{

char ch =0;

for(b=a;b<a+len2;b++)

{

if(s[b]==z[b-a])

{

ch=ch+1;

  if(ch==len2)

    return ch;

}

}

}

}
