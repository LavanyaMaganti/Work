#include<stdio.h>
#include<string.h>

int main()
{

char str1[1000],str2[1000];
int i,acount1=0,acount2=0,hcount1=0,hcount2=0;
scanf("%s",str1);
scanf("%s",&str2);

while(str1 != '\0') {
for(i=0;i<1000;i++) 
{
if(str1[i] == 'a')
  acount1++;

else if (str1[i] == 'h')
  hcount1++;
}
}

while (str2 != '\0') {
if(str2[i] == 'a')
  acount2++;
else if (str2[i] == 'h')
  hcount2++;
printf("%d\n %d\n",acount1,hcount1);
}
}
if((acount1<1000 && hcount1<2)&& (acount2<1000 && hcount2<2))
{
if(strlen(str1) > strlen(str2))
printf("go");
else
printf("no");
}


}
