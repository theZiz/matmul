#!/bin/bash
TILESIZE="256"

rm -rf paper_scaling_gcc
mkdir paper_scaling_gcc
cd paper_scaling_gcc
../make_paper_autotuning_power8.sh $TILESIZE
OMP_NUM_THREADS=160 ./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
