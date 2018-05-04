#!/usr/local/bin/node

/**
 * The following code reads a file (file-name given as the first command line
 * parameter.  The files data is stored in the variable "data":
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * Using the string 'data', count the number of periods (.) and the number of
 * dashes (-) in data and print the count.
 * Example input/output:
 * ./l7.js l7.js
 * # of dots and dashes = 10
 */

var count=0,i=0;
while (data[i]!=undefined){
  
 // if(data[i] == "." || data[i] == "-"){
//  console.log(data[i]);
   if(data[i] == ".")
      count++;
// }
 i++;

}

console.log("# of dots and dashes = "+ count);
