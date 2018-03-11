#!/bin/bash
echo "Enter the number to find factorial"
read a
p=1
while [ $a -ne 1 ]
do
	p=`expr $p \* $a`
	a=`expr $a - 1`
done
echo The factorial is : $p
