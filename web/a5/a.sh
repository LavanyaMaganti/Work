#!/bin/bash

# a.sh: 2 points
# List the files (non-hidden) found in the current directory with a leading
# index.  ex:
# > ./a.sh
#   1: a.sh
#   2: b.sh
#   3: c.sh

# Initialize an index variable to 1:

# Use a for - in loop with a wild-card to expand all the files in the current
# directory:


index=1
files=`ls *`
for i in $files
do
if [[ -f $i ]]; then
echo "$index $i"
index=$[$index + 1]
fi
done


