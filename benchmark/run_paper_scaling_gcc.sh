#!/bin/sh
TILESIZE="128"

rm -rf paper_scaling_knl_gcc
mkdir paper_scaling_knl_gcc
cd paper_scaling_knl_gcc
../make_paper_autotuning_knl_gcc.sh $TILESIZE
OMP_NUM_THREADS=128 numactl -C 0-127 ./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
