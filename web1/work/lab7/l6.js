#!/usr/local/bin/node

/**
 * The only built-in functions you may use for this assignment is Math.floor()
 * and parseInt().
 */
/**
 * Create four functions called 'days', 'hours', 'minutes' and 'seconds' that
 * when given a number of seconds returns numerically how many days, hours
 * (minus days), minutes (minus hours and days) or seconds (minus minutes/hours/
 * and days) it represents.  Note that there are 86400 seconds in a day and 3600
 * in an hour.  The functions should return an integer number of days/hours/
 * minutes/seconds (not a fractional number.)  Use Math.floor(x) to get the
 * integer portion of x.
 */

function days(a) {
return Math.floor(a/86400);
}

function hours(a) {
return Math.floor((a-(days(a)*86400))/3600);
}

function minutes(a) {
return Math.floor((a-(days(a)*86400)-(hours(a)*3600))/60);
}

function seconds(a) {
return Math.floor(a-(days(a)*86400)-(hours(a)*3600)-(minutes(a)*60));
}




/**
 * Get two command line parameters as integers, call them 'a' and 'b':
 */

var a=parseInt(process.argv[2]);
var b=parseInt(process.argv[3]);


/**
 * If b is less than a, switch a and b so that a is less than b.
 */

if(b<a) {
var temp =a;
  a=b;
  b=temp;
}



/**
 * Do not modify anything below this:
 * Example input/output:
 * ./l6.js 1000 340593
 * The difference in time is: 3 days, 22 hours, 19 minutes, 53 seconds
 */
var dt = b-a;
console.log("The difference in time is: " +
  days(dt) + " days, " +
  hours(dt) + " hours, " +
  minutes(dt) + " minutes, " +
  seconds(dt) + " seconds");
