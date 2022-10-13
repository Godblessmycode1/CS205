#include<iostream>
#include<string>
#include<cmath>
#include<stdio.h>
#include<sstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
bool IntervalAreAllNumerics(char input_num[],int start,int end){
    if(start>end){
        return false;
    }
    bool res=true;
    int temp;
    for(int i=start;i<=end;i++){
       temp=input_num[i];
       if(temp<48||temp>57){
        res=false;
        break;
       }
    }
    return res;
}
bool IsValidIntegerAllNumeric(char input_num[]){
    bool res=true;
    int len=strlen(input_num);
    if(input_num[0]=='-'){
        return IntervalAreAllNumerics(input_num,1,len-1);
    }
    else{
         return IntervalAreAllNumerics(input_num,0,len-1);
    }
}
bool IsValidIntegerExponent(char input_num[]){
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
        if(input_num[i]=='e'){
            if(input_num[0]=='-'){
                if(IntervalAreAllNumerics(input_num,1,i-1)&&IntervalAreAllNumerics(input_num,i+1,len-1)){
                return true;
              }
              else{
                return false;
              }

            }
            else{
                if(IntervalAreAllNumerics(input_num,0,i-1)&&IntervalAreAllNumerics(input_num,i+1,len-1)){
                return true;
              }
              else{
                return false;
              }
            }
        }
    }
    return false;
}
bool IsValidInteger(char input_num[]){
    return IsValidIntegerAllNumeric(input_num)||IsValidIntegerExponent(input_num);
}
bool IsValidFloatAllNumeric(char input_num[]){
    bool res=true;
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
        if(input_num[i]=='.'){
             if(input_num[0]=='-'){
                return IntervalAreAllNumerics(input_num,1,i-1)&&IntervalAreAllNumerics(input_num,i+1,len-1);
             }
             else{
                return IntervalAreAllNumerics(input_num,0,i-1)&&IntervalAreAllNumerics(input_num,i+1,len-1);
             }
             
        }
    }
   return false;
}
bool IsValidFloatExponent(char input_num[]){
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
        if(input_num[i]=='e'){
              char temp[200]={0};
              strncpy(temp,input_num+0,i);
              if(IsValidFloatAllNumeric(temp)){
                if(input_num[i+1]=='-'){
                   return IntervalAreAllNumerics(input_num,i+2,len-1);
                }
                else{
                    return IntervalAreAllNumerics(input_num,i+1,len-1);
                }
              }
              else{
                return false;
              }
        }
    }
    return false;
}
bool IsValidFloat(char input_num[]){
    return IsValidFloatAllNumeric(input_num)||IsValidFloatExponent(input_num);
}
void GetBaseFromExponentInteger(char input_num[],char res[]){
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
         if(input_num[i]=='e'){
            strncpy(res,input_num+0,i);
            break;
         }
    }
}
int AllNumericInteger(char input_num[]){
    int res=0;
    res=strtol(input_num,nullptr,10);
    return res;
}
int GetExponentFromExponentInteger(char input_num[]){
    int len=strlen(input_num);
    int res=0;
    char temp[200]={0};
    for(int i=0;i<len;i++){
         if(input_num[i]=='e'){
            strncpy(temp,input_num+i+1,len-i-1);
            cout<<"temp is:"<<temp<<endl;
            res=AllNumericInteger(temp);
            break;
         }
    }
    return res;
}
int ExponentInteger(char input_num[]){
    int res;
    int base;
    int exponent;
    char integer_part[200]={0};
    char exponent_part[200]={0};
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
          if(input_num[i]=='e'){
            strncpy(integer_part,input_num+0,i);
            strncpy(exponent_part,input_num+i+1,len-i-1);
            base=strtol(integer_part,nullptr,10);
            exponent=strtol(exponent_part,nullptr,10);
            break;
          }
    }
    for(int i=0;i<exponent;i++){
        base=base*10;
    }
    res=base;
    return res; 
}
float ExponentFloat(char input_num[]){
    float res;
    float base;
    int exponent;
    char float_part[200]={0};
    char exponent_part[200]={0};
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
        if(input_num[i]=='e'){
            strncpy(float_part,input_num+0,i);
            base=atof(float_part);
            if(input_num[i+1]=='-'){
               strncpy(exponent_part,input_num+i+2,len-i-2);
                exponent=-strtol(exponent_part,nullptr,10);
            }
            else{
               strncpy(exponent_part,input_num+i+1,len-i-1);
               exponent=strtol(exponent_part,nullptr,10);
            }
            break;
          }
    }
    if(exponent<0){
        for(int i=exponent;i<0;i++){
            base=base/10;
        }
    }
    else{
        for(int i=0;i<exponent;i++){
            base=base*10;
        }
    }
    res=base;
    return res;
}
void  GetBaseFromExponentFloat(char input_num[],char res[]){
    int len=strlen(input_num);
    for(int i=0;i<len;i++){
         if(input_num[i]=='e'){
            strncpy(res,input_num+0,i);
            break;
         }
    }
}
int GetExponentFromExponentFloat(char input_num[]){
    int len=strlen(input_num);
    int res=0;
    char temp[200]={0};
    for(int i=0;i<len;i++){
         if(input_num[i]=='e'){
            strncpy(temp,input_num+i+1,len-1-i);
            res=AllNumericInteger(temp);
            break;
         }
    }
    return res;
}
void CharArrayReverse(char a[]){
    char temp;
    int index=strlen(a);
    for(int i=0;i<index/2;i++){
            temp=a[i];
            a[i]=a[index-i-1];
            a[index-i-1]=temp;
    }
}
int GetExponentFromFloat(char input_num[]){
     int res;
     int len=strlen(input_num);
     for(int i=0;i<len;i++){
        if(input_num[i]=='.'){
              res=-(len-i-1);
              break;
        }
     }
     return res;
}
void MoveFloatArrayLeft(char input_num[]){
     int len=strlen(input_num);
     for(int i=0;i<len;i++){
        if(input_num[i]=='.'){
            for(int j=i;j<len-1;j++){
                input_num[j]=input_num[j+1];
            }
            input_num[len-1]=0;
            break;
        }
     }
}
void MultiplyCharArrays(char a[],char b[],char c []){
    CharArrayReverse(a);
    CharArrayReverse(b);
    int len_a=strlen(a);
    int len_b=strlen(b);
    int len_c=strlen(a)+strlen(b);
    for(int i=0;i<len_a;i++){
        if(a[i]=='-'){
            break;
        }
        else{
            for(int j=0;j<len_b;j++){
                if(b[j]=='-'){
                    break;
                }
                c[i+j]+=(a[i]-'0')*(b[j]-'0');
                if(c[i+j]>9){
                    c[i+j+1]+=c[i+j]/10;
                    c[i+j]=c[i+j]%10;
                }
            }
        }
    }
    for(int i=0;i<len_c;i++){
        c[i]+='0';
    }
}
void ShowResult(char res[],int exponent){
    int len=strlen(res);
    bool whether_first=false;
    int have_exponent=-1;
    for(int i=len-1;i>=0;i--){
        if(!whether_first&&res[i]!='0'){
            whether_first=true;
            have_exponent=i;
            break;
        }
    }
    if(exponent==0){
        for(int i=have_exponent;i>=0;i--){
            cout<<res[i];
        }
        return;
    }
    if(have_exponent+exponent==0){
        cout<<res[have_exponent]<<".";
        for(int i=have_exponent-1;i>=0;i--){
            cout<<res[i];
        }
    }
    else if(have_exponent+exponent<0){
            cout<<"0.";
            for(int i=have_exponent+exponent+1;i<0;i++){
                cout<<"0";
            }
            for(int i=have_exponent;i>=0;i--){
                cout<<res[i];
            }
    }
    else{
           if(exponent>=0){
            for(int i=have_exponent;i>=0;i--){
                cout<<res[i];
            }
            for(int i=0;i<exponent;i++){
                cout<<"0";
            }
           }
           else{
             for(int i=have_exponent;i>=0;i--){
                cout<<res[i];
                if(i+exponent==0){
                    cout<<".";
                }
             }
           }
    }
}
void MultiplyTwoInput(char num1[],char num2[]){
    char num1_base[200]={0};
    char num2_base[200]={0};
    int exponent_all=0;
    char res[400]={0};
    if(IsValidInteger(num1)&&IsValidInteger(num2)){
            if(IsValidIntegerAllNumeric(num1)&&IsValidIntegerAllNumeric(num2)){
                MultiplyCharArrays(num1,num2,res);
            }
            else{
                if(IsValidIntegerExponent(num1)){
                    GetBaseFromExponentInteger(num1,num1_base);
                    exponent_all+=GetExponentFromExponentInteger(num1);
                }
                if(IsValidIntegerExponent(num2)){
                    GetBaseFromExponentInteger(num2,num2_base);
                    exponent_all+=GetExponentFromExponentInteger(num2);
                }
                if(strlen(num1_base)!=0&&strlen(num2_base)!=0){
                    MultiplyCharArrays(num1_base,num2_base,res);
                }
                else if(strlen(num1_base)==0){
                    MultiplyCharArrays(num1,num2_base,res);
                }
                else{
                    MultiplyCharArrays(num1_base,num2,res);
                }
            }
    }
    else if(IsValidFloat(num1)&&IsValidFloat(num2)){
            if(IsValidFloatAllNumeric(num1)&&IsValidFloatAllNumeric(num2)){
                exponent_all+=GetExponentFromFloat(num1);
                exponent_all+=GetExponentFromFloat(num2);
                MoveFloatArrayLeft(num1);
                MoveFloatArrayLeft(num2);
                MultiplyCharArrays(num1,num2,res);
            }
            else if(IsValidFloatAllNumeric(num1)&&IsValidFloatExponent(num2)){
                exponent_all+=GetExponentFromFloat(num1);
                MoveFloatArrayLeft(num1);
                exponent_all+=GetExponentFromExponentFloat(num2);
                GetBaseFromExponentFloat(num2,num2_base);
                exponent_all+=GetExponentFromFloat(num2_base);
                MoveFloatArrayLeft(num2_base);
                MultiplyCharArrays(num1,num2_base,res);
            }
            else if(IsValidFloatExponent(num1)&&IsValidFloatAllNumeric(num2)){
                exponent_all+=GetExponentFromExponentFloat(num1);
                GetBaseFromExponentFloat(num1,num1_base);
                exponent_all+=GetExponentFromFloat(num1_base);
                MoveFloatArrayLeft(num1_base);
                exponent_all+=GetExponentFromFloat(num2);
                MoveFloatArrayLeft(num2);
                MultiplyCharArrays(num1_base,num2,res);
            }
            else{
                exponent_all+=GetExponentFromExponentFloat(num1);
                GetBaseFromExponentFloat(num1,num1_base);
                exponent_all+=GetExponentFromFloat(num1_base);
                MoveFloatArrayLeft(num1_base);
                exponent_all+=GetExponentFromExponentFloat(num2);
                GetBaseFromExponentFloat(num2,num2_base);
                exponent_all+=GetExponentFromFloat(num2);
                MoveFloatArrayLeft(num2_base);
                MultiplyCharArrays(num1_base,num2_base,res);
            }
    }
    else{
        if(IsValidInteger(num1)&&IsValidFloat(num2)){
            if(IsValidIntegerAllNumeric(num1)&&IsValidFloatAllNumeric(num2)){
                exponent_all+=GetExponentFromFloat(num2);
                MoveFloatArrayLeft(num2);
                MultiplyCharArrays(num1,num2,res);
            }
            else if(IsValidIntegerAllNumeric(num1)&&IsValidFloatExponent(num2)){
                 exponent_all+=GetExponentFromExponentFloat(num2);
                 GetBaseFromExponentFloat(num2,num2_base);
                 exponent_all+=GetExponentFromFloat(num2_base);
                 MoveFloatArrayLeft(num2_base);
                 MultiplyCharArrays(num1,num2_base,res);
            }
            else if(IsValidIntegerExponent(num1)&&IsValidFloatExponent(num2)){
                exponent_all+=GetExponentFromExponentInteger(num1);
                GetBaseFromExponentInteger(num1,num1_base);
                exponent_all+=GetExponentFromExponentFloat(num2);
                GetBaseFromExponentFloat(num2,num2_base);
                exponent_all+=GetExponentFromFloat(num2_base);
                MoveFloatArrayLeft(num2_base);
                MultiplyCharArrays(num1_base,num2_base,res);
            }
            else{
                exponent_all+=GetExponentFromExponentInteger(num1);
                GetBaseFromExponentInteger(num1,num1_base);
                exponent_all+=GetExponentFromFloat(num2);
                MoveFloatArrayLeft(num2);
                MultiplyCharArrays(num1_base,num2,res);
             }

        }
        else{
            if(IsValidFloatAllNumeric(num1)&&IsValidIntegerAllNumeric(num2)){
                exponent_all+=GetExponentFromFloat(num1);
                MoveFloatArrayLeft(num1);
                MultiplyCharArrays(num1,num2,res);
            }
            else if(IsValidFloatAllNumeric(num1)&&IsValidIntegerExponent(num2)){
                exponent_all+=GetExponentFromExponentFloat(num1);
                MoveFloatArrayLeft(num1);
                exponent_all+=GetExponentFromExponentInteger(num2);
                GetBaseFromExponentInteger(num2,num2_base);
                MultiplyCharArrays(num1,num2_base,res);
            }
            else if(IsValidFloatExponent(num1)&&IsValidIntegerAllNumeric(num2)){
                exponent_all+=GetExponentFromExponentFloat(num1);
                GetBaseFromExponentFloat(num1,num1_base);
                exponent_all+=GetExponentFromFloat(num1_base);
                MoveFloatArrayLeft(num1_base);
                MultiplyCharArrays(num1_base,num2,res);
            }
            else{
                exponent_all+=GetExponentFromExponentFloat(num1);
                GetBaseFromExponentFloat(num1,num1_base);
                exponent_all+=GetExponentFromFloat(num1_base);
                MoveFloatArrayLeft(num1_base);
                exponent_all+=GetExponentFromExponentInteger(num2);
                GetBaseFromExponentInteger(num2,num2_base);
                MultiplyCharArrays(num1_base,num2_base,res);
            }
        }
    }
    ShowResult(res,exponent_all);
}
int main(int argc,char* argv[]){
    int exponent_all=0;
    bool valid1=IsValidInteger(argv[1])||IsValidFloat(argv[1]);
    bool valid2=IsValidFloat(argv[2])||IsValidInteger(argv[2]);
    if(valid1&&valid2){
            cout<<argv[1];
            cout<<"*";
            cout<<argv[2];
            cout<<"=";
            if((argv[1][0]!='-'&&argv[2][0]=='-')||(argv[1][0]=='-'&&argv[2][0]!='-')){
                cout<<"-";
            }
            MultiplyTwoInput(argv[1],argv[2]);
    }
    else{
        cout<<"The input cannot be interpret as numbers!"<<endl;
    }
}