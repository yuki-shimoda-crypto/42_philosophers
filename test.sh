#!/bin/bash
 
i=100
while [ $i -lt 201 ]
do
  echo "$i is eating"
  cat output.txt | grep "$i is eating" | wc -l
  i=`expr $i + 1`
done
