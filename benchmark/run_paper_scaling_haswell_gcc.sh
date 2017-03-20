#!/bin/sh
TILESIZE="128"

rm -rf paper_scaling_haswell_gcc
mkdir paper_scaling_haswell_gcc
cd paper_scaling_haswell_gcc
../make_paper_autotuning_haswell_gcc.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
