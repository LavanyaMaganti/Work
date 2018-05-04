#!/usr/local/bin/node

/**
 * The following loads a dictionary of words into the string data:
 */
const fs = require("fs");
var data = fs.readFileSync("/usr/dict/words", {encoding: 'utf8'});

/**
 * Split the string data into words using the split() method on data using
 * "\n" as the deliminator.  Assign the result to the variables "words":
 */

var words = data.split('\n');
//var words = ["abc","xyz","testdata", "a", "b"];

/**
 * Assign the variable 'word' the string that is the first command line
 * parameter.
 */
var word = process.argv[2];


/**
 * Loop through words looking to see if 'word' is found in the list of words.
 * If it is, print "Found", if it isn't, print "Not found". Hint: Use a variable
 * as a flag (i.e. true or false) if the word is found.  You can use "break" to
 * exit the loop early if you do find the word.
 */
var i=0;

var flag = false;

while(words[i] != undefined){
if (words[i] == word){ flag = true;break;}
else { 
i++;
}
}

if(flag == true)
    console.log("Found");
else
    console.log("Not found");
