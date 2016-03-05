#!/bin/sh
rm -f xc xem dis funcall funcall.txt funcall.s
gcc -o xc -O3 -m32 -Ilinux -Iroot/lib root/bin/c.c
gcc -o xem -O3 -m32 -Ilinux -Iroot/lib root/bin/em.c -lm
gcc -o dis -O3 root/bin/dis.c
#./xc -o funcall -Iroot/lib root/usr/funcall.c
#./xc -o lab1 -Iroot/lib root/usr/lab/lab1.c
./xc  -o lab2 -Iroot/lib root/usr/lab/lab2.c
#./xc -s -Iroot/lib root/usr/funcall.c >funcall.txt
./xem lab2
