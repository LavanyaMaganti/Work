#!/usr/local/bin/node

/**
 * Opens and reads the file given as the first command line argument and puts
 * it's contents into "data":
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * data above is a JSON encoded string of an array of numbers, use the
 * JSON.parse() method to turn it back into an array of numbers stored in the
 * variable a:
 */

var a = JSON.parse(data);

var i=1;

var min = a[0];
/**
 * Loop through the array and find the smallest value within and print it out.
 * Example input/output:
 * ./l1.js testdata
 * -488
 */


while(a[i] != undefined){

if(min > a[i])
min = a[i];
i++;
}

console.log(min);


