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

var a= JSON.parse(data);

/**
 * Go through the array of numbers and sum (add together) the positive numbers
 * in the array, keep a second sum of all the negative numbers. Print the
 * positive sum on one line followed by the negative sum on the next.
 * Example input/output:
 * ./l5.js testdata
 * 14578
 * -9922
 */

var padd=0;
var nadd=0;
for(var i=0;i<a.length;i++){

if(a[i] >= 0)
{
  padd += a[i];
}
else
 nadd += a[i];

}

console.log(padd);
console.log(nadd);

