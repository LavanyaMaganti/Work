#!/usr/local/bin/node

/**
 * Take the first three command line parameters (a b and c), convert them to
 * an integer. They will be either zero or one.  Produce the output "pass"
 * or "fail" depending on the values of a, b and c using the following table:
 *
 * a | b | c | output
 *-------------------
 * 0 | 0 | 0 | "pass"
 * 0 | 0 | 1 | "fail"
 * 0 | 1 | 0 | "fail"
 * 0 | 1 | 1 | "fail"
 * 1 | 0 | 0 | "pass"
 * 1 | 0 | 1 | "pass"
 * 1 | 1 | 0 | "fail"
 * 1 | 1 | 1 | "pass"
 * 
 * Example input/output:
 * > ./l6.js 1 0 1
 * pass
 */

var a=parseInt(process.argv[2]);
var b=parseInt(process.argv[3]);
var c=parseInt(process.argv[4]);

if(a==0&&b==0&&c==0)
  console.log("pass");
else if(a==0&&b==0&&c==1)
  console.log("fail");
else if(a==0&&b==1&&c==0)
  console.log("fail");
else if(a==0&&b==1&&c==1)
  console.log("fail");
else if(a==1&&b==0&&c==0)
  console.log("pass");
else if(a==1&&b==0&&c==1)
  console.log("pass");
else if(a==1&&b==1&&c==0)
  console.log("fail");
else
  console.log("pass");
   
 









