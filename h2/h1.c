/**
 * Create a main function that:
 * - Reads a character from stdin and outputs that character. If the character
 *   is a lowercase letter however it should output the uppercase version of
 *   that letter.
 * Example input/output:
 * ./h1
 * test
 * TEST
 */
#include<stdio.h>

int main(){
	
	char ch;
	printf("Enter the string\n");
	while(ch !=EOF){
	scanf("%c",&ch);
	if(ch >='a' && ch <= 'z') {
		ch-=32;
		printf("%c",ch);
	}

	}
return 0;
}

