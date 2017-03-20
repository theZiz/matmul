#!/bin/sh
TILESIZE="4"

rm -rf paper_memcpy_p100_float
mkdir paper_memcpy_p100_float
cd paper_memcpy_p100_float
../make_paper_memcpy_p100_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 5 > log.txt
cd ..
