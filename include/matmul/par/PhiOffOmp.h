#pragma once

//-----------------------------------------------------------------------------
//! Copyright (c) 2014-2015, Benjamin Worpitz
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met :
//! * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//! * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//! * Neither the name of the TU Dresden nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//! IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//! HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#ifdef MATMUL_BUILD_PAR_PHI_OFF_OPENMP

    #include <matmul/common/Config.h>   // TElem

    #include <stddef.h>                 // size_t

    #ifdef __cplusplus
        extern "C"
        {
    #endif
    #if _OPENMP >= 200203   // OpenMP 2.0
        //-----------------------------------------------------------------------------
        //! (S/D)GEMM matrix-matrix product C := A * B + C using OpenMP 2.0 parallel for guided schedule offloading to Xeon Phi.
        //!
        //! \param m Specifies the number of rows of the matrix A and of the matrix C.
        //! \param n Specifies the number of columns of the matrix B and the number of columns of the matrix C.
        //! \param k Specifies the number of columns of the matrix A and the number of rows of the matrix B.
        //! \param alpha Scalar value used to scale the product of matrices A and B.
        //! \param A Array, size lda-by-k. The leading m-by-k part of the array must contain the matrix A.
        //! \param lda Specifies the leading dimension of A.
        //! \param B Array, size ldb-by-n. The leading k-by-n part of the array must contain the matrix B.
        //! \param ldb Specifies the leading dimension of B.
        //! \param beta Scalar value used to scale matrix C.
        //! \param C Array, size ldc-by-n. The leading m-by-n part of the array must contain the matrix C.
        //! \param ldc Specifies the leading dimension of C.
        //-----------------------------------------------------------------------------
        void matmul_gemm_par_phi_off_omp2_guided_schedule(
            size_t const m, size_t const n, size_t const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, size_t const lda,
            TElem const * const MATMUL_RESTRICT B, size_t const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, size_t const ldc);

        //-----------------------------------------------------------------------------
        //! (S/D)GEMM matrix-matrix product C := A * B + C using OpenMP 2.0 parallel for static schedule offloading to Xeon Phi.
        //!
        //! \param m Specifies the number of rows of the matrix A and of the matrix C.
        //! \param n Specifies the number of columns of the matrix B and the number of columns of the matrix C.
        //! \param k Specifies the number of columns of the matrix A and the number of rows of the matrix B.
        //! \param alpha Scalar value used to scale the product of matrices A and B.
        //! \param A Array, size lda-by-k. The leading m-by-k part of the array must contain the matrix A.
        //! \param lda Specifies the leading dimension of A.
        //! \param B Array, size ldb-by-n. The leading k-by-n part of the array must contain the matrix B.
        //! \param ldb Specifies the leading dimension of B.
        //! \param beta Scalar value used to scale matrix C.
        //! \param C Array, size ldc-by-n. The leading m-by-n part of the array must contain the matrix C.
        //! \param ldc Specifies the leading dimension of C.
        //-----------------------------------------------------------------------------
        void matmul_gemm_par_phi_off_omp2_static_schedule(
            size_t const m, size_t const n, size_t const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, size_t const lda,
            TElem const * const MATMUL_RESTRICT B, size_t const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, size_t const ldc);
    #endif
    #if _OPENMP >= 200805   // OpenMP 3.0
        //-----------------------------------------------------------------------------
        //! (S/D)GEMM matrix-matrix product C := A * B + C using OpenMP 3.0 parallel for collapse static schedule offloading to Xeon Phi.
        //!
        //! \param m Specifies the number of rows of the matrix A and of the matrix C.
        //! \param n Specifies the number of columns of the matrix B and the number of columns of the matrix C.
        //! \param k Specifies the number of columns of the matrix A and the number of rows of the matrix B.
        //! \param alpha Scalar value used to scale the product of matrices A and B.
        //! \param A Array, size lda-by-k. The leading m-by-k part of the array must contain the matrix A.
        //! \param lda Specifies the leading dimension of A.
        //! \param B Array, size ldb-by-n. The leading k-by-n part of the array must contain the matrix B.
        //! \param ldb Specifies the leading dimension of B.
        //! \param beta Scalar value used to scale matrix C.
        //! \param C Array, size ldc-by-n. The leading m-by-n part of the array must contain the matrix C.
        //! \param ldc Specifies the leading dimension of C.
        //-----------------------------------------------------------------------------
        void matmul_gemm_par_phi_off_omp3_static_schedule_collapse(
            size_t const m, size_t const n, size_t const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, size_t const lda,
            TElem const * const MATMUL_RESTRICT B, size_t const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, size_t const ldc);
    #endif
    #if _OPENMP >= 201307   // OpenMP 4.0
        //-----------------------------------------------------------------------------
        //! (S/D)GEMM matrix-matrix product C := A * B + C using OpenMP 4.0 teams distribute parallel for static schedule offloading to Xeon Phi.
        //!
        //! \param m Specifies the number of rows of the matrix A and of the matrix C.
        //! \param n Specifies the number of columns of the matrix B and the number of columns of the matrix C.
        //! \param k Specifies the number of columns of the matrix A and the number of rows of the matrix B.
        //! \param alpha Scalar value used to scale the product of matrices A and B.
        //! \param A Array, size lda-by-k. The leading m-by-k part of the array must contain the matrix A.
        //! \param lda Specifies the leading dimension of A.
        //! \param B Array, size ldb-by-n. The leading k-by-n part of the array must contain the matrix B.
        //! \param ldb Specifies the leading dimension of B.
        //! \param beta Scalar value used to scale matrix C.
        //! \param C Array, size ldc-by-n. The leading m-by-n part of the array must contain the matrix C.
        //! \param ldc Specifies the leading dimension of C.
        //-----------------------------------------------------------------------------
        void matmul_gemm_par_phi_off_omp4(
            size_t const m, size_t const n, size_t const k,
            TElem const alpha,
            TElem const * const MATMUL_RESTRICT A, size_t const lda,
            TElem const * const MATMUL_RESTRICT B, size_t const ldb,
            TElem const beta,
            TElem * const MATMUL_RESTRICT C, size_t const ldc);
    #endif
    #ifdef __cplusplus
        }
    #endif
#endif
