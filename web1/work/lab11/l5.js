#!/usr/local/bin/node

/**
 * Get a real number from the first command line argument, call it 'n', and an
 * integer from the second, call it 'm'.  Make a loop that multiplies the first
 * number (n) by itself m number of times.  Print the result.  Do not use the
 * Math.pow() function, use a loop.
 *
 * Example input/output:
 * ./l5.js 5.5 4
 * 915.0625
 */


var n=parseFloat(process.argv[2]);
var m=parseFloat(process.argv[3]);
var c=1,res=1;

while(c<=m){
res *= n;
c++;
}

console.log(res);
