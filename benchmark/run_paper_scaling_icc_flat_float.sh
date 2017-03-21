#!/bin/sh
TILESIZE="64"

rm -rf paper_scaling_knl_icc_flat_float
mkdir paper_scaling_knl_icc_flat_float
cd paper_scaling_knl_icc_flat_float
../make_paper_autotuning_knl_flat_float.sh $TILESIZE
OMP_NUM_THREADS=128 numactl -C 0-127 ./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
