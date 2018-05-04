#!/usr/local/bin/node

/**
 * Get the first and second command line arguments as integers and store them
 * in the variables a and b:
 */

var a=process.argv[2];
var b=process.argv[3];


/**
 * If a is evenly divisible by b, then print that b evenly divides a (
 * substituting the actual values of a and b respectively).  Otherwise print
 * that: "b does not evenly divide a, remainder = x" where x is the remainder
 * of the integer division of a / b.
 * Example input/output:
 * > ./l3.js 10 2
 * 2 evenly divides 10
 * > ./l3.js 10 3
 * 3 does not evenly divide 10, remainder = 1
 */
var x=a%b;
if(x==0)
  console.log(b+" evenly divides "+a);
else
  console.log(b+" does not evenly divide "+a+", remainder = "+(x));


