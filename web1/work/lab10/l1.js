#!/usr/local/bin/node

/**
 * Save the first command line argument as an integer into a variable called n,
 * and the second command line argument as an integer into a variable called m.
 */

var n=parseInt(process.argv[2]);
var m=parseInt(process.argv[3]);

/**
 * Make a box of *'s that is n columns by m rows in size:
 * Example input/output:
 * ./l1.js 5 4
 * *****
 * *****
 * *****
 * *****
 */

for(var i=0;i<m;i++) {
var b='';
  for(var j=0;j<n;j++){
  b=b+'*';
  }
  console.log(b);
//console.log("\n");
}

