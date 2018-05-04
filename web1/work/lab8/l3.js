#!/usr/local/bin/node

/**
 * Get two integers from the command line, 'n' and 'm' and "sum" all the numbers
 * from n to m inclusive.  This problem is much like l2.js
 * 
 * Reminder, use only a while loop for these problems.
 *
 * Example input/output:
 * ./l2.js 5 1
 * The sum of the numbers from 5 to 1 is: 15
 */

var n=parseInt(process.argv[2]);
var m=parseInt(process.argv[3]);
var start=Math.min(n,m);
var end=Math.max(n,m);
var result=0;
while(start <= end)
{
result = (result + start);
start++;
}
console.log("The sum of the numbers from "+ n +" to " + m +" is: " +result);









