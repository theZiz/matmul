#!/bin/sh
TILESIZE="64"

function doit {
	rm -rf paper_combination_knl_icc_$2_$1
	mkdir paper_combination_knl_icc_$2_$1
	cd paper_combination_knl_icc_$2_$1
	../make_paper_autotuning_knl.sh $2
	OMP_NUM_THREADS=$1 numactl -C 0-$(expr $1 - 1) ./matmul_benchmark 10240 10240 1 5 > log.txt
	cd ..
}

function for_tilesize {
	doit 64 $1
	doit 128 $1
	doit 256 $1
}

for_tilesize 16
for_tilesize 32
for_tilesize 64
for_tilesize 128
for_tilesize 256
