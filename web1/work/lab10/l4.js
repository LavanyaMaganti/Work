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
var l=0,i;
  var b='';
//var k=(n+n-1);
  for(var j=n;j>0;j--) {

    var space='';
    var result='';

      for(var k=j-1;k>0;k--){
        space=space+' ';
      }

//      b+='*';


if(l>0)
    {
    b+='*';
  var c='';
   for(var i=0;i<b.length-1;i++){
   c+='*';
   }

 result=space+b+c;
  }
else{
    b+='*';
    result=space+b;
}
        l++; 

console.log(result);
  }




