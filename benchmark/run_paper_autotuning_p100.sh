#!/bin/bash
function doit {
	rm -rf paper_autotuning_p100_$1
	mkdir paper_autotuning_p100_$1
	cd paper_autotuning_p100_$1
	../make_paper_autotuning_p100.sh $1
	./matmul_benchmark 13312 13312 1 10 > log13312.txt
	./matmul_benchmark 20480 20480 1 10 > log20480.txt
	cd ..
}
doit 1
doit 2
doit 4
doit 8
