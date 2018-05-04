#!/usr/local/bin/node

/**
 * Convert the first command line argument to an integer, then make a while loop
 * to print "Hello, world!" the number of times that the integer tells you to.
 *
 * Example input/output:
 * ./l1.js 3
 * Hello, world!
 * Hello, world!
 * Hello, world!
 */

var n=parseInt(process.argv[2]);

while(n!=0){
console.log("Hello, world!");
n--;
}



