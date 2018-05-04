#!/usr/local/bin/node

/**
 * Open and reads the file given as the first command line argument and put
 * its contents into "data", then decode data as a JSON encoded string and store
 * the result in the variable 'a':
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * Loop through the array 'a' and find the smallest and largest value within and
 * print them out.
 * Example input/output:
 * ./l9.js testdata
 * smallest = -488
 * largest  = 486
 */

var a=JSON.parse(data);
var min=a[0];
var max=a[1];

for(var i=1;i<a.length;i++){
if(min>a[i])
  min=a[i];

if(max<a[i])
  max=a[i];

}

console.log("smallest = "+min);
console.log("largest = "+max);
