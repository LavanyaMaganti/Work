#!/usr/local/bin/node

/**
 * Complete the function foo below.  Make it take three parameters and return
 * the result of multiplying the first two and adding the third.
 */
function foo(a,b,c) {
return (a*b)+c;
}

/**
 * Don't modify anything below here:
 * Example input/output:
 * ./l1.js 2
 * 47
 */
var n = parseInt(process.argv[2]);
var r = foo(n,n+1,n+2) + foo(n+3,n+4,n+5);
console.log(r);
