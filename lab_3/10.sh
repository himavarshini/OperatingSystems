#!/bin/sh
max=0
cat file.txt|while read LINE
do
    fir=`echo $LINE|awk '{print $2}'`
    sec=`echo $LINE|awk '{print $3}'`
    if [ $fir -gt $max ]; then
       max=$fir
    fi
    if [ $sec -gt $max ];then
        max=$sec
    fi
done

grep $max file.txt
