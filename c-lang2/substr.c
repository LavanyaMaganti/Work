#include<stdio.h>
#include<string.h>

int substr(char a[],char b[], int alen, int blen);

int main()
{

  char S[20];// = "ATCGTACT";
  char Z[20];// = "CGT";
  
  printf("Enter the sequences\n");
  scanf("%s",&S);
  scanf("%s",&Z);
  
  int Slen = strlen(S);
  int Zlen = strlen(Z);

 if(Slen == 0)
    printf("S is empty");
  else if(Zlen == 0)
    printf("Z is empty");
  
if(substr(S,Z,Slen,Zlen) == Zlen)
  printf("\n %s is a sub-string of %s\n",Z,S);
return 0;
}


int substr(char a[],char b[],int alen,int blen)
{
  
  int len = alen-blen;
  int j,i;
  int c;
    for(i=0;i<=len;i++)
    { 
      for(j=i;j<i+blen;j++)
      {
        if(a[j] == b[j-i])
        {
//         printf("\n *** MATCHING *** %c %c\n",a[j],b[j-i]);
//         printf("\ni= %d j= %d j-i= %d C-VLAUE: %d\n",j,j-i,c);
          c++;
            if(c==blen)
              return c;
        }
  //    else
    //    printf("STRING COMPARISION %c %c\t",a[j],b[j-i]);
      }
      c=0;

    }

}
