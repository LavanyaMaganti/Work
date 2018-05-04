#!/usr/local/bin/node

/**
 * Get the string from the first command line argument and store it in s:
 */

var s= process.argv[2];

/**
 * Use a loop to scan the string and keep a counter, initialized to zero.
 * If you encounter a '(' in the string, increment the counter.
 * If you encounter a ')' decrement the counter.
 * If the counter ever goes below 0, quit the loop and print "Unbalanced )"
 * If at the end of the string the counter is above zero, print "Unbalanced ("
 *   otherwise print "Balanced".
 */


var counter=0;
var i=0;

while(s[i]!=undefined){

    if(s[i] == "(")
      counter++;
   if(s[i] == ")")
      counter--;
i++;

}


if(counter > 0 )
  console.log("Unbalanced (");
else if(counter < 0) console.log("Unbalanced )");
else
  console.log("Balanced");



