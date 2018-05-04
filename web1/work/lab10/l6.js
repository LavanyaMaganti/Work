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

//var a=[5,4,6,8,9];

/**
 * Go through the array of numbers and find the longest sequence of increasing
 * numbers.
 * For this problem you'll need to keep track of the previous value and
 * increment a counter when the current value is greater than the last or reset
 * it back to one if it isn't. Keep track of the maximum value of count using
 * another variable.
 * Example input/output:
 * ./l6.js testdata
 * Longest sequence of increasing numbers: 5
 */

var prev=a[0];
var counter=0;
var max=0;
for(var i=1;i<a.length;i++) {

  if(a[i]>prev){
    prev=a[i];
    counter++;
  }
 else{ 
   prev=a[i];
  counter=1;
  }

  if(counter>max) max=counter;


}

console.log("Longest sequence of increasing numbers: " + max);




