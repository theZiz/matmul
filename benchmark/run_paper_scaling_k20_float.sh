#!/bin/bash
TILESIZE="4"

rm -rf paper_scaling_k20_float
mkdir paper_scaling_k20_float
cd paper_scaling_k20_float
../make_paper_autotuning_k20_float.sh $TILESIZE
./matmul_benchmark 1024 13312 1024 5 > log.txt
cd ..
