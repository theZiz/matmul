#!/bin/sh
TILESIZE="32"

rm -rf paper_scaling_knl_icc_flat_sc4
mkdir paper_scaling_knl_icc_flat_sc4
cd paper_scaling_knl_icc_flat_sc4
../make_paper_autotuning_knl.sh $TILESIZE
numactl -m 4,5,6,7 ./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
