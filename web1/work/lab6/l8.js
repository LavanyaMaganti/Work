#!/usr/local/bin/node


/**
 * we want to make an interest calculator, such as for a Mortgage. This requires
 * three command line parameters, the first is the principle value (PV), the
 * second the annual interest rate (APR), and the third the number of years for
 * the loan (years).  You may parseFloat all three values, although the year
 * will always be an integer so you could use parseInt() for it.
 * 
 * To make sure we've entered the information correctly, print the following:
 * Principle is: $##.## at ##.##% APR for ##.## years
 * 
 * The first ##.## is the PV, the second is the APR then finally years, all
 * rounded to two digits of precision.  We then must compute the number of
 * months for the loan, that just years * 12, and the monthly interest rate
 * (rate) which is the APR divided by 100 then by 12 again.
 * 
 * To calculate the monthly payment we use the following formula:
 *
 *                   rate * (1+rate)^months
 *    payment = PV * ----------------------
 *                    (1+rate)^months - 1
 * 
 * Then finally we compute the total number of payments (total) which is the
 * monthly payment (payment) * number of months (months). Once everything
 * has been computed, print out the monthly payment and total as:
 * 
 * Monthly payment is: $##.##
 * Total payments is : $##.##
 * 
 * Example input/output:
 * > ./l8.js 270000 3.09 15
 * Principle is: $270000.00 at 3.09% APR for 15.00 years
 * Monthly payment is: $1876.28
 * Total payments is : $337730.34
 */

var pv=parseFloat(process.argv[2]);
var apr=parseFloat(process.argv[3]); 
var years=parseInt(process.argv[4]);

console.log("Principle is: $"+pv.toFixed(2)+" at "+apr.toFixed(2)+"%"+" APR for "+years.toFixed(2)+" years");
var months=years*12;
var rate=(apr/100)/12;
var payment=pv*((rate*Math.pow((1+rate),months))/(Math.pow((1+rate),months)-1));
var total=payment*months;
console.log("Monthly payment is: $"+payment.toFixed(2));
console.log("Total payments is: $"+total.toFixed(2));

