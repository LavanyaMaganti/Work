#!/bin/bash

files="$@"

for i in $files
do
  if [ -f $i ]; then
  echo `stat --format=%i' '%n $i`
  fi
done 
