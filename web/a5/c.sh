#!/bin/bash

# c.sh: 2 points
# Given a path on the command line, use stat to print the permissions, user and
# group for each path as you use dirname to walk back up the directory tree to
# root (/).
# Example output:
# > ./c.sh .
#drwxr-xr-x   sbaker    users /net/sbaker/469/h/hw5
#drwx------   sbaker    users /net/sbaker/469/h
#drwx------   sbaker    users /net/sbaker/469
#drwx--x--x   sbaker    users /net/sbaker
#drwxr-xr-x     root     root /net
#drwxr-xr-x     root     root /

# Get the path from the first command line argument, if it is not provided, use
# the current working directory (.):

if [[ "$1" == '' ]]; then
path="."
else
path="$@"
fi

# Use realpath to get the real path:
if [ `realpath -e $path` != '' ];then
realpath=`realpath -e $path`
# If the path isn't to a directory, use dirname to get the directory name:
if [[ -d $realpath ]]; then
realpath=$realpath
else
realpath=`dirname $realpath`
fi


# While the path is not equal to /, loop:

while [ $realpath != '/' ]
do

  # Print the permissions, username, groupname, size and path using the stat
  # command.

echo "`stat -t --format="%A %-9U %-9G %-9s %-9n" $realpath | column -t -x`"
  # Use dirname to go up one directory:

realpath=`dirname $realpath`
done

if [[ $realpath == '/' ]]; then
echo "`stat -t --format="%A %-9U %-9G %-9s %-9n" $realpath | column -t -x`"
fi

fi
