#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 50
#define SIZE 200
typedef struct stack
{
  int data[MAX];
  int top;
} stack;

int precedence (char);
void init ();
int empty ();
int full ();
int pop ();
void push (int);
int top ();
void infix_to_postfix (char infix[], char postfix[]);
      //void calculator(char);
void evaluate (char *postfix[]);

stack *s;

void
main ()
{

  char infix[SIZE], *postfix[SIZE];
  printf ("Enter an infix expression: ");
  gets (infix);
  init ();
  infix_to_postfix (infix, postfix);
  printf ("\nPostfix expression: %s\n", postfix);
  evaluate (*postfix);

}



void
infix_to_postfix (char infix[], char postfix[])
{

  char x, token, k = ' ';
  int i, j;

  j = 0;

  for (i = 0; infix[i] != '\0'; i++)
    {
      token = infix[i];
      if (token == ' ')
	;
      else if (isalnum (token))
	{
	  postfix[j++] = token;
	  if (!isdigit (infix[i + 1]))
	    postfix[j++] = k;
	}
      else if (token == '(')
	push ('(');
      else if (token == ')')
	while ((x = pop ()) != '(')
	  {
	    postfix[j++] = x;
	    postfix[j++] = k;
	  }
      else
	{
	  while (precedence (token) <= precedence (top ()) && !empty ())
	    {
	      x = pop ();
	      postfix[j++] = x;
	      postfix[j++] = k;
	    }
	  push (token);
	}
    }

  while (!empty ())
    {
      x = pop ();
      postfix[j++] = x;
      postfix[j++] = k;
    }

  postfix[--j] = '\0';
}

int
precedence (char x)
{
  if (x == '(')
    return (0);
  if (x == '+' || x == '-')
    return (1);
  if (x == '*' || x == '/' || x == '%')
    return (2);

  return (3);
}

void
init ()
{
  s = (stack *) malloc (sizeof (struct stack));
  s->top = -1;
}

int
empty ()
{
  if (s->top == -1)
    return (1);

  return (0);
}

int
full ()
{
  if (s->top == MAX - 1)
    return (1);

  return (0);
}

void
push (int x)
{
  s->top = s->top + 1;
  s->data[s->top] = x;
}

int
pop ()
{
  int x;
  x = s->data[s->top];
  s->top = s->top - 1;
  return (x);
}

int
top ()
{
  return (s->data[s->top]);
}

void
evaluate (char *postfix)
{
  char *pch;
  int num;
  // int buff[20];
  int i, val1, val2;
  //init(&s);
  pch = strtok (postfix, " ");
  while (pch != NULL)
    {
      if (isdigit (pch[0]))
	{
	  printf ("pch: %s", pch);
	  num = atoi (pch);
	  printf ("num: %d", num);
	  push (pch[0]);
	  //push((int)pch);
	  printf ("%s\n", atoi (pch));
	}			//buff[j++]=(int) strtol(pch, (char **)NULL, 10);
      //printf("%d\n", top());
      //pch = strtok (NULL, " ");}
      //pch = strtok (NULL, " ");
      /*
         j=0; 
         for (i = 0; i < strlen (postfix); i++)
         {

         if (postfix[i] == ' ')
         ;
         else if (isdigit (postfix[i]))
         push (postfix[i] - '0');
         // push((int)pch);//push(token-'0');
       */

      else
	{
	  //token=pch;
	  val1 = top ();
	  printf ("%d\n", val1);
	  pop ();
	  val2 = top ();
	  printf ("%d\n", val1);
	  pop ();

	  //while()
	  switch (pch[0])
	    {
	    case '+':
	      push (val2 + val1);
	      break;
	    case '-':
	      push (val2 - val1);
	      break;
	    case '*':
	      push (val2 * val1);
	      break;
	    case '/':
	      push (val2 / val1);
	      break;
	    }
	  //if(strcmp(pch, '+')==0)
	  //  push(val2 + val1);


	}

      pch = strtok (NULL, " ");
    }
  printf ("\n\nResult: %d\n", top ());
}
