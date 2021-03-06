//-----------------------------------------------------------------------------
//! \file
//! Copyright 2013-2016 Benjamin Worpitz, Rene Widera
//!
//! This file is part of matmul.
//!
//! matmul is free software: you can redistribute it and/or modify
//! it under the terms of the GNU Lesser General Public License as published by
//! the Free Software Foundation, either version 3 of the License, or
//! (at your option) any later version.
//!
//! matmul is distributed in the hope that it will be useful,
//! but WITHOUT ANY WARRANTY; without even the implied warranty of
//! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//! GNU Lesser General Public License for more details.
//!
//! You should have received a copy of the GNU Lesser General Public License
//! along with matmul.
//! If not, see <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------

#if defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_SEQ) || defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_OMP2_T_SEQ) || defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_OMP2) || defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_BT_OMP4) || defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_THREADS) || defined(MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_FIBERS)

    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_GPU_CUDA
        // If we do not undefine here, we would get the error:
        // #error If ALPAKA_ACC_GPU_CUDA_ENABLED is set, the compiler has to support CUDA!
        // because the cpp files are compiled with the host compiler.
        #undef MATMUL_BUILD_PAR_ALPAKA_ACC_GPU_CUDA
        #undef ALPAKA_ACC_GPU_CUDA_ENABLED
    #endif

    #include <matmul/par/AlpakaOmpNative.h>

    #include <matmul/par/AlpakaOmpNative.hpp>

    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_SEQ
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_seq_alpaka_cpu_b_seq_t_seq_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuSerial<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_OMP2_T_SEQ
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_par_alpaka_cpu_b_omp2_t_seq_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuOmp2Blocks<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_OMP2
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_par_alpaka_cpu_b_seq_t_omp2_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuOmp2Threads<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_BT_OMP4
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_par_alpaka_cpu_bt_omp4_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuOmp4<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_THREADS
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_par_alpaka_cpu_b_seq_t_threads_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuThreads<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
    #ifdef MATMUL_BUILD_PAR_ALPAKA_ACC_CPU_B_SEQ_T_FIBERS
        //-----------------------------------------------------------------------------
        //
        //-----------------------------------------------------------------------------
        TReturn matmul_gemm_seq_alpaka_cpu_b_seq_t_fibers_ompNative(
            TSize const m, TSize const n, TSize const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, TSize const lda,
            TElem const * const MATMUL_RESTRICT B, TSize const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, TSize const ldc)
        {
            if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
            {
                MATMUL_TIME_RETURN_EARLY_OUT;
            }

            return
                matmul_gemm_par_alpaka_ompNative<alpaka::acc::AccCpuFibers<alpaka::dim::DimInt<1u>, TSize>, GemmAlpakaOmpNative>(
                    m, n, k,
                    alpha,
                    A, lda,
                    B, ldb,
                    beta,
                    C, ldc);
        }
    #endif
#endif
