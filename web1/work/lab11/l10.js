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
 * Loop through the array and find the _second_ smallest value within and print
 * it out.
 * Example input/output:
 * ./l10.js testdata
 * -481
 */

var min=smin=a[0];

for(var i=1;i<a.length;i++){

  if(a[i]<min){
    smin=min;
    min=a[i];
  }
  else if(a[i] < smin) {
  smin=a[i]
  }
}
console.log(smin);
