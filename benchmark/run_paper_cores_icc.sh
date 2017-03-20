#!/bin/sh
TILESIZE="32"

function doit {
	rm -rf paper_cores_knl_$1
	mkdir paper_cores_knl_$1
	cd paper_cores_knl_$1
	../make_paper_autotuning_knl.sh $TILESIZE
	OMP_NUM_THREADS=$1 numactl -C 0-$1 ./matmul_benchmark 10240 10240 1 5 > log.txt
	cd ..
}
doit 64
doit 128
doit 256
