#!/usr/local/bin/node

/**
 * The only built-in functions you may use for this assignment is parseInt().
 */
/**
 * Create a function called max that takes two parameters and returns the larger
 * of the two as its return value.
 */

function max(a,b) {
  if(a>b)
    return a;
 else 
    return b;
}



/*
function max(a,b) {
  if(a>b) {
    return a;
  }
  else {
    return b;
  }
}

*/



/**
 * Create a function called min that takes two parameters and returns the
 * smaller of the two as its return value.
 */

function min(a,b) {
  if(a<b)
    return a;
 else
    return b;
}



/*function min(a,b) {
  if(a<b) {
    return a;
  }
  else {
    return b;
  }
}
*/


/**
 * Get two command line arguments as integers and store in them in 'a' and 'b'
 */

var a=parseInt(process.argv[2]);
var b=parseInt(process.argv[3]);







/*
var a=parseInt(process.argv[2]);
var b=parseInt(process.argv[3]);
*/

/**
 * Do not modify anything below here:
 * Example input/output:
 * ./l4.js 5 10
 * The maximum is: 10
 * The minimum is: 5
 */
console.log("The maximum is: " + max(a, b));
console.log("The minimum is: " + min(a, b));
