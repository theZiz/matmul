#include <matmul/common/Config.h>   // TElem

#ifndef OMP_ELEM_NUM
    #define OMP_ELEM_NUM 256u
#endif

#define VEC2(y,x,w) (x+y*w)

void xl_c_mul(const TElem * restrict matA,const TElem * restrict matB, TElem* restrict matC,TSize sizeA,TSize sizeB,TSize sizeC)
{
    #pragma ibm independent_loop
    for( TSize i = 0; i < OMP_ELEM_NUM; ++i )
    {
        TElem * lineC = &(matC[VEC2(i,0,sizeC)]);
        #pragma ibm independent_loop
        for( TSize k = 0; k < OMP_ELEM_NUM; ++k )
        {
            const TElem a = matA[VEC2(i,k,sizeA)];
            const TElem * lineB = &(matB[VEC2(k,0,sizeB)]);
            #pragma ibm independent_loop
            for( TSize j = 0; j < OMP_ELEM_NUM; ++j )
            {
                    lineC[j] += a * lineB[j];
            }
        }
    }
}
