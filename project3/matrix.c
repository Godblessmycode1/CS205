#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <float.h>
#include<math.h>
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
void mulScalar(Matrix* input,float scalar);
int maxValue(Matrix* input,float* res);
int minValue(Matrix* input,float* res);
void deleteMatrix(Matrix* matrix);
Matrix* transposedMatrix(Matrix* src,Matrix* dst);
int detrMatrix(Matrix* matrix,float* res);
float det(float* array,int n,int max);
float minor(float* array,int index,int n,int max);
Matrix* reverseMatrix(Matrix* src,Matrix* dst);
Matrix* createMatrix(Matrix* matrix,int row,int column){ //矩阵初始化
      if(row>0&&column>0){
           matrix=(Matrix*)malloc(sizeof(matrix)); //方便free
           matrix->row=row;
           matrix->column=column;
           matrix->matrix_data=(float*)malloc(sizeof(float)*row*column); //方便free
           memset(matrix->matrix_data,0,sizeof(float)*row*column);//初始化为0
           return matrix;
      }
      else{
        printf("The row or column is not positive\n");
        return NULL;
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
Matrix* addMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2){
    if(matrix1==NULL||matrix2==NULL){
        printf("The addMatrix input is not valid\n");
        return NULL;
    }
    if(matrix1->row==matrix2->row&&matrix1->column==matrix2->column){
        res=createMatrix(res,matrix1->row,matrix1->column);
        float* res_data=res->matrix_data;
        float* matrix1_data=matrix1->matrix_data;
        float* matrix2_data=matrix2->matrix_data;
            for(int i=0;i<matrix1->row;i++){
                for(int j=0;j<matrix2->column;j++){
                    (*res_data++)=(*matrix1_data++)+(*matrix2_data++);//相加并移动一个float单位
                }
            }
        return res;
    }
    else{
        printf("The matrix size does not match addMatrix\n");
        printf("The row and column of matrix1 is %d,%d\n",matrix1->row,matrix1->column);
        printf("The row and column of matrix2 is %d,%d\n",matrix2->row,matrix2->column);
        return NULL;
    }
}
Matrix* subtractMatrix(Matrix* res,Matrix* matrix1,Matrix* matrix2){ //第一个矩阵减第二个矩阵
     if(matrix1==NULL||matrix2==NULL){
        printf("The input is not valid in subtractMatrix\n");
        return NULL;
     }
     if(matrix1->row==matrix2->row&&matrix1->column==matrix2->column){
        res=createMatrix(res,matrix1->row,matrix1->column);
        float* res_data=res->matrix_data;
        float* matrix1_data=matrix1->matrix_data;
        float* matrix2_data=matrix2->matrix_data;
            for(int i=0;i<matrix1->row;i++){
                for(int j=0;j<matrix2->column;j++){
                    (*res_data++)=(*matrix1_data++)-(*matrix2_data++);//相减并移动一个float单位
                }
            }
        return res;
    }
    else{
        printf("The matrix size does not match substractMatrix\n");
        printf("The row and column of matrix1 is %d,%d\n",matrix1->row,matrix1->column);
        printf("The row and column of matrix2 is %d,%d\n",matrix2->row,matrix2->column);
    }
}
Matrix* copyMatrix(Matrix* src,Matrix* dst){//src是源，dst是目的地
      if(src!=NULL){
         dst=createMatrix(dst,src->row,src->column);
         valueMatrix(dst,src->matrix_data);
         return dst;
      }
      else{
        printf("At least one pointer is not valid in copyMatrix\n");
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
        for(int i=0;i<matrix1->row;i++){
            for(int j=0;j<matrix2->column;j++){
                for(int k=0;k<matrix1->column;k++){
                    res_data[i*matrix2->column+j]+=matrix1_data[i*matrix1->column+k]*matrix2_data[k*matrix2->column+j];
                }
            }
        }
        return res;
    }
    else{
        printf("The matrix size does not match multiplyMatrix\n");
        printf("The row and column of matrix1 is %d,%d\n",matrix1->row,matrix1->column);
        printf("The row and column of matrix2 is %d,%d\n",matrix2->row,matrix2->column);
        return NULL;
    }
}
void showMatrix(Matrix* input){
    if(input==NULL){
        printf("invalid input in showMatrix\n");
        return;
    }
    float* temp=input->matrix_data;
    for(int i=0;i<input->row;i++){
        for(int j=0;j<input->column;j++){
            printf("%f ",*(temp++));
        }
        printf("\n");
    }
}
void addScalar(Matrix* input,float scalar){
    if(input==NULL){
        printf("The input matrix is not valid in addScalar\n");
        return;
    }
    else{
        float* data=input->matrix_data;
        for(int i=0;i<input->row;i++){
            for(int j=0;j<input->column;j++){
                *(data)=*(data)+scalar;
                data++;
            }
        }
    }
}
void subScalar(Matrix* input,float scalar){
    if(input==NULL){
        printf("The input matrix is not valid in subScalar\n");
        return;
    }
    else{
        float* data=input->matrix_data;
        for(int i=0;i<input->row;i++){
            for(int j=0;j<input->column;j++){
                *(data)=*(data)-scalar;
                data++;
            }
        }
    }
}
void mulScalar(Matrix* input,float scalar){
     if(input==NULL){
        printf("The input matrix is not valid in mulScalar\n");
        return;
    }
    else{
        float* data=input->matrix_data;
        for(int i=0;i<input->row;i++){
            for(int j=0;j<input->column;j++){
                *(data)=*(data)*scalar;
                data++;
            }
        }
    }
}
int minValue(Matrix* input,float* res){
    if(input==NULL){
        printf("The input matrix is not valid in minValue\n");
        return 0;
    }
    else{
       float temp=FLT_MAX;
       float* data=input->matrix_data;
       for(int i=0;i<input->row;i++){
        for(int j=0;j<input->column;j++){
            if(*(data)<temp){
                temp=*(data);
                data++;
            }
        }
       }
       *res=temp;
       return 1;
    }
}
int maxValue(Matrix* input,float* res){
    if(input==NULL){
        printf("The input matrix is not valid in maxValue\n");
        return 0;
    }
    else{
       float temp=FLT_MIN;
       float* data=input->matrix_data;
       for(int i=0;i<input->row;i++){
        for(int j=0;j<input->column;j++){
            if(*(data)>temp){
                temp=*(data);
                data++;
            }
        }
       }
       *res=temp;
       return 1;
    }
}
void deleteMatrix(Matrix* matrix){
    free(matrix->matrix_data);
    free(matrix);
}
Matrix* transposedMatrix(Matrix* src,Matrix* dst){
    if (src==NULL)
    {
        printf("The input is not valid in transposedMatrix\n");
        return NULL;
    }  
    dst=createMatrix(dst,src->column,src->row);//转置行列互换
    for(int i=0;i<dst->row;i++){
        for(int j=0;j<dst->column;j++){
            dst->matrix_data[i*dst->column+j]=src->matrix_data[j*src->column+i];
        }
    }
    return dst;
}

int detrMatrix(Matrix* matrix,float* res){ //求行列式
     if(matrix==NULL||res==NULL){
        printf("Input invalid pointer in detrMatrix\n");
         return 0;
     }
     else if (matrix->row!=matrix->column)
     {  printf("The matrix is not a square matrix , no determinet\n");
        return 0;
     }
     else{
       *res=det(matrix->matrix_data,matrix->row,matrix->row);
       return 1;
     }  
}
float det(float* array,int n,int max){//array 是矩阵,n代表矩阵的长和宽,max代表输入matrix的长度和宽度即递归调用中的最大维度（对于后续递归调用过程来说要释放内存的）。
     int row=0;//第一行本行列式计算一直用第一行做展开
     float M=0;//用于计算余子式的值;
     float res=0;//用于计算行列式结果
     if(n==1){
        return array[0];
     }
     else {
        for(int index=0;index<n;index++){
            M=minor(array,index,n,max); //M为除去这一行这一列的余子式值。
            float component=0;
            if(index%2==0){
               component=1.0f;
            }
            else{
                component=-1.0f;
            }
            res+=component*array[index]*M;
        }
     }
     if(n!=max){
        free(array);
     }
     return res;
}
float minor(float* array,int index,int n,int max){ //n代表为n阶余子式.index代表选取的的行数为展开的行。
     float* sub_array=(float*)malloc(sizeof(float)*(n-1)*(n-1));
     memset(sub_array,0,sizeof(float)*(n-1)*(n-1));
     int row_length=n-1;
     int column_length=n-1;
     for(int i=0;i<row_length;i++){
        for(int j=0;j<column_length;j++){
            if (j<index)
            {
                sub_array[i*column_length+j]=array[(i+1)*n+j];
            }
            else{
                sub_array[i*column_length+j]=array[(i+1)*n+j+1];
            }
        }
     }
     return det(sub_array,n-1,max);
}
Matrix* reverseMatrix(Matrix* src,Matrix* dst){ //将src的逆矩阵放入dst中
        float determinant=0;
        if (src==NULL)
        {   printf("Src is not valid in reverseMatrix\n");
            return NULL;
        }
        else if(detrMatrix(src,&determinant)!=1){
            return NULL;
        }
        else{
            if(determinant==0){
                printf("The determinant is 0, no reverse matrix");
                return NULL;
            }
            else{
                dst=transposedMatrix(src,dst);
                mulScalar(dst,1.0f/determinant);
                return dst;
            }
        }
}