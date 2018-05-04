#include<stdio.h>
#include<string.h>

int finalseq(char s[], char z[], int len1, int len2);


void main ()
{
char s[]="ATCGGTT";

char z[]="TCGGT";

int len1 = strlen(s);

int len2 = strlen(z);

if(finalseq(s,z,len1,len2)==len2)

printf("z is a sub-seq of s\n");

else

printf("z is not a sub-seq of s\n");

}

int finalseq(char s[], char z[], int len1, int len2)

{

int ch=0,d=0;

if(len1==0 || len2==0||(len1==0 && len2>0) || (len1>0 && len2==0))
  return ch;
  if(d==1)
  return ch;
else if (s[len1-1]==z[len2-1])

{

ch=ch+1;
finalseq(s,z,len1-1,len2-1);


}

else

finalseq(s,z,len1-1,len2);

}
