#include<stdio.h>
#include<string.h>

int subseq(char a[],char b[], int alen, int blen);
int c=0;

int main()
{

  char S[20] ;//= "CTGAA";
  char Z[20] ;//= "TGAAA";

  printf("Enter sequences\n");
  scanf("%s",&S);
  scanf("%s",&Z);

  int Slen = strlen(S);
  int Zlen = strlen(Z);


 if(Slen == 0)
    printf("S is empty");
  else if(Zlen == 0)
    printf("Z is empty");
  

if(subseq(S,Z,Slen,Zlen) == Zlen)
  printf("%s is a sub-sequence of %s\n",Z,S);
else
  printf("%s is not a sub-sequence of %s",Z,S);

return 0;
}


int subseq(char a[],char b[],int alen,int blen)
{
  int  aindex = alen-1;
  int  bindex = blen-1;

   if((alen==0 && blen>0) || (alen>0 && blen==0) || alen==0 || blen==0)
      return c;
  else if(a[aindex]==b[bindex])
  {
//  printf("%d %d",alen,blen);
//  printf("\n");
//  printf("\n");
//  printf(" STRING MATCHING %c %c",a[aindex],b[bindex]);
//  printf("\n");
    c++;
    subseq(a,b,aindex,bindex);
    
  }

 else
  {
//    printf(" STRING NOT MATCHING %c %c\t",a[aindex],b[bindex]);
    subseq(a,b,aindex,bindex+1);
  }
}
