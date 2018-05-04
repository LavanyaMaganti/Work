#include<stdio.h>
#include<stdlib.h>

typedef struct student {

char fname[30];
char lname[30];
char g1[2],g2[2],g3[2];
char csid[7];
float gpa;

}ST;

void add_student();
void del_student();
void print_student();

ST cs559[39];
int student_count=0;

int main() {

int ch;

while(1)
  {
printf("1.ADD\n  2.DEL\n 3. PRINT \n Enter Choice:");
scanf("%d",&ch);

switch(ch)
      {
case 1: add_student();
        break;
//case 2: del_student();
  //      break;
//case 3: print_student();
        break;
//case 4: return;
default: printf("Invalid Choice\n");
        break;
      }
  }
return 0;
}


void add_student() {

printf("Enter Firstname: ");
scanf("%s",cs559[student_count].fname);
printf("Enter Lastname:");
scanf("%s",cs559[student_count].lname);
printf("Enter grad 1:");
scanf("%s",cs559[student_count].g1);
printf("Enter grad 2:");
scanf("%s",cs559[student_count].g2);
printf("Enter grad 3:");
scanf("%s",cs559[student_count].g3);

}
