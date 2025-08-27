#!/bin/bash
cf gen > in                 # input generator
cf code < in > out 2> err   # file to rte test

for ((i = 1; ; ++i)) do
    echo $i
    ./gen > in
    ./code < in > out 2> err
    if [ $? -ne 0 ] || grep -q -E "AddressSanitizer|runtime error" err; then
        echo "RTE found!!!"
        cat err
        break
    fi
done
