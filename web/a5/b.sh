#!/bin/bash

# b.sh: 2 points
# Prompt the user for a start/end numbers and print all the odd numbers between
# them.  If start > end, switch start and end.
# Example output:
# > ./b.sh 
#Start? 0
#  End? 20
#1  3  5  7  9  11  13  15  17  19 

# Use read to prompt for a start and ending value:



# If the start > end, switch the two:


echo -n "Start?"
read start
echo -n "End?"
read end

if [[ $start > $end ]]; then
start=$end
end=$start
fi


# If start is an even number, increment by one:

if [[ $[ $start % 2 ] -eq 0 ]]; then
start=$[ $start + 1 ]
fi
echo $start
# Use a C style for loop to loop through the odd numbers until start > end.
# Increment start by two each time through the loop.  Use echo to print the
# number followed by a space, but without a newline.

for (( start=$start; $start < $end; start=$[ $start + 2 ] ));
do
echo $start
done


# After the loop is finished use echo to print a newline.

