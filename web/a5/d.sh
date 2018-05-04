#!/bin/bash

# d.sh: 2 points
# Use du to give a byte total of a particular path, then print out the total
# in the SI unit human readable formats.
#example output:
# > ./d.sh /net/vm
#Total:  39873039000 bytes / 38938514 KB / 38025 MB / 37 GB

# Get the path from the first command line argument, if it is not provided, use
# the current working directory (.):


# Use du and cut to get the size in bytes for the path given, assign the result
# to a variable:

if [[ "$1" == '' ]]; then
path="."
else
path="$@"
fi

total=`du -sb $path | cut -f 1`;

echo -n "Total: ";

siunits=( "bytes" "KB" "MB" "GB" "TB" "PB" );

# Setup a index variable for the siunits array defined above:
index=0;

# While the total is > 0 loop:

  # if the si index is > 0 output a "/" separator:

  # Print the current total with the siunit indexed by the index variable

  # divide the total by 1024.

  # increment the index variable.


# print a new-line after exiting the loop

while [ $total -gt 0 ] 
do
  if [ $index > 0 ]; then
    printf "$total ${siunits[$index]} ";
    total=$(($total / 1024));
    index=$(($index + 1));

      

  fi
done

echo -e "\n";
