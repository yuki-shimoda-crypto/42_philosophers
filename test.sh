#!/bin/bash
 
i=1
while [ $i -lt 6 ]
do
  echo "$i is eating"
  cat output.txt | grep "$i is eating" | wc -l
  i=`expr $i + 1`
done
