#include<regex>
#include<iostream>
#include<string>
using namespace std;
extern regex isAllNumericInteger;
extern regex isAllNumericFloat;

bool negative;
cmatch m;
struct Num
{
   char input_num [200]={0};
   int scale=0;
};
struct OperatorStack
{
   char operator_stack[200];
   int top=-1;
};
struct OperandStack
{
    Num operand_stack[200];
    int top=-1;
};

void moveArrayLeft(char value[]){ //用于将3.00变成300 scale=-2，其中-2在前一步已经提出。
   int len=strlen(value);
   int index=0;//used to store the index of '.'
   for(int i=0;i<len;i++){
      if (value[i]=='.')
      {
         index=i;
         break;
      }
   }
   for(int i=index;i<len-1;i++){
      value[i]=value[i+1];
   }
   value[len-1]='\0';
}
void charArrayReverse(char a[]){ //用于将数组反转，方便相乘，相加以及反转。
    char temp;
    int index=strlen(a);
    for(int i=0;i<index/2;i++){
            temp=a[i];
            a[i]=a[index-i-1];
            a[index-i-1]=temp;
    }
}
void moveArrayRight(char a[],int step){ //用于将数组右移，根据不同num scale的差值。
int len=strlen(a);
for(int i=len;i>=0;i--){
   if(i+step<200){
     a[i+step]=a[i];
   }
   else{
      return;
   }
 }

for(int i=0;i<step;i++){ //填充为0。
   a[i]='0';
 }
}
void moveArrayRightBeforeCal(Num* res,Num* num1,Num* num2){ //加减计算前需要自动根据scale差移动。
    int step=0;
  if((*num1).scale>(*num2).scale){
      step=(*num1).scale-(*num2).scale;
      moveArrayRight((*num1).input_num,step);
  }
  else{
      step=(*num2).scale-(*num1).scale;
      moveArrayRight((*num2).input_num,step);
  }
  (*res).scale=min((*num1).scale,(*num2).scale);
}
void  initialNum(Num* num,char value[]){
   int len=strlen(value);
   char temp[200]={0};
   if(regex_match(value,m,isAllNumericInteger)){
      strncpy((*num).input_num,value+0,len);
      charArrayReverse((*num).input_num);
      (*num).scale=0;
   }
   else if(regex_match(value,m,isAllNumericFloat)){
      for(int i=0;i<len;i++){
         if(value[i]=='.'){
           (*num).scale=-(len-1-i);
           break;
         }
      }
      moveArrayLeft(value);
      len=strlen(value); // new_length=old_length-1;
      int first=0;
      while(value[first]=='0'){
         first++;
      }
      strncpy((*num).input_num,value+first,len-first);
      charArrayReverse((*num).input_num);
   }
}
bool isEmptyOperandStack(OperandStack* operand_stack){ //判断是否为空
  return (*operand_stack).top==-1;
}
bool isEmptyOperatorStack(OperatorStack* operator_stack){ 
   return (*operator_stack).top==-1;
}
void pushOperandStack(OperandStack* operatand_stack_input,Num* num){ 
   if(negative&&isEmptyOperandStack){
      int len=strlen((*num).input_num);
      (*num).input_num[len]='-';
      negative=false;
   }
   (*operatand_stack_input).top++;
   (*operatand_stack_input).operand_stack[(*operatand_stack_input).top]=*num;
}

void pushOperatorStack(OperatorStack* operator_stack_input,char operator_input){
   (*operator_stack_input).top++;
   (*operator_stack_input).operator_stack[(*operator_stack_input).top]=operator_input;
}
void addArray(char res[],char input1[],char input2[]){//数组已经反转并且移动完。
     int len1=strlen(input1);
     int len2=strlen(input2);
     int len=max(len1,len2);
     for(int i=0;i<len;i++){
      if(input1[i]!=0&&input2[i]!=0){
         res[i]=input1[i]-'0'+input2[i]-'0';
      }
      else if(input1[i]!=0){
         res[i]=input1[i]-'0';
      }
      else{
         res[i]=input2[i]-'0';
      }
     }
     for(int i=0;i<len;i++){
      if(res[i]>=10){
        res[i+1]+=res[i]/10;
        res[i]=res[i]%10;
      }
     }
     for(int i=0;i<=len;i++){
      res[i]=res[i]+'0';
     }
     int first=len;
     while(first>0){
      if(res[first]=='0'){
         res[first]=0;
         first--;
      }
      else{
         break;
      }
     }
}
void minusArray(char res[],char input1[],char input2[]){ //默认input1>=input2都为非负数,有函数检验的在int compareArray(char input1[],char input2[])里
   int len1=strlen(input1);
   int len2=strlen(input2);
   int len=max(len1,len2);
        for(int i=0;i<len;i++){
         if(input1[i]!=0&&input2[i]!=0){
            res[i]=input1[i]-input2[i];
         }
         else if(input1[i]!=0){
            res[i]=input1[i]-'0';
         }
        }
        for(int i=0;i<len;i++){
         if(res[i]<0){
            res[i]=res[i]+10;
            res[i+1]=res[i+1]-1;
         }
        }
        for(int i=0;i<len;i++){
         res[i]=res[i]+'0';
        }
        int first=len-1;
        while(first>0){
         if(res[first]=='0'){
            res[first]=0;
            first--;
         }
         else{
            break;
         }
        }
}
int compareArrayByteByByte(char input1[],char  input2[]){//默认都是非负数。因为负数之间比较都可以转为整数取负。
    int len1=strlen(input1);
    int len2=strlen(input2);
    int len=max(len1,len2);
    int first=len-1;
    while(first>=0){
      if(input1[first]<input2[first]){
         return -1;
      }
      else if(input1[first]==input2[first]){
         first--;
      }
      else{
         break;
      }
    }
   if(first<0){
      return 0;
   }
   return 1;
}
int compareArray(char input1[],char input2[]){ //用于比较两数大小。1代表input1>=input2,-1则相反。此时已经根据scale差值，完成移位。
     int len1=strlen(input1);
     int len2=strlen(input2);
     //只考虑input1>input2的情况。
     if(input1[len1-1]!='-'&&input2[len2-1]=='-'){//一正一负
      return 1;
     }
     else if(input1[len1-1]!='-'&&input2[len2-1]!='-'){ //同为正。
        return compareArrayByteByByte(input1,input2);
     }
     else if(input1[len1-1]=='-'&&input2[len2-1]=='-'){
      char temp1[200];
      char temp2[200];
      strncpy(temp1,input1+0,len1);
      strncpy(temp2,input2+0,len2);
      temp1[len1-1]=0;
      temp2[len2-1]=0;
      return -compareArrayByteByByte(temp1,temp2);
     }
     return -1;
}
void addNum(Num* res,Num* num1,Num* num2){ //用于两数字相加
  moveArrayRightBeforeCal(res,num1,num2);
  int len1=strlen((*num1).input_num);
  int len2=strlen((*num2).input_num);
  if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]=='-'){
    (*num1).input_num[len1-1]=0;
    (*num2).input_num[len2-1]=0;
    addArray((*res).input_num,(*num1).input_num,(*num2).input_num);
    int len=strlen((*res).input_num);
    (*res).input_num[len]='-';
  }
  else if((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]!='-'){
    addArray((*res).input_num,(*num1).input_num,(*num2).input_num);
  }
  else if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]!='-'){
      (*num1).input_num[len1-1]=0;
      if(compareArray((*num1).input_num,(*num2).input_num)>=0){
         minusArray((*res).input_num,(*num1).input_num,(*num2).input_num);
         int len=strlen((*res).input_num);
         (*res).input_num[len]='-';
      }
      else{
         minusArray((*res).input_num,(*num2).input_num,(*num1).input_num);
      }
  }
  else{
      (*num2).input_num[len2-1]=0;
      if(compareArray((*num1).input_num,(*num2).input_num)>=0){
         minusArray((*res).input_num,(*num1).input_num,(*num2).input_num);
      }
      else{
         minusArray((*res).input_num,(*num2).input_num,(*num1).input_num);
         int len=strlen((*res).input_num);
         (*res).input_num[len]='-';
      }
  }
}
void  minusNum(Num* res,Num* num1,Num* num2){//两数相减
moveArrayRightBeforeCal(res,num1,num2);
int len1=strlen((*num1).input_num);
int len2=strlen((*num2).input_num);
 if((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]!='-'){
      if(compareArray((*num1).input_num,(*num2).input_num)>=0){
         minusArray((*res).input_num,(*num1).input_num,(*num2).input_num);
      }
      else{
         minusArray((*res).input_num,(*num2).input_num,(*num1).input_num);
         int len=strlen((*res).input_num);
         (*res).input_num[len]='-';
      }
 }
 else if((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]=='-'){
      (*num2).input_num[len2-1]=0;
      addArray((*res).input_num,(*num1).input_num,(*num2).input_num);
 }
 else if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]!='-'){
      (*num1).input_num[len1-1]=0;
      addArray((*res).input_num,(*num1).input_num,(*num2).input_num);
      int len=strlen((*res).input_num);
      (*res).input_num[len]='-';
 }
 else if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]=='-'){
            (*num2).input_num[len2-1]=0;
            (*num1).input_num[len1-1]=0;
         if(compareArray((*num1).input_num,(*num2).input_num)>0){
            minusArray((*res).input_num,(*num1).input_num,(*num2).input_num);
            int len=strlen((*res).input_num);
            (*res).input_num[len]='-';
         }
         else{
            minusArray((*res).input_num,(*num2).input_num,(*num1).input_num);
         }
 }
}
void mulArrays(char res[],char input1[],char input2[]){//默认都为正数。
   int len1=strlen(input1);
   int len2=strlen(input2);
   int len=len1+len2;
   for(int i=0;i<len1;i++){      
            for(int j=0;j<len2;j++){
                res[i+j]+=(input1[i]-'0')*(input2[j]-'0');
                if(res[i+j]>9){
                    res[i+j+1]+=res[i+j]/10;
                    res[i+j]=res[i+j]%10;
                }
            }
    }
    for(int i=0;i<len;i++){
        res[i]+='0';
    }
    int first=strlen(res)-1;
    while(first>0){
      if (res[first]=='0')
      {
          res[first]=0;
          first--;
      }
      else{
         break;
      }    
    }

}
void mulNum(Num* res,Num* num1,Num* num2){ 
    int len1=strlen((*num1).input_num);
    int len2=strlen((*num2).input_num);
    (*res).scale=(*num1).scale+(*num2).scale;
    if((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]!='-'){
      mulArrays((*res).input_num,(*num1).input_num,(*num2).input_num);
    }
    else if ((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]=='-'){
      (*num2).input_num[len2-1]=0;
      mulArrays((*res).input_num,(*num1).input_num,(*num2).input_num);
      int len=strlen((*res).input_num);
      (*res).input_num[len]='-';
    }
    else if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]!='-'){
      (*num1).input_num[len1-1]=0;
      mulArrays((*res).input_num,(*num1).input_num,(*num2).input_num);
      int len=strlen((*res).input_num);
      (*res).input_num[len]='-';
    }
    else{
      (*num1).input_num[len1-1]=0;
      (*num2).input_num[len2-1]=0;
      mulArrays((*res).input_num,(*num1).input_num,(*num2).input_num);
    }
}
void moveArrayLeftOneBit(char input[]){
   int len=strlen(input);
   for(int i=0;i<len;i++){
      input[i]=input[i+1];
   }
   input[len-1]=0;

}
void divideArrays(char res[],char input1[], char input2[],int scale){//scale用于储存目标小数精度,input1是被除数，input2是除数,temp储存目前的小数位数。
      if(scale!=0){
         moveArrayRight(input1,1);
      }
      int len1=strlen(input1);
      int len2=strlen(input2);
      char temp[len2]={0};//用于截取这段区间来和被除数比较大小。
      for(int i=len1-len2;i>=0;i--){
              memset(temp,0,sizeof(temp)); //清零
              if(i!=len1-len2&&input1[i+len2]>'0'){
               input1[i+len2-1]+=(input1[i+len2]-'0')*10;
               input1[i+len2]='0';
              }
              strncpy(temp,input1+i,len2);
              temp[len2]=0;
              while(compareArray(temp,input2)>=0){
               minusArray(temp,temp,input2);
               for(int j=0;j<len2;j++){
                  input1[j+i]=temp[j];
               }
               res[i]++;
               memset(temp,0,sizeof(temp));
               strncpy(temp,input1+i,len2);
               temp[len2]=0;
             }
          }
          if(scale!=0){
            int temp1=res[0];
            if(res[0]>=5){
             res[1]++;
            }
            for(int i=1;i<max(len1-len2,0);i++){
              if(res[i]>=10){
               res[i+1]=res[i+1]+res[i]/10;
               res[i]=res[i]%10;
              }
            }
          for(int i=0;i<max(len1-len2+1,0);i++){
            res[i]=res[i]+'0';
          }
          moveArrayLeftOneBit(res);
          }
          else{
            for(int i=max(len1-len2,0);i>=0;i--){
             res[i]=res[i]+'0';
            }
          }
          int first=strlen(res)-1;
          while(first>0){
            if(res[first]=='0'){
               res[first]=0;
               first--;
            }
            else{
               break;
            }
          }   
}
void divNum(Num* res,Num* num1,Num* num2){
    int scale=min((*num1).scale,(*num2).scale);
    (*res).scale=scale;
    moveArrayRight((*num1).input_num,(*num1).scale-(*num2).scale-scale);
    int len1=strlen((*num1).input_num);
    int len2=strlen((*num2).input_num);
    if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]=='-'){
      (*num1).input_num[len1-1]=0;
      (*num2).input_num[len2-1]=0;
      divideArrays((*res).input_num,(*num1).input_num,(*num2).input_num,scale);
    }
    else if((*num1).input_num[len1-1]!='-'&&(*num2).input_num[len2-1]=='-'){
      (*num2).input_num[len2-1]=0;
      divideArrays((*res).input_num,(*num1).input_num,(*num2).input_num,scale);
      int len=strlen((*res).input_num);
      (*res).input_num[len]='-';
    }
    else if((*num1).input_num[len1-1]=='-'&&(*num2).input_num[len2-1]!='-'){
      (*num1).input_num[len1-1]=0;
       divideArrays((*res).input_num,(*num1).input_num,(*num2).input_num,scale);
       int len=strlen((*res).input_num);
       (*res).input_num[len]='-';
    }
    else{
       divideArrays((*res).input_num,(*num1).input_num,(*num2).input_num,scale);
    }
  
}
void popOperandStack(OperandStack* operand_stack){
   (*operand_stack).top--;
}
void popOperatorStack(OperatorStack* operator_stack){
   (*operator_stack).top--;
}
Num* topOperandStack(OperandStack* operand_stack){
    return &(*operand_stack).operand_stack[(*operand_stack).top];
}
char topOperatorStack(OperatorStack* operator_stack){
   char res=(*operator_stack).operator_stack[(*operator_stack).top];
   return res;
}
void showNum(Num* num){
  int len=strlen((*num).input_num);
  int exponent=(*num).scale;
  if(len==1&&(*num).input_num[0]=='0'&&exponent==0){
   cout<<"0"<<endl;
  }
  bool whether_first=false;
    int have_exponent=-1;
    for(int i=len-1;i>=0;i--){
        if(!whether_first&&(*num).input_num[i]!='0'){
            whether_first=true;
            have_exponent=i;
            break;
        }
    }
    if(exponent==0){
        for(int i=have_exponent;i>=0;i--){
            cout<<(*num).input_num[i];
        }
        cout<<""<<endl;
        return;
    }
    if(have_exponent+exponent==0){
        cout<<(*num).input_num[have_exponent]<<".";
        for(int i=have_exponent-1;i>=0;i--){
            cout<<(*num).input_num[i];
        }
    }
    else if(have_exponent+exponent<0){
            cout<<"0.";
            for(int i=have_exponent+exponent+1;i<0;i++){
                cout<<"0";
            }
            for(int i=have_exponent;i>=0;i--){
                cout<<(*num).input_num[i];
            }
    }
    else{
           if(exponent>=0){
            for(int i=have_exponent;i>=0;i--){
                cout<<(*num).input_num[i];
            }
            for(int i=0;i<exponent;i++){
                cout<<"0";
            }
           }
           else{
             for(int i=have_exponent;i>=0;i--){
                cout<<(*num).input_num[i];
                if(i+exponent==0){
                    cout<<".";
                }
             }
           }
    }
    cout<<""<<endl;
}
