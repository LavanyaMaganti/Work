#!/usr/local/bin/node

/**
 * The only built-in functions you may use for this assignment is Math.pow and
 * parseInt().
 */

/**
 * Create a global variable called seed and set it to the integer value of the
 * first command line argument.
 */

var seed=parseInt(process.argv[2]);

/**
 * Create a function called "rand" that takes no parameters.  Rand should have
 * three local variables, set to the following:
 *   a = 1103515245
 *   b = 12345
 *   m = 2^32 (use Math.pow(x,y) to raise x to the yth power)
 * The function should set the global seed variable to the result of
 *   (a * seed + b) % m
 * then return the new value of seed as the return value of the function rand.
 */

function rand(){
a = 1103515245
b = 12345
m=Math.pow(2,32);
seed=(a*seed+b)%m;
return seed;
}





/**
 * Do not modify below this line:
 * Example input/output:
 * ./l8.js 100
 * 45
 * 84
 * 68
 * 36
 * 16
 */
console.log(rand() % 100);
console.log(rand() % 100);
console.log(rand() % 100);
console.log(rand() % 100);
console.log(rand() % 100);