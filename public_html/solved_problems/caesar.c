//Caeser Cipher

#include<stdio.h>
#include<string.h>


int main()  {
  char msg[300],caesar[300],cipher[300];
  int i;

  printf("Enter message\n");

  fgets(msg,300,stdin);

  msg[strlen(msg)-1]='\0';

  printf("Message:%s",msg);

  for(i=0;i<strlen(msg);i++)
    {
//      cipher[i] = 122-(msg[i]-97);
  //    cipher[i]='\0';
    //  printf("Message:%s",cipher); 
      switch(msg[i]){
      
      case 'a':cipher[i] = 'z';
              break;
      case 'b':cipher[i] = 'y';
              break;
      case 'c':cipher[i] = 'x';
              break;
      case 'd':cipher[i] = 'w';
              break;
      case 'e':cipher[i] = 'v';
              break;
      case 'f':cipher[i] = 'u';
              break;
      case 'g': cipher[i] = 't';
              break;
      case 'h': cipher[i] = 's';
              break;
      case 'i': cipher[i] = 'r';
               break;
      case 'j': cipher[i] = 'q';
               break;
      case 'k': cipher[i] = 'p';
               break;
      case 'l': cipher[i] = 'o';
               break;
      case 'm': cipher[i] = 'n';
               break;
      case 'n': cipher[i] = 'm';
               break; 
      case 'o': cipher[i] = 'l';
               break;
      case 'p': cipher[i] = 'k';
               break;
      case 'q': cipher[i] = 'j';
               break;
      case 'r': cipher[i] = 'i';
               break;
      case 's': cipher[i] = 'h';
               break;
      case 't': cipher[i] = 'g';
               break;
      case 'u': cipher[i] = 'f';
               break;
      case 'v': cipher[i] = 'e';
              break;
      case 'w': cipher[i] = 'd';
               break;
      case 'x': cipher[i] = 'c';
                break;
      case 'y': cipher[i] = 'b';
               break;
      case 'z': cipher[i] = 'a';
              break;
    }

    }
printf("Message:%s:",cipher);
 }

