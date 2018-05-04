#!/usr/local/bin/node

/**
 * Save the first command line argument as an integer into a variable called n.
 */

var n=parseInt(process.argv[2]);

/**
 * Print a left-aligned right angled triangle out of stars that is n rows high.
 * Example input/output:
 * ./l2.js 5
 * *
 * **
 * ***
 * ****
 * *****
 */


for(var i=0;i<n;i++){
var b='';
  for(var j=i+1;j>0;j--){
     b = b + '*';
  }
console.log(b);
}


