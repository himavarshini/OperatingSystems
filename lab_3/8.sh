#!/bin/sh
echo "Enter length"
read length
echo "enter breadth"
read breadth 
echo "enter radius"
read radius


areaR=`expr $length \* $breadth`
perimeterR=`expr $length \* 2+ $breadth \* 2 `

areaC=`echo 3.14 \* $radius \* $radius | bc `

cirC=`echo 2 \* 3.14 \* $radius | bc`

echo "Area of rectangle =" $areaR "and perimeter =" $perimeterR
echo "Area of circle =" $areaC "and circumference =" $cirC
