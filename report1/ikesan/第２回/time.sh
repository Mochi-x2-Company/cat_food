#! /bin/bash
time1=0
time2=0
time1=`date +%N`
for ((i = 0; i < 1000; i++))
do
    ./AlgoSortView.exe 4 < rand.txt
done
time2=`date +%N`
time=${time2-time1}
echo "${time/1000000}" >&1