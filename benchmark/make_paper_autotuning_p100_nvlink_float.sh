#!/bin/sh
cmake -Dalpaka_DIR=~/src/alpaka -DCUDA_NVCC_FLAGS="-DGPU_ELEM_NUM=$1 --ptxas-options=-v --use_fast_math" -DMATMUL_BENCHMARK_ALPAKA_TILING_KERNEL=ON -DMATMUL_BENCHMARK_ALPAKA_OMPNATIVE_KERNEL=OFF -DMATMUL_BENCHMARK_ALPAKA_CUDASDK_KERNEL=OFF -DMATMUL_BENCHMARK_PAR_ALPAKA_ACC_GPU_CUDA=ON -DMATMUL_BENCHMARK_PRINT_GFLOPS=ON -DCMAKE_CXX_FLAGS_RELEASE="-Ofast -DNDEBUG" -DCMAKE_CXX_FLAGS="-mtune=native -mcpu=native -Wno-deprecated-declarations" -DCMAKE_BUILD_TYPE="Release" -DCMAKE_C_FLAGS="-mtune=native -mcpu=native -Wno-deprecated-declarations" -DALPAKA_CUDA_ARCH="sm_60" -DMATMUL_INDEX_TYPE="int" -DMATMUL_ELEMENT_TYPE_DOUBLE=OFF .. >&cmake_log.txt
make -j >&make_log.txt 
