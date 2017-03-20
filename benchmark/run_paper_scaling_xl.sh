#!/bin/sh
TILESIZE="512"

rm -rf paper_scaling_xl
mkdir paper_scaling_xl
cd paper_scaling_xl
../make_paper_autotuning_xl.sh $TILESIZE
OMP_NUM_THREADS=40 numactl -C `../../../matmul/benchmark/interleave 160 8 0 $(expr 40 / 20)` ./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
