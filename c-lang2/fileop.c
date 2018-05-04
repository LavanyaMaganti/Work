

// file operation

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int main (int argc, char *argv[])
{
  int i;
  int j=0;
      char output[100];
          char* output1[100];
              char string[100];
                  char delims1[] = " ";
                      char delims2[] = "*";
                          char* result = NULL;
                              char* result3 = NULL;
                                  int num;
  FILE *f;
// READ OPERATION

  f = fopen ("input.txt", "r");
  if (f == NULL)
    {
      printf ("File Does not Exist.\n");
    exit (0);
    }
else
{

 while( fgets(string,sizeof(string),f) )
     {
             result = strtok( string, delims1 );
              while( result != NULL )
                 {
                   output1[i]=result;
                   printf("%s\n",output1[i]);
                   result = strtok( NULL, delims1 );
                   i++;
                 }
              for (num = 0; num < 100; i++ )      //
              {
                // Error On this array
               printf("%s\n", output1[i]);     //
              }                                   //
    }

}
  fclose (f);

}

