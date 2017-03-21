#!/bin/sh

function doit {
	rm -rf paper_combination_power8_gcc_$2_$1
	mkdir paper_combination_power8_gcc_$2_$1
	cd paper_combination_power8_gcc_$2_$1
	../make_paper_autotuning_power8.sh $2
	OMP_NUM_THREADS=$1 numactl -C `../interleave 160 8 0 $(expr $1 / 20)` ./matmul_benchmark 10240 10240 1 5 > log.txt
	cd ..
}

function for_tilesize {
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
