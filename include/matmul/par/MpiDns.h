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

#pragma once

#ifdef MATMUL_BUILD_PAR_MPI_DNS

    #include <matmul/common/Config.h>   // TElem, TSize, TReturn

    #ifdef __cplusplus
        extern "C"
        {
    #endif
    //-----------------------------------------------------------------------------
    //! (S/D)GEMM matrix-matrix product C = alpha * A * B + beta * C using the DNS algorithm with MPI communication and the basic optimized sequential GEMM for local computation.
    //!
    //! \param m Specifies the number of rows of the matrix A and of the matrix C.
    //! \param n Specifies the number of columns of the matrix B and the number of columns of the matrix C.
    //! \param k Specifies the number of columns of the matrix A and the number of rows of the matrix B.
    //! \param alpha Scalar value used to scale the product of matrices A and B.
    //! \param A Array, size lda-by-k. The leading m-by-k part of the array must contain the matrix A. All processes except root will ignore the value.
    //! \param lda Specifies the leading dimension of A. All processes except root will ignore the value.
    //! \param B Array, size ldb-by-n. The leading k-by-n part of the array must contain the matrix B. All processes except root will ignore the value.
    //! \param ldb Specifies the leading dimension of B. All processes except root will ignore the value.
    //! \param beta Scalar value used to scale matrix C.
    //! \param C Array, size ldc-by-n. The leading m-by-n part of the array must contain the matrix C. All processes except root will ignore the value.
    //! \param ldc Specifies the leading dimension of C. All processes except root will ignore the value.
    //! dns square matrix multiplication with mpi. C = A*B + C.
    //! \param n The matrix dimension.
    //! \param A The left input matrix. All processes except root will ignore the value.
    //! \param B The right input matrix. All processes except root will ignore the value.
    //! \param C The input and result matrix. All processes except root will ignore the value.
    //-----------------------------------------------------------------------------
    TReturn matmul_gemm_par_mpi_dns(
        TSize const m, TSize const n, TSize const k,
        TElem const alpha,
        TElem const * const MATMUL_RESTRICT A, TSize const lda,
        TElem const * const MATMUL_RESTRICT B, TSize const ldb,
        TElem const beta,
        TElem * const MATMUL_RESTRICT C, TSize const ldc);
    #ifdef __cplusplus
        }
    #endif
#endif
