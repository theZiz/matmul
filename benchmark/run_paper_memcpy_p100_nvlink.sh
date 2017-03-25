#!/bin/sh
TILESIZE="4"

rm -rf paper_memcpy_p100
mkdir paper_memcpy_p100
cd paper_memcpy_p100
../make_paper_memcpy_p100_nvlink.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
