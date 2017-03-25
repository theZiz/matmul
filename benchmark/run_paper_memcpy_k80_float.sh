#!/bin/bash
TILESIZE="4"

rm -rf paper_memcpy_k80_float
mkdir paper_memcpy_k80_float
cd paper_memcpy_k80_float
../make_paper_memcpy_k80_float.sh $TILESIZE
./matmul_benchmark 1024 20480 1024 10 > log.txt
cd ..
