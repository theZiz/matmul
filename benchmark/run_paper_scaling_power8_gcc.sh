#!/bin/sh
TILESIZE="256"

rm -rf paper_scaling_gcc
mkdir paper_scaling_gcc
cd paper_scaling_gcc
../make_paper_autotuning_power8.sh $TILESIZE
OMP_NUM_THREADS=80 numactl -C `../interleave 160 8 0 $(expr 80 / 20)` ./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
