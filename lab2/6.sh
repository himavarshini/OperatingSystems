#!/bin/sh
echo "Enter the two filenames "
read first
read second
cat first > third
cat second >> third
