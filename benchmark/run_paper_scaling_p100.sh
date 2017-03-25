#!/bin/sh
TILESIZE="4"

rm -rf paper_scaling_p100
mkdir paper_scaling_p100
cd paper_scaling_p100
../make_paper_autotuning_p100.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
