#!/bin/bash
TILESIZE="4"

rm -rf paper_scaling_k80_float
mkdir paper_scaling_k80_float
cd paper_scaling_k80_float
../make_paper_autotuning_k80_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
