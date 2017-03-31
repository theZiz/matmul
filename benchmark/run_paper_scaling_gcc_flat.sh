#!/bin/sh
TILESIZE="128"

rm -rf paper_scaling_knl_gcc_flat
mkdir paper_scaling_knl_gcc_flat
cd paper_scaling_knl_gcc_flat
../make_paper_autotuning_knl_gcc.sh $TILESIZE
OMP_NUM_THREADS=128 numactl -C 0-127 -m 1 ./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
