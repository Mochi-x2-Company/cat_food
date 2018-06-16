#!/bin/bash
for i in `seq 1 2651`; do
    ./TestMlt.exe << EOS
    4
    1 2
    $i
EOS
done