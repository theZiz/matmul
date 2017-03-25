#!/bin/sh
function doit {
	rm -rf paper_autotuning_p100_$1
	mkdir paper_autotuning_p100_$1
	cd paper_autotuning_p100_$1
	../make_paper_autotuning_p100.sh $1
	./matmul_benchmark 7168 7168 1 10 > log7168.txt
	./matmul_benchmark 10240 10240 1 10 > log10240.txt
	cd ..
}
doit 1
doit 2
doit 4
doit 8
