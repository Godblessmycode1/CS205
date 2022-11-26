#pragma once
#include "matrix.h"
#include <immintrin.h>
#include <smmintrin.h>
void matmulPlain(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* multiplyTransposeMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2);
void matualImporvedTranspose(Matrix* res, Matrix* matrix1,Matrix* matrix2);
Matrix* multiplyTransposeSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);
void matualImprovedTransposeSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* multiplyTransposeBlockingSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);
void matualTransposedBlockingSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* multiplyFastTransposeBlockingSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* fastTransposedMatrix(Matrix* src,Matrix* dst);
void fastTrans(float* src,float* dst,size_t row,size_t col);
void tranBlock8(float** src_array,float** dst_array);
void tranBlock4(const __m128 s1,const __m128 s2, const __m128 s3, const __m128 s4,float* d1,float* d2,float* d3,float*d4);
void matualFastTransposedBlockingSimd(Matrix* res,Matrix* matrix1,Matrix* matrix2);