//-----------------------------------------------------------------------------
//! \file
//! Copyright 2013-2015 Benjamin Worpitz
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

#if defined(MATMUL_BUILD_PAR_OMP2_GUIDED) || defined(MATMUL_BUILD_PAR_OMP2_STATIC) || defined(MATMUL_BUILD_PAR_OMP3) || defined(MATMUL_BUILD_PAR_OMP4)

    #include <matmul/par/Omp.h>

    #include <matmul/common/Mat.h>  // matmul_mat_gemm_early_out

    #include <omp.h>

    #include <stdio.h>              // printf

    #if _OPENMP >= 200203   // OpenMP 2.0
        #ifdef MATMUL_BUILD_PAR_OMP2_GUIDED
            //-----------------------------------------------------------------------------
            //
            //-----------------------------------------------------------------------------
            TReturn matmul_gemm_par_omp2_guided_schedule(
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

                MATMUL_TIME_START;

                #pragma omp parallel// shared(n,lda,A,ldb,B,ldc,C)
                {
            #ifdef MATMUL_OMP_PRINT_NUM_CORES
                    #pragma omp single
                    {
                        printf(" p=%d ", omp_get_num_threads());
                    }
            #endif
                    int iM = (int)m;
                    int i;
                    #pragma omp for schedule(guided)
                    for(i = 0; i < iM; ++i)
                    {
                        for(TSize j = 0; j < n; ++j)
                        {
                            C[i*ldc + j] *= beta;
                        }
                        for(TSize k2 = 0; k2 < k; ++k2)
                        {
                            TElem const a = alpha * A[i*lda + k2];

                            for(TSize j = 0; j < n; ++j)
                            {
                                C[i*ldc + j] += a * B[k2*ldb + j];
                            }
                        }
                    }
                }

                MATMUL_TIME_END;
                MATMUL_TIME_RETURN;
            }
        #endif
        #ifdef MATMUL_BUILD_PAR_OMP2_STATIC
            //-----------------------------------------------------------------------------
            //
            //-----------------------------------------------------------------------------
            TReturn matmul_gemm_par_omp2_static_schedule(
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

                MATMUL_TIME_START;

                #pragma omp parallel //shared(A,B,C)
                {
                    #ifdef MATMUL_OMP_PRINT_NUM_CORES
            #pragma omp single
                    {
                        printf(" p=%d ", omp_get_num_threads());
                    }
            #endif
                    int iM = (int)m;
                    int i;
                    #pragma omp for schedule(static)
                    for(i = 0; i < iM; ++i)
                    {
                        for(TSize j = 0; j < n; ++j)
                        {
                            C[i*ldc + j] *= beta;
                        }
                        for(TSize k2 = 0; k2 < k; ++k2)
                        {
                            TElem const a = alpha * A[i*lda + k2];

                            for(TSize j = 0; j < n; ++j)
                            {
                                C[i*ldc + j] += a * B[k2*ldb + j];
                            }
                        }
                    }
                }

                MATMUL_TIME_END;
                MATMUL_TIME_RETURN;
            }
        #endif
    #endif
    #if _OPENMP >= 200805   // OpenMP 3.0
        #ifdef MATMUL_BUILD_PAR_OMP3
            //-----------------------------------------------------------------------------
            //
            //-----------------------------------------------------------------------------
            TReturn matmul_gemm_par_omp3_static_schedule_collapse(
                TSize const m, TSize const n, TSize const k,
                TElem const alpha,
                TElem const * const MATMUL_RESTRICT A,  TSize const lda,
                TElem const * const MATMUL_RESTRICT B,  TSize const ldb,
                TElem const beta,
                TElem * const MATMUL_RESTRICT C,  TSize const ldc)
            {
                if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
                {
                    MATMUL_TIME_RETURN_EARLY_OUT;
                }

                MATMUL_TIME_START;

                #pragma omp parallel //shared(A,B,C)
                {
            #ifdef MATMUL_OMP_PRINT_NUM_CORES
                    #pragma omp single
                    {
                        printf(" p=%d ", omp_get_num_threads());
                    }
            #endif

                    #pragma omp for collapse(2) schedule(static)
                    for(TSize i = 0; i < m; ++i)
                    {
                        for(TSize j = 0; j < n; ++j)
                        {
                            C[i*ldc + j] *= beta;
                        }
                    }

                    // NOTE:
                    // - ikj-order not possible.
                    // - In ijk order we can only collapse the outer two loops.
                    // Both restrictions are due to the non-atomic write to C (multiple threads could write to the same indices i and j of C)
                    #pragma omp for collapse(2) schedule(static)    // http://software.intel.com/en-us/articles/openmp-loop-collapse-directive
                    for(TSize i = 0; i < m; ++i)
                    {
                        for(TSize j = 0; j < n; ++j)
                        {
                            for(TSize k2 = 0; k2 < k; ++k2)
                            {
                                C[i*ldc + j] += alpha * A[i*lda + k2] * B[k2*ldb + j];
                            }
                        }
                    }
                }

                MATMUL_TIME_END;
                MATMUL_TIME_RETURN;
            }
        #endif
    #endif
    #if _OPENMP >= 201307   // OpenMP 4.0
        #ifdef MATMUL_BUILD_PAR_OMP4
            //-----------------------------------------------------------------------------
            //
            //-----------------------------------------------------------------------------
            TReturn matmul_gemm_par_omp4(
                TSize const m, TSize const n, TSize const k,
                TElem const alpha,
                TElem const * const MATMUL_RESTRICT A,  TSize const lda,
                TElem const * const MATMUL_RESTRICT B,  TSize const ldb,
                TElem const beta,
                TElem * const MATMUL_RESTRICT C,  TSize const ldc)
            {
                if(matmul_mat_gemm_early_out(m, n, k, alpha, beta))
                {
                    MATMUL_TIME_RETURN_EARLY_OUT;
                }

                MATMUL_TIME_START;

                #pragma omp target if(0) map(to: m, n, k, alpha, A[0:lda*m], lda, B[0:ldb*k], ldb, beta, ldc) map(tofrom: C[0:ldc*m])
                {
                    #pragma omp teams /*num_teams(...) thread_limit(...)*/
                    {
                        #pragma omp distribute
                        for(TSize i = 0; i < m; ++i)
                        {
                            #pragma omp parallel for  /*num_threads(...)*/ schedule(static)
                            for(TSize j = 0; j < n; ++j)
                            {
                                C[i*ldc + j] *= beta;
                            }
                            // NOTE: ikj-order not possible due to the non-atomic write to C (multiple threads could write to the same indices i and j of C)
                            #pragma omp parallel for  /*num_threads(...)*/ schedule(static)
                            for(TSize j = 0; j < n; ++j)
                            {
                                for(TSize k2 = 0; k2 < k; ++k2)
                                {
                                    C[i*ldc + j] += alpha * A[i*lda + k2] * B[k2*ldb + j];
                                }
                            }
                        }
                    }
                }

                MATMUL_TIME_END;
                MATMUL_TIME_RETURN;
            }
        #endif
    #endif
#endif
