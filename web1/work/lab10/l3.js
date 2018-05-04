#!/usr/local/bin/node

/**
 * Save the first command line argument as an integer into a variable called n.
 */

var n=parseInt(process.argv[2]);

/**
 * Print a right-aligned right angled triangle out of stars that is n rows high.
 * Example input/output:
 * ./l3.js 5
 *     *
 *    **
 *   ***
 *  ****
 * *****
 */

  var b='';

  for(var j=n;j>0;j--) {

    var space='';
    var result='';

      for(var k=j-1;k>0;k--){
        space=space+' ';
      }
      b+='*';
    result=space+b;
console.log(result);
  }




