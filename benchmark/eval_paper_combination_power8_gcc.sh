#!/bin/sh
function doit {
	cd paper_combination_power8_gcc_$2_$1
	cat log.txt | grep -v "#" | grep -v "m=n=k" | grep -v "Workdiv" | grep -v "Using" | grep -v -e '^$' | grep -v "Total" | grep "\." | sed "s/	//g"
	cd ..
}

function for_tilesize {
	echo "-- tilesize = $1 --"
	doit 20 $1
	doit 40 $1
	doit 80 $1
	doit 160 $1
}

for_tilesize 16
for_tilesize 32
for_tilesize 64
for_tilesize 128
for_tilesize 256
for_tilesize 512
