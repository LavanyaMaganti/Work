// I will assume 0-ROCK, 1-PAPER, 2- SCISSORS


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()   {

int x,i;
time_t t;

srand((unsigned) time(&t));  //Setting system time as the random seed

char ans[10],comp[10];    //Reading in your answer

printf("ROCK PAPER SCISSORS!!\n");

char choice='y';

while(choice=='y')  {

x=rand()%3;

printf("ROCK\n");
sleep(1);
printf("PAPER\n");
sleep(1);
printf("SCISSORS\n");
sleep(1);
printf("GO!\n");
printf("Enter your choice:\n");
scanf("%s",ans);

//compare and write the conditions to see who wins

if ( strcmp(ans,"rock") == 0 && x==2) {

printf("YOU WIN!!\n");

}

else if ( strcmp(ans,"paper") == 0 && x==0) {

printf("YOU WIN!!\n");

}

else if ( strcmp(ans,"scissors") == 0 && x==1) {

printf("YOU WIN!!\n");

}

else
printf("YOU LOOSE\n");


printf("Do you want to continue? (Y/N):");
scanf("%c",choice);
}

printf("Thank yOu have a nice day\n");

}

//printf("RAND_MAX is %d\n", RAND_MAX);

//for(i==0;i<10;i++)
//{
//x=rand()%100;

//printf("x=%d\n",x);

//}
//}
