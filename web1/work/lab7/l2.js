#!/usr/local/bin/node

/**
 * Define a function called "rprint" that takes three parameters and prints them
 * out to the console log in reverse order (i.e. print the third argument first.)
 */
/*
function rprint(a,b,c) {
console.log(c);
console.log(b);
console.log(a);

}
*/

function rprint(a,b,c){
console.log(c);
console.log(b);
console.log(a);
}


/**
 * Don't modify the code below here:
 * Example input/output:
 * ./l2.js a b c
 * c
 * b
 * a
 */
rprint(process.argv[2], process.argv[3], process.argv[4]);
