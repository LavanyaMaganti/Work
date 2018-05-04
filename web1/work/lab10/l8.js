#!/usr/local/bin/node

/**
 * Save the first command line argument as an integer into a variable called n
 */

var n= parseInt(process.argv[2]);

/**
 * Make a function called pad that is given a number as its only argument and
 * returns a string with the number formatted as a string that has been padded
 * on the left with spaces until the string is exactly 4 characters wide:
 * i.e.: pad(20) returns "  20" as a string.
 */

function pad(num){
if(num >99){
 var str = " " +num;
}
else if(num >9){
 str = "  "+num;
 }
 else { 
 str= "   "+num;
 }
return str;
}

function pad1(num){
if(num >99){
var str = " " +num;
}
else if(num >9){
 str = "  "+num;
 }
else {
  str = "   "+num;
}
return str;
}

/**
 * Output a formatted n x n multiplication table. Assume that all numbers are
 * right aligned to 4 spaces (using the pad function above):
 *
 * Hint:
 * The top two rows are separate loops to print the top numbers and the top
 * line. Below that will require a loop inside of a loop.  An outer loop for
 * each row and an inner loop for the columns.
 * example input/output:
 * ./l8.js 4
 *    *    1   2   3   4
 *     +----------------
 *    1|   1   2   3   4
 *    2|   2   4   6   8
 *    3|   3   6   9  12
 *    4|   4   8  12  16
 */

var top1="";
for(var i=0;i<=n;i++){
    if(i==0)
    top1 += pad("* ");
    else
    top1 += pad1(i);
}
    console.log(top1);




var top2="";
for(var i=0;i<4*n;i++){
if(i==1)
top2 += pad("+-");
     if(i<1)
     top2 += " "
     else
     top2+="-";
}
  console.log(top2);



var l=1;
for(var i=1;i<=n;i++){
  var col1r="";
  var k=1;
  var res ="";
    for(var j=0;j<=n;j++){
      if(j==0){
        col1r += pad(l);
        col1 = col1r+"|";
      }
    else{
      res+=pad(k*i);
      k++;
    }
}
  l++;
console.log(col1 + res);
}

