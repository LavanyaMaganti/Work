#!/bin/bash

read path
output=`stat --format=%F%i%n $path | grep regular | cut -c 13-`
#output=`stat --format=%i%n $path`
echo "$output"
