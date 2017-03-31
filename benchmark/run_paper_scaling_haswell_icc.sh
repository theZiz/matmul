#!/bin/sh
TILESIZE="128"

rm -rf paper_scaling_haswell_icc
mkdir paper_scaling_haswell_icc
cd paper_scaling_haswell_icc
../make_paper_autotuning_haswell.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
