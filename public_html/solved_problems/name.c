#include <stdio.h>
#include <string.h>


main(){

  char name[25] = "Chinmai";

  char first[25];
  char last[25];
  char full[25];

  printf("First: ");
  scanf("%s",&first);

  printf("Last: ");
  scanf("%s",&last);

  //String concatenate

  strcpy(name, first);
  strcat(name, " ");
  strcat(name,last);
  printf("Name: %s\n", name);

}

