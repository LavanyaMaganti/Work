#!/usr/local/bin/node

/**
 * Convert the first command line parameter to an integer using the parseInt()
 * function and save the result into a variable called 'n':
 */

var n=parseInt(process.argv[2]);

/**
 * Print out the value n, then then n squared (n times itself), then n cubed,
 * and finally n to the fourth power:
 * Example input/output:
 * > ./l1.js 5
 * 5
 * 25
 * 125
 * 625
 */

console.log(n);

console.log(n*n);

console.log(n*n*n);

console.log(n*n*n*n);



