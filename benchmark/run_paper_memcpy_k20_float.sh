#!/bin/bash
TILESIZE="4"

rm -rf paper_memcpy_k20_float
mkdir paper_memcpy_k20_float
cd paper_memcpy_k20_float
../make_paper_memcpy_k20_float.sh $TILESIZE
./matmul_benchmark 1024 13312 1024 5 > log.txt
cd ..
