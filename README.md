matmul - Generalized Matrix-Matrix-Multiplication (GEMM) Library with C Interface
===============================================================

This repository contains multiple sequential and parallel implementations of the generalized matrix-matrix-multiplication GEMM (C = alpha * A * B + beta * C).
Single and double precision values are supported (compile-time decision).


Software License
----------------

**matmul** is licensed under **LGPLv3** or later.


Available Implementations
-------------------------

* Sequential
  * Basic (3 nested loops ijk)
  * Basic Algorithm with a Single Optimization:
    * Pointer Instead of Index
    * restrict for Input Pointers
    * Loop Reordering (ikj)
    * Index Precalculation
    * Loop Unrolling (4, 8, 16)
    * Loop Blocking/Tiling
  * With Multiple Optimizations
    * restrict + Loop Reordering + Blocking
    * restrict + Loop Reordering
  * Strassen algorithm

* Parallel
  * OpenMP 2.0
    * guided schedule
    * static schedule
    * Offload to Intel XeonPhi
    * Strassen Algorithm
  * OpenMP 3.0
    * static schedule + loop collapsing
  * OpenMP 4.0
    * target + teams + distribute + parallel for host and device
  * OpenACC
  * CUDA Native Implementation
    * fixed block size
      * 2D static shared memory
      * 1D static shared memory
      * 1D extern shared memory
    * dynamic block size
      * 1D extern shared memory
        * with memory copy
        * without memory copy
  * [alpaka](https://github.com/ComputationalRadiationPhysics/alpaka)
    * Sequential
    * CUDA
      * with memory copy
      * without memory copy
    * OpenMP 2.0 (Host only)
    * OpenMP 4.0 (Host only)
    * std::thread
    * Boost.Fiber
  * BLAS
    * MKL
    * MKL Offload to Intel XeonPhi
    * cuBLAS2
      * with memory copy
      * without memory copy
  * MPI
    * Cannon Algorithm
      * Optimized Sequential per Node
        * Blocking Communication
        * Non-Blocking Communication
      * MKL per Node
      * cuBLAS2 per Node
    * DNS
      * Optimized Sequential per Node
