#!/usr/local/bin/node

/**
 * Convert the first command line parameter to a floating point value and
 * then print the grade.  Use the following for the grade distribution:
 * 97+ A+	77+ C+
 * 93+ A	73+ C
 * 90+ A-	70+ C-
 * 87+ B+	67+ D+
 * 83+ B	63+ D
 * 80+ B-	60+ D-
 *	 < 50 F
 *
 * Example input/output:
 * > ./l5.js 98.4
 * Your grade = A+
 */


var grade=parseFloat(process.argv[2]);

if(grade>=97)
  console.log("Your grade = A+");
if(grade>=93 && grade<97)
  console.log("Your grade = A");
if(grade>=90 && grade<93)
  console.log("Your grade = A-");
if(grade>=87 && grade<90)
  console.log("Your grade = B+");
if(grade>=83 && grade<87)
  console.log("Your grade = B");
if(grade>=80 && grade<83)
  console.log("Your grade = B-");
if(grade>=77 && grade<80)
  console.log("Your grade = C+");
if(grade>=73 && grade<77)
  console.log("Your grade = C");
if(grade>=70 && grade<73)
  console.log("Your grade = C-");
if(grade>=67 && grade<70)
  console.log("Your grade = D+");
if(grade>=63 && grade<67)
  console.log("Your grade = D");
if(grade>=60 && grade<63)
  console.log("Your grade = D-");
if(grade<=50)
  console.log("Your grade = F");







