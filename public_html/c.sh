#!/bin/bash

read path
sym=`stat --format=%N $path`
echo $sym
