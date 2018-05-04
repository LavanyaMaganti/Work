#!/usr/local/bin/node

/**
 * Get the first command line argument and convert it to a floating point value
 * using the parseFloat() function and save the result in the variable called
 * f:
 */

var f = parseFloat(process.argv[2]);

/**
 * Make a variable called c that is f minus 32 times 5 over 9. (The Fahrenheit
 * to Celsius conversion formula):
 */

var c=(f-32)*5/9;

/**
 * Print out the f and c rounded to two decimal places, i.e. use c.toFixed(2) to
 * produce a string consisting of the value of c rounded to 2 digits.
 * Example input/output:
 * > ./l2.js 30.25
 * 30.25 degrees F = -0.97C
 */

console.log(f.toFixed(2)+" degrees F = "+c.toFixed(2)+"C");
