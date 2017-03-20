#!/bin/sh
TILESIZE="64"

rm -rf paper_scaling_haswell_icc_float
mkdir paper_scaling_haswell_icc_float
cd paper_scaling_haswell_icc_float
../make_paper_autotuning_haswell_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
