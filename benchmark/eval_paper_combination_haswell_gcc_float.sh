#!/bin/sh
function doit {
	cd paper_combination_haswell_gcc_float_$2_$1
	cat log.txt | grep -v "#" | grep -v "m=n=k" | grep -v "Workdiv" | grep -v "Using" | grep -v -e '^$' | grep -v "Total" | grep "\." | sed "s/	//g"
	cd ..
}

function for_tilesize {
	echo "-- tilesize = $1 --"
	doit 12 $1
	doit 24 $1
}

for_tilesize 16
for_tilesize 32
for_tilesize 64
for_tilesize 128
for_tilesize 256
