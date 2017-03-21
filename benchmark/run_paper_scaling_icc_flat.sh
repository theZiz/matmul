#!/bin/sh
TILESIZE="64"

rm -rf paper_scaling_knl_icc_flat
mkdir paper_scaling_knl_icc_flat
cd paper_scaling_knl_icc_flat
../make_paper_autotuning_knl_flat.sh $TILESIZE
OMP_NUM_THREADS=64 numactl -C 0-63 ./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
