#!/bin/bash
function doit {
	cd paper_combination_power8_xl_float_$2_$1
	cat log$3.txt | grep -v "#" | grep -v "m=n=k" | grep -v "Workdiv" | grep -v "Using" | grep -v -e '^$' | grep -v "Total" | grep "\." | sed "s/	//g"
	cd ..
}

function for_tilesize {
	echo "-- tilesize = $1 --"
	doit 20 $1 $2
	doit 40 $1 $2
	doit 80 $1 $2
	doit 160 $1 $2
}

function for_matrix {
	echo "---- matrixsize = $1 ----"
	for_tilesize 16 $1
	for_tilesize 32 $1
	for_tilesize 64 $1
	for_tilesize 128 $1
	for_tilesize 256 $1
	for_tilesize 512 $1
}

for_matrix 7168
for_matrix 10240
