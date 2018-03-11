#!/bin/sh
echo "Enter two values"
read v1
read v2
echo "The values before exchange : v1 = $v1 ; v2 = $v2 "
tmp=$v1
v1=$v2
v2=$tmp
echo "The values after exchange : v1 = $v1 ; v2 = $v2 "
