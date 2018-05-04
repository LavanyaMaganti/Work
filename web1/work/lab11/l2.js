#!/usr/local/bin/node

/**
 * Get two integers from the command line, 'n' and 'm' and print all the numbers
 * from n to m inclusive  The starting number should be the smaller of the two
 * and the ending number the larger of n or m.  You may use Math.min() and
 * Math.max() for this problem. Reminder: Use only a while loop for these
 * problems.
 *
 * Example input/output:
 * ./l2.js 5 1
 * 1
 * 2
 * 3
 * 4
 * 5
 */


var n=parseInt(process.argv[2]);
var m=parseInt(process.argv[3]);

s=Math.min(n,m);
e=Math.max(n,m);

while(s<=e){
console.log(s);
s++;
}
