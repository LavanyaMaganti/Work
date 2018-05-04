#!/usr/local/bin/node

/**
 * Open and read the file given as the first command line argument and put
 * it's contents into "data":
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * data above is a JSON encoded string of an array of numbers, use the
 * JSON.parse() method to turn it back into an array of numbers stored in the
 * variable a:
 */

var a=JSON.parse(data);

/**
 * Go through the array of numbers and sum (add together) the positive and
 * negative numbers in the array separately.  Print out the result.
 * Example input/output:
 * ./l8.js testdata
 * +sum = 14578
 * -sum = -9922
 */

var Nsum=Psum=0;
for(var i=0;i<a.length;i++){

  if(a[i]<0)
    Nsum += a[i];
 else
    Psum += a[i];
}

console.log("+sum = "+ Psum);
console.log("-sum = "+ Nsum);
