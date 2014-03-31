#!/bin/bash

x=0
for file in `cat graph_file_list`; do
  x=`expr $x + 1`
  echo $x: $file
  ./ToGraphTest2 $file
done
