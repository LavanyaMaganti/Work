#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){

char date[11],input[11],*str;
int val,i,c=0,dat,month, year;;

scanf("%s",&date);

for(i=0;i<strlen(date);i++)
input[i]=date[i];

str=strtok(date," /");
while(str!=NULL)
{
val=atoi(str);
c++;
if(c==1)
dat=val;
else if(c==2)
month=val;
else if(c==3)
year=val;
str=strtok(0," / ");
}


if(0<=year<=999)
{
year=2000+year;
if(month==1 || month==3 ||  month==5 ||  month==7 ||  month==8 ||  month==10 ||  month==12)
{
if(dat<=31)
{
if(month<10 && dat<10)
printf("%d-0%d-0%d\n",year,month,dat);
else
printf("%d-%d-%d\n",year,month,dat);
}
else printf("%s is illegal",input);
}
else if(month==2 || month==4 || month==6 || month==9 || month==11)
{
if(dat<30)
{
if(month<10 && dat<10)
printf("%d-0%d-0%d\n",year,month,dat);
else
printf("%d-%d-%d\n",year,month,dat);
}
else printf("%s is illegal",input);
}
}
else printf("%s is illegal",input);
}

