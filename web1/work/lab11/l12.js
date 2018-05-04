#!/usr/local/bin/node

var primes = [ 2 ];

/**
 * Create a function called isprime that takes a number as a parameter called
 * 'n'. Using Math.sqrt() find the square root of the number 'n' passed to the
 * function and add one to it and save that number as a local variable called
 * 'sq'.  Using  the primes global array above check if the number given is
 * divisible by the numbers in prime up to 'sq' (i.e. if the number you're
 * looking at in primes is > than sq, break out of the loop.)
 * If any of the numbers in primes evenly divides 'n', return false, otherwise
 * return true.
 */

function isprime(n){
  
  sq= Math.sqrt(n)+1;
  
//  if(n > sq)
  //break;
  if(n%sq ==0){
  return false;
  }
  else 
  return true;

}


/**
 * Get the first command line argument as a integer and save it in 'n':
 */

var n= parseInt(process.argv[2]);

/**
 * Starting at 3, check all the odd numbers less than n to see if they're prime
 * by calling isprime, passing it the current number you're checking. If the
 * number is prime, add it to the end of the primes global array.
 */

var snum=3;

while (snum<n){
if (isprime(snum)=="true")
  primes.push(snum);

snum+2;
}

/**
 * Print out the size of the 'primes' array, which is equal to the number of
 * primes <= n:
 * Example input/output:
 * ./l12.js 100
 * # primes <= 100 is 25
 */

console.log(primes.length);
