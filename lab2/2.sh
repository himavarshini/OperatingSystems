#!/bin/sh
echo "Enter 4 integers"
read a
read b
read c
read d
sum=`expr $a + $b + $c + $d`
echo "The sum of 4 integers is : "$sum
avg=`expr $sum / 4`
echo "The average of 4 integers is : "$avg
pdt=`expr $a \* $b \* $c \* $d`
echo "The product of 4 integers is : "$pdt


