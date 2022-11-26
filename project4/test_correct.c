#include "multiply.h"
#include "matrix.h"
int correctTest(Matrix* true, Matrix* test){
    if (true->column==test->column&&true->row==test->row)
    {
        for(int i=0;i<true->row;i++){
            for(int j=0;j<true->column;j++){
                if(true->matrix_data[i*true->column+j]!=test->matrix_data[i*true->column+j]){
                  return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}
int main(){
    size_t s0=16;
    Matrix* matrix=createMatrix(matrix,s0,s0);
    Matrix* matrix_res;
    FILE* fp=fopen("data/data_16.txt","r");
    valueMatrixFile(matrix,fp);
    fclose(fp);
    Matrix* matrix_copy=copyMatrix(matrix,matrix_copy);
    Matrix* res=mulMatrix(res,matrix,matrix_copy); //必然正确
    Matrix* res1=multiplyTransposeSimd(res1,matrix,matrix_copy);
    printf("Transpose simd is the same or not %d",correctTest(res,res1));
    Matrix* res2=multiplyTransposeMatrix(res2,matrix,matrix_copy);
    printf("Transpose simd is the same or not %d",correctTest(res,res2));
    Matrix* res3=multiplyTransposeBlockingSimd(res3,matrix,matrix_copy);
    printf("Transpose blocking simd is the same or not %d",correctTest(res,res3));
    deleteMatrix(matrix);
    deleteMatrix(matrix_copy);
    deleteMatrix(res);
    deleteMatrix(res1);
    deleteMatrix(res2);
    deleteMatrix(res3);
}