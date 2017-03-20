#include <matmul/common/Config.h>   // TElem

extern "C" void xl_c_mul(const TElem * matA,const TElem * matB, TElem* matC,TSize sizeA,TSize sizeB,TSize sizeC);
