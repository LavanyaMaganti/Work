#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void add_element ();
void print_list ();
void del_element ();
typedef struct node
{
  char key[MAX];
  struct node *next;
} NODE;
NODE *list = NULL;		//List is Empty int main(int argc, char *argv[]){

int ch;
while (1)
  {
    printf ("1:Add\n2:Del\n3:Print\n4:Exit\nEnter Choice: ");
    scanf ("%d", &ch);

    switch (ch)
      {
      case 1:
	add_element ();
	break;
      case 2:
	del_element ();
	break;
      case 3:
	print_list ();
	break;
      case 4:
	exit (0);
      default:
	printf ("Invalid choice\n");
      }
  }
}

void add_element ()
{
  char buf[MAX];
  NODE *temp, *p;
  printf ("Enter Key Value: ");
  scanf ("%s", buf);
  if (list == NULL)
    {				//List is empty.
      list = (NODE *) malloc (sizeof (struct node));
      strcpy (list->key, buf);
      list->next = NULL;
    }
  else
    {
      p = list;
      temp = (NODE *) malloc (sizeof (struct node));
      while (p->next != NULL)
	p = p->next;

      strcpy (temp->key, buf);
      p->next = temp;
    }
}



void print_list ()
{
  NODE *p;
  p = list;
  if (list == NULL)
    {
      printf ("List is Empty.\n");
      return;
    }
  while (p != NULL)
    {
      printf ("%s ", p->key);
      p = p->next;
    }
  printf ("\n");
}




void del_element ()
{
  char buf[MAX];
  NODE *prev, *cur, *tmp;
  printf ("Enter Key Value to Delete: ");
  scanf ("%s", buf);
  if (list == NULL)
    {
      printf ("List is Empty.\n");
      return;
    }
  prev = cur = list;

  while (cur != NULL)
    {

      if (strcmp (cur->key, buf) == 0)
	{
	  if (prev == cur)
	    {
	      tmp = list;
	      list = list->next;
	      free (tmp);
	      return;
	    }
	  prev->next = cur->next;
	  free (cur);
	  return;
	}
      prev = cur;
      cur = cur->next;
    }
  printf ("Key not found!.\n");
  return;
}
