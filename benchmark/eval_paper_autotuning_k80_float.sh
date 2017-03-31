#!/bin/bash
function doit {
	cd paper_autotuning_k80_float_$1
	cat log$2.txt | grep -v "#" | grep -v "m=n=k" | grep -v "Workdiv" | grep -v "Using" | grep -v -e '^$' | grep -v "Total" | grep "\." | sed "s/	//g"
	cd ..
}

function for_matrix {
	echo "---- matrixsize = $1 ----"
	doit 1 $1
	doit 2 $1
	doit 4 $1
	doit 8 $1
}

for_matrix 7168
for_matrix 10240

