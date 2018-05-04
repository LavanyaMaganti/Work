#include <stdio.h>

/**
 * Modify the code example 1.2p9.c in the following ways:
 * 1) Print miles/kilometers instead of the Fahrenheit/Celsius.
 * 2) Print column headings for the Miles and Kilometers columns.
 * 3) Miles will be an integer from 10 to 300 in steps of 10 and Kilometers
 *    should a floating point value that is printed to 2 decimal places.
 * Example output:
 * Miles:  Kilometers:
 * 10      16.09
 * 20      32.19
 * 30      48.28
 * 40      64.37
 * ...
 * 300     482.80
 */

int main(){

	printf("Miles:\tKilometers:\n");	  
	
	int miles=10;
	float kilometers;
	for(miles=10;miles<=300;miles+=10) {
	kilometers=miles*1.60934;
	printf("%d\t%.2f\n", miles,kilometers);
	}
	return 0;
}