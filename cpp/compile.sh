#!/bin/sh

if test -n "$1"; then
  src=$1
  output=`echo $src | cut -d'.' -f1`

  eval "g++ -std=c++11 -pthread $src -o ./bins/$output" 
else
  echo "Please input your source file."
fi
