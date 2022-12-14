#include<iostream>
#include<string.h>
template < class T>
class Matrix{
  private:
   size_t row;
   size_t col;
   size_t channel;
   unsigned int* ref_num;//用于解决多个矩阵指向一个地址 soft copy问题,只有在assign operator中才会调用。
   size_t step;//数据走一行多远。
   T* data;
   Matrix* parent;
  public:
   friend std::ostream & operator<<(std::ostream & os, const Matrix & mat);
   Matrix();
   Matrix(size_t row,size_t col,size_t channel,T* tp);
   Matrix(size_t row,size_t col,size_t channel);//用于生成数据矩阵。
   Matrix(const Matrix& mat);
   size_t getRow()const;
   size_t getCol()const;
   size_t getChannel()const;
   size_t getStep()const;
   Matrix* getParent()const;
   unsigned int getRefCount()const;
   Matrix operator=(const Matrix & mat);
   Matrix operator +(const Matrix & mat)const;
   Matrix operator-(const Matrix & mat) const;
   bool operator==(const Matrix &mat);
   Matrix operator*(const Matrix & mat) const;
   Matrix roi(size_t row_index,size_t col_index,size_t roi_row_length,size_t roi_col_length);
   ~Matrix();
};
template<class T>
Matrix<T>::Matrix(){
    this->row=0;
    this->col=0;
    this->channel=0;
    this->step=0;
    this->ref_num=new unsigned int{1};
    this->data=nullptr;//因为共享内存，直接赋一个nullptr就可以了。
    this->parent=nullptr;
}
template<class T>
Matrix<T>::Matrix(size_t row,size_t col,size_t channel,T* tp){
    if(channel==0){
      std::cerr<<"Channel should be at least 1,exit"<<std::endl;
      exit(EXIT_FAILURE);
    }
    this->channel=channel;
    this->row=row;
    this->col=col;
    this->step=col*channel;//一行数据多长。
    this->parent=nullptr;
    this->ref_num=new unsigned int{1};
    if(tp==nullptr){
      this->data=nullptr;
    }
    else{
      this->data=new T[row*col*channel];
      memcpy(this->data,tp,sizeof(T)*row*col*channel);
    }
}

template<class T>
Matrix<T>::Matrix(size_t row,size_t col,size_t channel){ 
  if(channel==0){
    std::cerr<<"The channel should be at least 1,exit"<<std::endl;
    exit(EXIT_FAILURE);
  }
  this->row=row;
  this->col=col;
  this->channel=channel;
  this->step=col*channel;
  this->ref_num=new unsigned int{1};
  this->data=nullptr;//如果是0,指向空指针，空数据.
  this->data=new T[row*col*channel];
}
template<class T>
Matrix<T>::~Matrix(){
  this->ref_num[0]--;
  if(this->ref_num[0]==0){ //应该删除
     if(this->parent==nullptr){  //不为子矩阵才会删除数据，若为子矩阵则等待父亲的构析函数即可。
       delete []this->data;
     }
     delete this->ref_num;//删除ref_num的内存//
  }
}
template<class T>
size_t Matrix<T>::getRow() const{
  return this->row;
}
template<class T>
size_t Matrix<T>::getCol() const{
  return this->col;
}
template <class T>
size_t Matrix<T>::getChannel() const{
   return this->channel;
}
template <class T>
size_t Matrix<T>::getStep()const{
  return this->step;
}
template <class T>
Matrix<T>* Matrix<T>::getParent()const{
  return this->parent;
}
template<class T>
Matrix<T>::Matrix(const Matrix<T> & mat){ //copy constructor
    this->row=mat.row; //复制行
    this->col=mat.col; //复制列
    this->channel=mat.channel; //复制通道。
    this->parent=mat.parent; //复制父亲
    this->step=mat.step; //复制一行长度
    this->ref_num=mat.ref_num; 
    mat.ref_num[0]++;//引用数目加一
    this->data=mat.data;
}
template <class T>
unsigned int Matrix<T>::getRefCount()const{
 return this->ref_num[0];
}
template <class T>
Matrix<T> Matrix<T>::operator =(const Matrix<T> & mat){
   if(this==&mat){
    return *this;
   }
   if(this->ref_num[0]==1){ //释放数据和指针。
    delete this->data;
    delete this->ref_num; //释放指针
   }
   else{
      
      this->ref_num[0]--;
   }
   this->row=mat.row;
   this->col=mat.col;
   this->step=mat.step;
   this->channel=mat.channel;
   this->data=mat.data;
   this->ref_num=mat.ref_num; //指向同一个ref_count并++
   this->ref_num[0]++;
   this->parent=mat.parent;
   return *this;
}
template <class T>
bool Matrix<T>::operator==(const Matrix & mat){
    if(this->row!=mat.row||this->col!=mat.col||this->channel!=mat.channel){
      return false;
    }
      for(size_t i=0;i<this->row;i++){
        for(size_t j=0;j<this->col;j++){
          for(size_t k=0;k<this->channel;k++){
            if(this->data[(i*col+j)*channel+k]!=mat.data[(i*col+j)*channel+k]){
              return false;
            }
          }
        }
      }
    return true;
}
template <class T>
std::ostream & operator<<(std::ostream & os,const Matrix<T> & mat){
   if(mat.data==nullptr){
    std::cerr<<"There is no data"<<std::endl;
    return os;
   }
      for(size_t i=0;i<mat.row;i++){
        for(size_t j=0;j<mat.col;j++){
          os<<"(";
          for(size_t k=0;k<mat.channel;k++){
            os<<mat.data[i*mat.step+j*mat.channel+k];
            os<<" ";
          }
          os<<")";
        }
        os<<"\n";
      }
   return os;
}
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & mat) const{
   if(this->row!=mat.row||this->col!=mat.col||this->channel!=mat.channel){
      std::cerr<<"The row or column or channel don't match please check carefully"<<std::endl;
      exit(EXIT_FAILURE);
   }
   Matrix temp(this->row,this->col,this->channel);
  for(size_t i=0;i<this->row;i++){
      for(size_t j=0;j<this->col;j++){
        for(size_t k=0;k<this->channel;k++){
          temp.data[i*temp.step+j*temp.channel+k]=this->data[i*this->step+j*this->channel+k]+mat.data[i*mat.step+j*mat.channel+k];
        }
      }
    }
   return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & mat) const{
  if(this->row!=mat.row||this->col!=mat.col||this->channel!=mat.channel){
      std::cerr<<"The row or column or channel  don't match please check carefully"<<std::endl;
      exit(EXIT_FAILURE);
   }
   Matrix temp(this->row,this->col,this->channel);
    for(size_t i=0;i<this->row;i++){
      for(size_t j=0;j<this->col;j++){
        for(size_t k=0;k<this->channel;k++){
          temp.data[i*temp.step+j*temp.channel+k]=this->data[i*this->step+j*this->channel+k]-mat.data[i*mat.step+j*mat.channel+k];
        }
      }
    }
   return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & mat) const{
    if(this->row!=mat.col||this->col!=mat.row||this->channel!=mat.channel){
      std::cerr<<"The size of two matrixs don't match"<<std::endl;
      exit(EXIT_FAILURE);
    }
    Matrix temp(this->row,mat.col,this->channel);//带通道的矩阵相乘要一个通道一个通道的算
    //Eg.储存结果矩阵的第一行与第一列的channel1的结果是第一行与第一列channel1的结果.
    for(size_t channel_index=0;channel_index<mat.channel;channel_index++){
      for(size_t row_index=0;row_index<mat.row;row_index++){
        for(size_t col_index=0;col_index<mat.col;col_index++){
           for(size_t col_length=0;col_length<this->col;col_length++){
               temp.data[row_index*temp.step+col_index*temp.channel+channel_index]+=this->data[row_index*this->step+this->channel*col_length+channel_index]*mat.data[channel_index+mat.channel*col_length+col_length*mat.step];
           }
        }
      }
    }
    return temp;
}
template <class T>
Matrix<T> Matrix<T>::roi(size_t row_index,size_t col_index,size_t roi_row_length,size_t roi_col_length){
          if(this->data=nullptr){
            std::cerr<<"There is no data in the father matrix, return a matrix with no data"<<std::endl;
            Matrix temp;
            return temp;
          }
          if(row_index+roi_row_length>this->row||col_index+roi_col_length>this->col){
            std::cerr<<"The roi region is not valid"<<std::endl;
            exit(EXIT_FAILURE);
          }
          //开始提取roi,将子矩阵的data指针指向父矩阵的roi开始位置。
          Matrix temp;
          temp.channel=this->channel;
          temp.row=roi_row_length;
          temp.col=roi_col_length;
          temp.parent=this;
          temp.data=this->data+(row_index*this->step+col_index*channel); //父矩阵row_index行,col_index列的位置指针。
          temp.step=this->step;//因为是soft copy，对于子矩阵来说，想要跳到下一行的数据的长度与父矩阵的行长度相同。
          temp.ref_num=new unsigned int{1};
          return temp;
}