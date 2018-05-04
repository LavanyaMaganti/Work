
#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
  char buf[BUFSIZ];
    int i;
      
        printf ("Enter your number: ");
          
            if (fgets(buf, sizeof(buf), stdin) != NULL)
              {
                  i = atoi(buf);
                      printf ("You entered %d\n", i);
                        }  
                          
                            return(0);
                            }
