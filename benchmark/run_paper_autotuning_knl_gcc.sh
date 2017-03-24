#!/bin/sh
function doit {
	rm -rf paper_autotuning_knl_gcc_$1
	mkdir paper_autotuning_knl_gcc_$1
	cd paper_autotuning_knl_gcc_$1
	../make_paper_autotuning_knl_gcc.sh $1
	./matmul_benchmark 10240 10240 1 5 > log.txt
	cd ..
}
doit 16
doit 32
doit 64
doit 128
doit 256
doit 512