#!/bin/sh
echo "Enter two strings"
read s1
read s2
s3="$s1$s2"
echo  "concatenation of two strings $s3"
len=${#s3}
echo "Length of the string after $len"
