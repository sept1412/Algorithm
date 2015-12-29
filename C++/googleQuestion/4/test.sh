#!/bin/sh

a=0
while [ "$a" -le 100 ]
do
	./solution "$a"
	a=`expr $a + 1`
done

