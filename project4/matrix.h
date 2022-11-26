#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <float.h>
#pragma once
typedef struct
{
    size_t row;
    size_t column;
    float* matrix_data;
}Matrix;
Matrix* createMatrix(Matrix* matrix,size_t row,size_t column);
void valueMatrixFile(Matrix* input,FILE* file);
void valueMatrix(Matrix* input,float* array);
Matrix* copyMatrix(Matrix* src,Matrix* dst);
Matrix* mulMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2);
void showMatrix(Matrix* input);
void deleteMatrix(Matrix* matrix);
Matrix* transposedMatrix(Matrix* src,Matrix* dst);



