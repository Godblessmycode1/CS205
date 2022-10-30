#pragma once
typedef struct
{
    int row;
    int column;
    float* matrix_data;
}Matrix;
Matrix* createMatrix(Matrix* matrix,int row,int column);
void valueMatrix(Matrix* input,float* array);
Matrix* addMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* subtractMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2);
Matrix* copyMatrix(Matrix* src,Matrix* dst);
Matrix* mulMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2);
void showMatrix(Matrix* input);
void addScalar(Matrix* input,float scalar);
void subScalar(Matrix* input,float scalar);
int minValue(Matrix* input,float* res);
int maxValue(Matrix* input,float* res);
void deleteMatrix(Matrix* matrix);
Matrix* transposedMatrix(Matrix* src,Matrix* dst);
void mulScalar(Matrix* input,float scalar);
int detrMatrix(Matrix* matrix,float* res);
float det(float* array,int n,int max);
float minor(float* array,int index,int n,int max);
Matrix* reverseMatrix(Matrix* src,Matrix* dst);