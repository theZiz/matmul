#!/bin/sh
TILESIZE="256"

rm -rf paper_scaling_gcc_float
mkdir paper_scaling_gcc_float
cd paper_scaling_gcc_float
../make_paper_autotuning_power8_float.sh $TILESIZE
OMP_NUM_THREADS=160 ./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
