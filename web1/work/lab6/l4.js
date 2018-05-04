#!/usr/local/bin/node

/**
 * Convert the first command line parameter to an integer and if the number is
 * divisible 3 output "Fizz".  If the number is divisible by 5 output
 * "Buzz".  If it is divisible by both 3 and 5 output "FizzBuzz".  If it is
 * not divisible by either 3 or 5 just output the number itself.
 * Example input/output:
 * > ./l4.js 2
 * 2
 * > ./l4.js 15
 * FizzBuzz
 * > ./l4.js 5
 * Buzz
 */

var n=parseInt(process.argv[2]);

if(n%5==0 && n%3==0)
  console.log("FizzBuzz");
else if(n%3==0)
  console.log("Fizz");
else if(n%5==0)
  console.log("Buzz");
else
  console.log(n);








