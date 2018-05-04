#!/usr/local/bin/node


/**
 * Save the first command line argument as an integer into a variable called n
 */
var n=parseInt(process.argv[2]);


/**
 * Output a n x n multiplication table.  Each number should have a space in
 * between them.
 * 
 * Example input/output:
 * ./l7.js 4
 * 1 2 3 4
 * 2 4 6 8
 * 3 6 9 12
 * 4 8 12 16
 */
var str= " ";
for(var i=1;i<=n;i++){
 var k=1;
var res ="";
    for(var j=1;j<=n;j++){

if(j<n){
        //str +=(k*i);
        res +=(k*i)+str;//          console.log(k*i + " ");
          k++;
   }
   
   else{
   res+=(k*i);
   k++;
   }
    }
console.log(res);
}






