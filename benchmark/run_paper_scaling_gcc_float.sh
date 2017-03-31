#!/bin/sh
TILESIZE="256"

rm -rf paper_scaling_knl_gcc_float
mkdir paper_scaling_knl_gcc_float
cd paper_scaling_knl_gcc_float
../make_paper_autotuning_knl_gcc_float.sh $TILESIZE
OMP_NUM_THREADS=64 numactl -C 0-63 ./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
