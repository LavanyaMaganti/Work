#!/usr/local/bin/node

/**
 * Use a while loop to determine how many command line arguments follow the 
 * command. process.argv[i] will be equal to undefined when you've gone beyond
 * the end of all the command line arguments.  Print out each command line
 * argument on its own line then a final count of the number.
 *
 * Example input/output:
 * ./l6.js a b c
 * a
 * b
 * c
 * argc = 3
 */

var i=2;
while(process.argv[i] != undefined)
{
console.log(process.argv[i]);
i++;
}
console.log("argc = "+(i-2));







