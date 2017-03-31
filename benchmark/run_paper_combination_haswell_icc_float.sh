#!/bin/sh

function doit {
	rm -rf paper_combination_haswell_icc_float_$2_$1
	mkdir paper_combination_haswell_icc_float_$2_$1
	cd paper_combination_haswell_icc_float_$2_$1
	../make_paper_autotuning_haswell_float.sh $2
	OMP_NUM_THREADS=$1 numactl -C 0-$(expr $1 - 1) ./matmul_benchmark 7168 7168 1 10 > log7168.txt
	OMP_NUM_THREADS=$1 numactl -C 0-$(expr $1 - 1) ./matmul_benchmark 10240 10240 1 10 > log10240.txt
	cd ..
}

function for_tilesize {
#	doit 12 $1
	doit 24 $1
}

for_tilesize 16
for_tilesize 32
for_tilesize 64
for_tilesize 128
for_tilesize 256
