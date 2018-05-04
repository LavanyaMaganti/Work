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
 * Loop through the array and find the _second_ smallest value within and print
 * it out.
 * Example input/output:
 * ./l2.js testdata
 * -481
 */
first = a[0];
second = a[1];
var i =0;

if(second  < first) {
  first = a[1];
  second = a[0];
}


while(a[i]!=undefined){

    if(a[i] < first) {
       second = first;
       first = a[i];
    }

    else if(a[i] < second) {
    second = a[i];
    }
    i++;
}

console.log(second);


