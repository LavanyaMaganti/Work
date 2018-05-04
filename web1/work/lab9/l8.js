#!/usr/local/bin/node

/**
 * Using the binary() function below make a function called octal that does
 * the same thing binary does, but converts the number to an octal (base 8
 * instead of base 2) string and returns that.
 * Note that an Octal number should have a leading "0" rather than a leading
 * "0b".
 */

function binary(n) {
  var b = "";
  for(var i=0; n > 0; i++) {
    b = (n % 2) + b;
    n = Math.floor(n/2);
  }
  return "0b" + b;
}


function octal(n) {
  var b = "";
  for(var i=0; n > 0; i++) {
    b = (n % 8) + b;
    n = Math.floor(n/8);
  }
  return "0" + b;
}


/**
 * Do it again and make a function called "hex" that returns the input number
 * as a hexadecimal string. Hint:
 *   var hexdigit = "0123456789ABCDEF";
 *   then hexdigit[n] where n is in the range 0 to 15 will give you the
 *   hexadecimal digit for n.
 * Note that a hex number should have a leading 0x:
 */


function hex(n) {
  var hexdigit = "0123456789ABCDEF";
  var b = "";
for(var i=0; n > 0; i++) {

c=n%16;

if(c >= 0 && c<= 15){
   b=hexdigit[c]+b; 
}

    n = Math.floor(n/16);
  
  }
  return "0x" + b;
}




/**
 * Using the above three functions (binary, octal and hex), get the first
 * command line argument as an integer and output the value in decimal,
 * hex, octal and binary respectively. Example input/output:
 * ./l3.js 53
 * Dec : 53
 * Hex : 0x35
 * Oct : 065
 * Bin : 0b110101
 */


var num=parseInt(process.argv[2]);
console.log("Dec : " +num);
console.log("Hex : " +hex(num));
console.log("Oct : " +octal(num));
console.log("Bin : " +binary(num));

