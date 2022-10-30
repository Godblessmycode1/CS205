#include "matrix.h"
#include "stdio.h"
int main(){
    float array[9]={2.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f};
    float array1[9]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f};
    float array2[12]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f};
    float array3[12]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f};
    float array4[1]={200.0f};
    Matrix* matrix1=createMatrix(matrix1,3,4);
    Matrix* matrix2=createMatrix(matrix2,4,3);
    Matrix* matrix3=createMatrix(matrix3,3,3);
    Matrix* matrix4=createMatrix(matrix4,3,4);
    valueMatrix(matrix1,array2);
    valueMatrix(matrix2,array3);
    valueMatrix(matrix3,array);
    valueMatrix(matrix4,array2);
    printf("The matrix1 is \n");
    showMatrix(matrix1);
    printf("The matrix2 is \n");
    showMatrix(matrix2);
    printf("The matrix3 is\n");
    showMatrix(matrix3);
    printf("The matrix4 is\n");
    showMatrix(matrix4);
    Matrix* matrix5=copyMatrix(matrix4,matrix5);
    printf("The copy matrix5 is\n");
    showMatrix(matrix5);
    Matrix* res=addMatrix(res,matrix1,matrix2);//invalid add
    res=addMatrix(res,matrix1,matrix4);//valid add
    printf("The res matrix after add matrix1 and matrix4 is\n");
    showMatrix(res);
    res=subtractMatrix(res,matrix1,matrix2);//invalid sub
    res=subtractMatrix(res,matrix1,matrix4);
    printf("The res matrix after sub matrix1 and matrix4 is\n");
    showMatrix(res);
    Matrix* res1=mulMatrix(res1,matrix1,matrix2);
    printf("The res1 matrix after matrix1 multiply matrix2 is \n");
    showMatrix(res1);
    addScalar(res1,1.0f);
    printf("The res1 after addScalar is\n");
    showMatrix(res1);
    subScalar(res1,1.0f);
    printf("The res1 after subScalar is\n");
    showMatrix(res1);
    mulScalar(res1,6.0f);
    printf("The res1 after mulScalar is\n");
    showMatrix(res1);
    Matrix* tran=transposedMatrix(res1,tran);
    printf("The tran matrix is\n");
    showMatrix(tran);
    float res2=0;
    if(maxValue(res1,&res2)==1){
        printf("The max value is %f\n",res2);
    }
    if(minValue(res1,&res2)==1){
        printf("The min value is %f\n",res2);
    }
    float res3=0;
    if(detrMatrix(matrix3,&res3)==1){
           printf("The determinant of matrix3 is %f\n",res3);
    }
    Matrix* reverse=reverseMatrix(matrix3,reverse);
    printf("The reverse matrix of matrix3 is\n");
    showMatrix(reverse);
}