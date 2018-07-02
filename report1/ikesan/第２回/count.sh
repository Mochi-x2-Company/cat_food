#! /bin/bash
for ((i = 1; i <= 100; i++))
do
    ./rand.exe $i > rand.txt
    sleep 1s
    ./AlgoSortView.exe 8 < rand.txt
done