#!/bin/bash
TILESIZE="2"

rm -rf paper_scaling_k80
mkdir paper_scaling_k80
cd paper_scaling_k80
../make_paper_autotuning_k80.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
