#!/usr/local/bin/node

/**
 * Reminder: For these programs you may not use any built in math functions
 * to find the mean or median values.  You may only use conditionals and
 * Boolean logic.
 */

/**
 * Create a function called max that takes 3 integer values and returns the 
 * largest of the three:
 */

function max(a,b,c){
  if(a>b && a>c)
    return a;
  else if(b>a && b>c)
    return b;
  else
  return c;
}




/*
function max(a,b,c) {
  if(a>b && a>c) {
    return a;
  } else if(b>a && b>c) {
    return b;
  }else {
    return c;
  }
}
*/


/**
 * Create a function called second that takes 4 integer values and returns the
 * second largest of the 4.  Hint: Find the largest of a,b,c or d and use
 * max() above to find the largest of the remaining three, that will be the
 * second largest.
 */

function second(a,b,c,d) {
  if(a>b && a>c && a>d) {
      return max(b,c,d);
  }else if(b>a && b>c && b>d) {
    return max(a,c,d);
  }else if(c>a && c>b && c>d) {
    return max(a,b,d);
  }else {
    return max(a,b,c);
  }
}

/**
 * Create a function called 'median' that takes 5 integer parameters and returns
 * the middle (or median) of the 5 values. Hint: Find the largest, then use
 * second() above to find the second largest of the remaining 4.
 */
function median(a,b,c,d,e) {
  if(a>b && a>c && a>d && a>e) {
    return second(b,c,d,e);
  }else if(b>a && b>c && b>d && b>e) {
    return second(a,c,d,e);
  } else if(c>a && c>b && c>d && c>e) {
    return second(a,b,d,e);
  }else if(d>a && d>b && d>c && d>e) {
    return second(a,b,c,e);
  }else 
    return second(a,b,c,d);
}




/**
 * Create a function called 'mean' that takes 5 integer parameters and returns
 * the average (or mean) value of the 5 values.
 */


function mean(a,b,c,d,e) {
return (a+b+c+d+e)/5;
}









/*
function mean(a,b,c,d,e) {
  return (a+b+c+d+e)/5;
}
*/

/**
 * Get 5 command line parameters as integers and call them 'a' through 'e':
 */
var a=parseInt(process.argv[2]);
var b=parseInt(process.argv[3]);
var c=parseInt(process.argv[4]);
var d=parseInt(process.argv[5]);
var e=parseInt(process.argv[6]);

/**
 * Do not modify below here:
 * Example input/output:
 * ./l5.js 13 7 18 2 5
 * The median is: 7
 * The mean is  : 9
 */
console.log("The median is: " + median(a, b, c, d, e));
console.log("The mean is  : " + mean(a, b, c, d, e));
