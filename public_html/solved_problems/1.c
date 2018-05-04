#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<ctype.h>

#define MAX 200
#define ADD 2 
#define SUB 1 
#define MUL 4 
#define DIV 3
#define EXP 5

int prec (char);
int eval(char a, int list1, int list2);

int main (int argc, char *argv[])
{
  int i,res,j;
  char *a;
  int list[200];
  int top = -1, len,up=-1,num,num1;		//Stack is Empty

  char temp[5];
  if (argc < 4)
    {
      printf ("Invalid Format. Expected ./a.out A + B\n");
      exit (0);
    }

  char *stack, *output;
  stack = (char *) malloc (200);	//This is equivalent to stack[argc] 
  output = (char*) malloc(200); //This is equivalent to stack[argc] 
  for (i = 1; i < argc; i++)
    {
      if (isalpha (argv[i][0]) || isdigit (argv[i][0]))
	{
	  strcat (output, " ");
	  strcat (output, argv[i]);
	}
      else if (strcmp (argv[i], "(") == 0)
	{
	  top++;
	  stack[top] = argv[i][0];
	}
      else if (strcmp (argv[i], ")") == 0)
	{
	  while (stack[top] != '(')
	    {
	      temp[0] = ' ';
	      temp[1] = stack[top];
	      temp[2] = '\0';
	      strcat (output, temp);
	      top--;
	    }
	  top--;
	}
      else
	{			//Its an Operator. Do something
	  while (top != -1 && (prec (argv[i][0]) < prec (stack[top])))
	    {
	      temp[0] = ' ';
	      temp[1] = stack[top];
	      temp[2] = '\0';
	      strcat (output, temp);
	      top--;
	    }
	  top++;
	  stack[top] = argv[i][0];
	}
    }				//End of For
  //While stack not empty put everything to the end of output 
  while(top != -1)
  { 
  temp[0] = ' '; 
  temp[1] = stack[top]; 
  temp[2] = '\0'; 
  strcat (output, temp);
  top--;
}
char b;
printf ("Postfix Expression: %s\n", output);
printf("%s\n",output[0][0]);
a=strtok(output," ");
 while (a != NULL)
     {//
//printf("%s\n",a);
strcpy(a,b);
//char b=(char)a;
//printf("%c",b);
if(isdigit(b))
{
num=b;
num1=num-48;
//printf("%d",*a);
//printf("num=%d\n",num1);
//up=up+1;
list[++up]=num1;
//for(i=0;i<=up;i++)
//printf("list*** %d\n",list[i]);
}
else
{
//x=list[up];
//y=list[up-1];
res=eval(*a,list[up],list[up-1]);
//printf("%d %c %d %d\n",list[up],*a,list[up-1],res);
up=up-2;
up++;
list[up]=res;
//for(i=0;i<=up;i++)
//printf("list %d\n",list[i]);

}
a = strtok (0, " ");
}

printf("result: %d\n",res);
}

int prec (char a)
{
  switch (a)
    {
    case '+':
      return ADD;		//2 
      case '-': return SUB; //1 
      case '*': return MUL; //4 
      case '/': return DIV; //3 
      case '%': return EXP; //3 
      case '(': return 0; //3
    }
}


int eval(char a, int list1, int list2)
{
int res;
//printf("a= %c\n",a);
//printf("list1 %d\n",list1);
//printf("list2 %d\n",list2);
if(a=='+'){
res = list2+list1;
//printf("%d %c %d %d\n",list2,a,list1,res);
return res;
}
else if(a=='-')
{
res=list2 - list1;
//printf("%d %c %d %d\n",list2,a,list1,res);
return res;
}
else if(a=='/')
{
res=list2 / list1;
//printf("%d %c %d %d\n",list2,a,list1,res);
return res;
}
else if(a=='*')
{
res=list2 * list1;
//printf("%d %c %d %d\n",list2,a,list1,res);
//printf("3*2 %d",res);
return res;
}
else if(a=='%')
{
res=list2 % list1;
//printf("%d %c %d %d\n",list2,a,list1,res);
return res;
}
}


