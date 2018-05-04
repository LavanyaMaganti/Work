#!/usr/local/bin/node

/**
 * Leave the following code, use "data" below.
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * Using the file input in data above, count the number of spaces, the number
 * of numbers and the number of letters and return a count for each of them.
 *
 * Example input/output:
 * ./l7.js l6.js
 * Spaces : 147
 * Letters: 571
 * Numbers: 6
 */

var index=0,ch;
var scount=0,ncount=0,lcount=0;

while(ch=data[index++]){

if(ch == " ") scount++;
else if(ch == "0" || ch == "1" || ch == "2" || ch == "3" || ch == "4" || ch == "5" || ch == "6" || ch == "7" || ch == "8" || ch =="9") ncount++;
//else if(ch != "0" || ch != "1" || ch != "2" || ch != "3" || ch !="4" || ch != "5" || ch != "6" || ch != "7" || ch != "8" || ch != "9" || ch != " ") 
lcount = index-ncount;
}

console.log("Spaces : " + scount);
console.log("Letters : " + lcount);
console.log("Numbers : " + ncount);














