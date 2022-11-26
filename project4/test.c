#include<stdio.h>
#include "matrix.h"
#include "multiply.h"
int main(){
    size_t s0=16;
    size_t s1=128;
    size_t s2=1024;
    // unsigned long long s3=8*1024;
    size_t s3=4096;
    size_t s4=8192;
    // unsigned long long s4=64*1024;//分配内存是乘法，会溢出，使用long long,防止乘法时候溢出为负。
    Matrix* matrix=createMatrix(matrix,s0,s0);
    Matrix* matrix_res;
    FILE* fp=fopen("data/data_16.txt","r");
    valueMatrixFile(matrix,fp);
    fclose(fp);
    Matrix* matrix_copy=copyMatrix(matrix,matrix_copy);
    matmulPlain(matrix_res,matrix,matrix_copy);
    matualImporvedTranspose(matrix_res,matrix,matrix_copy);
    matualImprovedTransposeSimd(matrix_res,matrix,matrix_copy);
    matualTransposedBlockingSimd(matrix_res,matrix,matrix_copy);
    matualFastTransposedBlockingSimd(matrix_res,matrix,matrix_copy);
    deleteMatrix(matrix);
    deleteMatrix(matrix_copy);
    printf("matrix complete all\n");
    // ////
    // ////
    Matrix* matrix1=createMatrix(matrix1,s1,s1);
    Matrix* matrix1_res;
    FILE* fp1=fopen("data/data_128.txt","r");
    valueMatrixFile(matrix1,fp1);
    fclose(fp1);
    Matrix* matrix1_copy=copyMatrix(matrix1,matrix1_copy);
    matmulPlain(matrix1_res,matrix1,matrix1_copy);
    matualImporvedTranspose(matrix1_res,matrix1,matrix1_copy);
    matualImprovedTransposeSimd(matrix1_res,matrix1,matrix1_copy);
    matualTransposedBlockingSimd(matrix1_res,matrix1,matrix1_copy);
    matualFastTransposedBlockingSimd(matrix1_res,matrix1,matrix1_copy);
    deleteMatrix(matrix1);
    deleteMatrix(matrix1_copy);
    printf("matrix1 complete all\n");
    // ////
    // ////
    Matrix* matrix2=createMatrix(matrix2,s2,s2);
    Matrix* matrix2_res;
    FILE* fp2=fopen("data/data_1k.txt","r");
    valueMatrixFile(matrix2,fp2);
    fclose(fp2);
    Matrix* matrix2_copy=copyMatrix(matrix2,matrix2_copy);
    matmulPlain(matrix2_res,matrix2,matrix2_copy);
    matualImporvedTranspose(matrix2_res,matrix2,matrix2_copy);
    matualImprovedTransposeSimd(matrix2_res,matrix2,matrix2_copy);
    matualTransposedBlockingSimd(matrix2_res,matrix2,matrix2_copy);
    matualFastTransposedBlockingSimd(matrix2_res,matrix2,matrix2_copy);
    deleteMatrix(matrix2);
    deleteMatrix(matrix2_copy);
    printf("matrix2 complete all\n");
    // ////
    // ////
    Matrix* matrix3=createMatrix(matrix3,s3,s3);
    Matrix* matrix3_res;
    FILE* fp3=fopen("data/data_4k.txt","r");
    valueMatrixFile(matrix3,fp3);
    fclose(fp3);
    Matrix* matrix3_copy=copyMatrix(matrix3,matrix3_copy);
    matmulPlain(matrix3_res,matrix3,matrix3_copy);
    matualImporvedTranspose(matrix3_res,matrix3,matrix3_copy);
    matualImprovedTransposeSimd(matrix3_res,matrix3,matrix3_copy);
    matualTransposedBlockingSimd(matrix3_res,matrix3,matrix3_copy);
    matualFastTransposedBlockingSimd(matrix3_res,matrix3,matrix3_copy);
    deleteMatrix(matrix3);
    deleteMatrix(matrix3_copy);
    printf("matrix3 complete all\n");
    ////
    ////
    Matrix* matrix4=createMatrix(matrix4,s4,s4);
    Matrix* matrix4_res;
    FILE* fp4=fopen("data/data_8k.txt","r");
    valueMatrixFile(matrix4,fp4);
    fclose(fp4);
    Matrix* matrix4_copy=copyMatrix(matrix4,matrix4_copy);
    matmulPlain(matrix4_res,matrix4,matrix4_copy);
    matualImporvedTranspose(matrix4_res,matrix4,matrix4_copy);
    matualImprovedTransposeSimd(matrix4_res,matrix4,matrix4_copy);
    matualTransposedBlockingSimd(matrix4_res,matrix4,matrix4_copy);
    matualFastTransposedBlockingSimd(matrix4_res,matrix4,matrix4_copy);
    deleteMatrix(matrix4);
    deleteMatrix(matrix4_copy);
    printf("all complete\n");
}