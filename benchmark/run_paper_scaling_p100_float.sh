#!/bin/sh
TILESIZE="4"

rm -rf paper_scaling_p100_float
mkdir paper_scaling_p100_float
cd paper_scaling_p100_float
../make_paper_autotuning_p100_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
