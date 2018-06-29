#!/bin/bash
array=(2654 1675 1327 1143 1027 945 885 837 799 767 740 717 697 679 664 649 637 625 614 604 595 587 579 572 565 558 552 546 541)
for i in `seq 2 30`
do 
    b=${array[$i-2]}
    while :
    do 
        ./TestMlt.exe 2 1 ${i} ${b}
        if [ $? -eq 0 ] ; then
            break
        fi
        b=`expr $b - 1`
    done
done