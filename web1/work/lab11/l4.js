#!/usr/local/bin/node

/**
 * Get two integers from the command line, 'n' and 'm' and sum all the numbers
 * from n to m inclusive, then print the sum.
 *
 * Example input/output:
 * ./l4.js 5 1
 * 15
 */

var n=parseInt(process.argv[2]);
var m=parseInt(process.argv[3]);

var s=Math.min(n,m);
var e=Math.max(n,m);

var sum=0;

while(s<=e){
sum += s;
s++;
}

console.log(sum);
