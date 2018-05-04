
#!/bin/bash

if [[ "$#" > 1 ]]; then
files="$@"
else
files="."
fi

max=0
for i in $files/*
do
  if [ -f $i ]; then
  siz=`stat --format=%s $i`
    if [[ $siz -gt $max ]]; then
      max=$siz
    fi
  fi
done 

echo "$max $i"
