#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <float.h>
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
Matrix* createMatrix(Matrix* matrix,size_t row,size_t column){ //矩阵初始化
           matrix=(Matrix*)aligned_alloc(32,sizeof(matrix)); //方便free
           matrix->row=row;
           matrix->column=column;
          //matrix->matrix_data=(float*)malloc(sizeof(float)*row*column); //方便free
           matrix->matrix_data=(float*)aligned_alloc(32,sizeof(float)*row*column);//内存对齐.
           memset(matrix->matrix_data,0,sizeof(float)*row*column);//初始化为0
           return matrix;
      
}
void valueMatrixFile(Matrix* input,FILE* file){ //文件过大，通过文件流输入
    for(size_t i=0;i<input->row;i++){
        for (size_t j = 0; j < input->column; j++)
        {
            fscanf(file,"%f",&input->matrix_data[i*input->column+j]);
        }
    }
}
void valueMatrix(Matrix* input,float* array){
 if (input!=NULL&&array!=NULL)
 {
     memcpy(input->matrix_data,array,sizeof(float)*input->row*input->column);
 }
 else{
    printf("Input an invalid pointer in valueMatrix\n");
 }
}

Matrix* copyMatrix(Matrix* src,Matrix* dst){//src是源，dst是目的地
      if(src!=NULL){
         dst=createMatrix(dst,src->row,src->column);
         valueMatrix(dst,src->matrix_data);
         return dst;
      }
      else{
        return NULL;
      }
}
Matrix* mulMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2){ //here is the code
    if(matrix1==NULL||matrix2==NULL){
        printf("The input is not valid in mulMatrix\n");
        return NULL;
    }
    if(matrix1->column==matrix2->row&&matrix1->row==matrix2->column){
        res=createMatrix(res,matrix1->row,matrix2->column);
        float* res_data=res->matrix_data;
        float* matrix1_data=matrix1->matrix_data;
        float* matrix2_data=matrix2->matrix_data;
        for(size_t i=0;i<matrix1->row;i++){
            for(size_t j=0;j<matrix2->column;j++){
                for(size_t k=0;k<matrix1->column;k++){
                    res_data[i*matrix2->column+j]+=matrix1_data[i*matrix1->column+k]*matrix2_data[k*matrix2->column+j];
                }
            }
        }
        return res;
    }
    else{
        return NULL;
    }
}
void showMatrix(Matrix* input){
    if(input==NULL){
        printf("invalid input in showMatrix\n");
        return;
    }
    float* temp=input->matrix_data;
    for(size_t i=0;i<input->row;i++){
        for(size_t j=0;j<input->column;j++){
            printf("%f ",*(temp++));
        }
        printf("\n");
    }
}
void deleteMatrix(Matrix* matrix){
    free(matrix->matrix_data);
    free(matrix);
}
Matrix* transposedMatrix(Matrix* src,Matrix* dst){
    if (src==NULL)
    {
        return NULL;
    }  
    dst=createMatrix(dst,src->column,src->row);//转置行列互换
    for(size_t i=0;i<dst->row;i++){
        for(size_t j=0;j<dst->column;j++){
            dst->matrix_data[i*dst->column+j]=src->matrix_data[j*src->column+i];
        }
    }
    return dst;
}
