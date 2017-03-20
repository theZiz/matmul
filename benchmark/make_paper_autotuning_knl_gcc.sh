#!/bin/sh
CC=gcc CXX=g++ cmake -Dalpaka_DIR=~/src/alpaka -DMATMUL_BENCHMARK_ALPAKA_TILING_KERNEL=ON -DMATMUL_BENCHMARK_ALPAKA_OMPNATIVE_KERNEL=OFF -DMATMUL_BENCHMARK_ALPAKA_CUDASDK_KERNEL=OFF -DMATMUL_BENCHMARK_PAR_ALPAKA_ACC_CPU_B_OMP2_T_SEQ=ON -DMATMUL_BENCHMARK_PRINT_GFLOPS=ON -DCMAKE_CXX_FLAGS_RELEASE="-Ofast -DNDEBUG" -DCMAKE_CXX_FLAGS="-DOMP_ELEM_NUM=$1 -mtune=native -march=native -Wno-deprecated-declarations" -DCMAKE_BUILD_TYPE="Release" -DCMAKE_C_FLAGS="-mtune=native -march=native -Wno-deprecated-declarations " .. >&cmake_log.txt
make -j >&make_log.txt 
