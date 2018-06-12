#!/bin/bash
b=0
for i in `seq 2 7`
do 
    b=0
    echo $i
    while :
    do
        b=`expr $b + 1`
        echo ${b}
        if [ $b -eq 10 ]; then 
            break
        fi
    done
done