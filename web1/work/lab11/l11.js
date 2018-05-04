#!/usr/local/bin/node

/**
 * Open and read the file given as the first command line argument and put
 * it's contents into data:
 */
const fs = require("fs");
var data = fs.readFileSync(process.argv[2], {encoding: 'utf8'});

/**
 * Use the JSON.parse function to decode the string data into a JavaScript
 * array of objects called 'files', each element of which is an object of the
 * form:
 *   {name: <filename>, size: <filesize>}
 * 
 * Thus files[i].size would be the size of the i-th file in the array.
 */
var files = JSON.parse(data);
var maxL=files[0].size;
var fname;

for(var i=0;i<files.length;i++){
  if(maxL < files[i].size){
    maxL=files[i].size;
    fname=files[i].name;
  }
    

}
console.log(maxL +" " + fname);

/**
 * Search through the array of and print out the size of the largest file
 * followed by its name.
 * Example input/output:
 * ./l11.js testfiles
 * 4096 data
 */

