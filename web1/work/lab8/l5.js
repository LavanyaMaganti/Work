#!/usr/local/bin/node

/**
 * Get the first three command line parameters as integers.  The first integer
 * represents the start, the second the end and the third numer the skip.
 * Print the numbers from the start until the end skipping every skip number
 * of numbers.
 *
 * Example input/output:
 * ./l3.js 2 11 3
 * 2
 * 5
 * 8
 * 11
 */

var start=parseInt(process.argv[2]);
var end=parseInt(process.argv[3]);
var skip=parseInt(process.argv[4]);

while(start <= end) {
console.log(start);
start = start + skip;
}






