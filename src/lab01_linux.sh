#!/bin/bash

mkdir -p informatics
cd informatics || exit 1

pwd
date
ls -ld /sbin

echo "hello" > file.txt
echo "world" >> file.txt
cat file.txt

cp file.txt copy.txt
rm copy.txt

ls -l
