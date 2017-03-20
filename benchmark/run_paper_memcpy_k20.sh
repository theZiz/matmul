#!/bin/bash
TILESIZE="2"

rm -rf paper_memcpy_k20
mkdir paper_memcpy_k20
cd paper_memcpy_k20
../make_paper_memcpy_k20.sh $TILESIZE
./matmul_benchmark 1024 13312 1024 5 > log.txt
cd ..
