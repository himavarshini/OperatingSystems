#!/bin/sh
echo "Input no : "
read no

length=`expr length $no`

while [ $length -ne 0 ]
do
    b=`expr substr $no $length 1`
    ans=`expr $ans + $b`    
    length=`expr $length - 1`
done
echo "Sum of Digit is : $ans"
