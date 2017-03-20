#!/bin/bash
TILESIZE="2"

rm -rf paper_scaling_k20
mkdir paper_scaling_k20
cd paper_scaling_k20
../make_paper_autotuning_k20.sh $TILESIZE
./matmul_benchmark 1024 13312 1024 5 > log.txt
cd ..
