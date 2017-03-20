#!/bin/sh
CC=/gpfs/software/opt/gcc/gcc-6.3.0/bin/gcc CXX=/gpfs/software/opt/gcc/gcc-6.3.0/bin/g++ cmake -Dalpaka_DIR=~/src/alpaka -DMATMUL_BENCHMARK_ALPAKA_TILING_KERNEL=ON -DMATMUL_BENCHMARK_ALPAKA_OMPNATIVE_KERNEL=OFF -DMATMUL_BENCHMARK_ALPAKA_CUDASDK_KERNEL=OFF -DMATMUL_BENCHMARK_PAR_ALPAKA_ACC_CPU_B_OMP2_T_SEQ=ON -DMATMUL_BENCHMARK_PRINT_GFLOPS=ON -DCMAKE_CXX_FLAGS_RELEASE="-Ofast -DNDEBUG" -DCMAKE_CXX_FLAGS="-DOMP_ELEM_NUM=$1 -mtune=native -mcpu=native -Wno-deprecated-declarations -mveclibabi=mass" -DCMAKE_BUILD_TYPE="Release" -DCMAKE_C_FLAGS="-mtune=native -mcpu=native -Wno-deprecated-declarations -mveclibabi=mass" .. >&cmake_log.txt
make -j >&make_log.txt 
