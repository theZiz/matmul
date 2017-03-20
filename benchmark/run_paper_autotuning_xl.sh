#!/bin/sh
function doit {
	rm -rf paper_autotuning_xl_$1
	mkdir paper_autotuning_xl_$1
	cd paper_autotuning_xl_$1
	../make_paper_autotuning_xl.sh $1
	./matmul_benchmark 10240 10240 1 10 > log.txt
	cd ..
}
doit 16
doit 32
doit 64
doit 128
doit 256
doit 512
