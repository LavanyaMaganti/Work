#!/usr/local/bin/node

/**
 * Create a function called max that takes three parameters and returns the
 * larger of the three as its return value.
 */

function max(a,b,c){
if(a>b && a>c)
return a;
else if(b>a && b>c)
return b;
else
return c;
}

/**
 * Create a function called min that takes three parameters and returns the
 * smallest of the three as its return value.
 */

function min(a,b,c){
if(a<b && a<c)
return a;
else if(b<a && b<c)
return b;
else
return c;
}


/**
 * Get three command line arguments as integers and store in them in 'a', 'b'
 * and 'c' respectively.
 */

var a=parseInt(process.argv[2]); 
var b=parseInt(process.argv[3]); 
var c=parseInt(process.argv[4]); 


/**
 * Output the minimum and maximum of the three command line arguments;
 * Example input/output:
 * ./l1.js 10 5 16
 * The minimum is: 5
 * The maximum is: 16
 */

console.log("The minimum is: " + min(a,b,c));
console.log("The maximum is: " + max(a,b,c));
