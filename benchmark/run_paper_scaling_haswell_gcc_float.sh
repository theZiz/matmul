#!/bin/sh
TILESIZE="128"

rm -rf paper_scaling_haswell_gcc_float
mkdir paper_scaling_haswell_gcc_float
cd paper_scaling_haswell_gcc_float
../make_paper_autotuning_haswell_gcc_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
