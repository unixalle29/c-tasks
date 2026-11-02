#!/bin/bash

set -e

mkdir -p informatics
cd informatics || exit 1

pwd
date
date +%Y-%m-%d
date -u
whoami
id
groups
who
uname -a
hostname
type help
ls -ld /sbin

echo "hello" > file.txt
echo "world" >> file.txt
cat file.txt
cp file.txt copy.txt
mv copy.txt moved.txt
rm moved.txt

find . -maxdepth 1 -type f
du -sh .

sleep 1 &
wait

echo "done"
