#!/usr/local/bin/node

/**
 * Create a function called 'dprint' that takes one argument and prints it out
 * to the console log twice.
 */
/*
function dprint(a) {
  console.log(a);
  console.log(a);
}
*/

function dprint(a){
console.log(a);
console.log(a);
}


/**
 * Create a function call 'add' that takes two arguments, adds them together
 * then calls dprint defined above to print out the result.
 */
/*
function add(b,c) {
  r=b+c;
  dprint(r);  
}
*/

function add(a,b) {
//dprint(a+b);
var r=a+b;
dprint(r);
}

/**
 * Call the add function with the 2 and 3 command line arguments (stored in
 * process.argv[2] and process.argv[3] respectively.
 * Example input/output:
 * ./l3.js one two
 * onetwo
 * onetwo
 */

//add(process.argv[2],process.argv[3]);

add(process.argv[2],process.argv[3]);
