#include "matrix.hpp"
#include<iostream>
using namespace std;
int main(){
  Matrix<float> test;
  float* temp=new float[8]{1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f};
  float* temp2=new float[4]{1.0f,2.0f,3.0f,4.0f};
  float* temp1=new float[8]{1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,9.0f};
  float* temp3=new float[4]{1.0f,2.0f,3.0f,4.0f};
  float* temp4=new float[32]{1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f,13.0f,14.0f,15.0f,16.0f,17.0f,18.0f,19.0f,20.0f,21.0f,22.0f,23.0f,24.0f,25.0f,26.0f,27.0f,28.0f,29.0f,30.0f,31.0f,32.0f};
  Matrix<float>test1(2,2,2,temp);
  cout<<"Test1 is\n"<<test1;
  Matrix<float>test2(2,2,2,temp1);
  cout<<"Test2 is\n"<<test2;
  Matrix<float>test3=test1+test2;
  cout<<"Test3 is\n"<<test3;
  test3=test1-test2;
  cout<<"Test3 is\n"<<test3;
  Matrix<float>test4;
  test4=test1*test2;
  cout<<"Test4 is\n"<<test4;
  Matrix<float>test5(4,4,2,temp4);
  cout<<"Test5 is\n"<<test5;
  Matrix<float>test6=test5.roi(1,1,2,2);
  cout<<"test6 is:"<<endl;
  cout<<test6<<endl;
  cout<<test6+test4;
}