# CS205 Project1 Report
11911702 郭一潼<br>
Studentid:11911702

CS205 Project1 Report
<!-- vscode-markdown-toc -->
* 1. [Introduction](#1-a-nameintroductiona-introduction)
  * [Project Description](#11-a-nameproject-descriptionaproject-description)
  * [Development Enviroment](#12-a-namedevelopment-environmenta-development-environment)
* 2. [Analysis](#2a-nameanalysisaanalysis)
  * [Input Protection](#21a-nameinput-protection-input-protection)
   * [Array Multiply Method](#22a-namearray-multiply-method-array-multiply-method)
   * [Overall Multiply Method](#23a-nameoverall-multiply-method-overall-multiply-method)
* 3. [Code](#3a-namecodeacode)
   * [Integer Input Protection](#31a-nameinteger-input-protection-integer-input-protection)
   * [Float Input Protection](#32a-namefloat-input-protection-float-input-protection)
   * [Char Array Multiplication](#33a-namechar-array-multiplication-char-array-multiplication)
   * [Ouput Result](#34a-nameoutput-result-output-result)
* 4.[Result and Verification](#4a-nameresult-and-verificationaresult-and-verification)
* 5.[Difficulties and Solution](#5a-namedifficulties-and-solutionadifficulties-and-solution)
<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Introduction'></a> Introduction
### 1.1 <a name='Project Description'></a>Project Description
This Project designs a calculator for valid input number(including integer/float in valid decimal system or scientific notation form).
<ol>
<li>The calculator should get input throught command line</li>
<li>It can tell that the input is not a number</li>
<li>It can still get the right result although the input is big</li>
</ol>

### 1.2 <a name='Development Environment'></a> Development Environment
<ul>
<li>x86_64
<ul>
<li>vscode (version 1.71)</li>
<li>WSL (version 2)</li>
<li>Ubuntu(22.04)</li>
<li>g++(11.2.0)</li>
</ul>
</li>
</ul>

## 2.<a name='Analysis'></a>Analysis
### 2.1<a name='Input Protection'> Input Protection
The program should tell whether the input is valid or not. <br>Eg: **3.145a1, a.3145, 1.0ea , a.0e10** are not valid input.
<br>By contrast, **3.1415, 2.0e10 , 1e10** are valid input.
<br>**Overall, there are four kinds of valid input:**
<ul>
<li>Valid input
<ul>
<li>1.Each bit of the input is digital number.Eg:114514</li>
<li>2.The bits before and after 'e' are all digital number.Eg:1e10</li>
<li>3.The bits except '.' are all digital number.Eg:3.1415</li>
<li>4.The bits before 'e' fit rule 3 , the bits after 'e' fit rule 1. Eg:2.0e10</li>
</ul>
</li>
</ul>

### 2.2<a name='Array Multiply Method'> Array Multiply Method
Considering there are big number inputs sometimes. Using '*' operator may cause overflow, so we use **char array** to represent the number.
<ul>
<li>Procedure
<ul>
<li>1.Reverse the input number and store it into  char input1 [ ] and char input2 [ ]</li>
<li>2.Using a char res [ ] (res.length=input1.length+input2.length)to store the result</li>
<li>3. For each index i in input1 and for each index j in input2,res[i+j]=input1[i]*input2[j]</li>
<li>4.If res[i+j]>9 then res[i+j+1]+=res[i+j]/10 , res[i+j]=res[i+j]%10.</li>
<li>5.From the higher index of res to lower index of res, if find the first unzero bit, then output all the remaining digital bits.</li>
</ul>
</li>
</ul>
<br>
Eg:Taking 341*61 as example.

![](/example.png)

![](/example1.png)


### 2.3<a name='Overall Multiply Method'> Overall Multiply Method
Considering there exists exponent form integer and float. The exponent **can be added** , so in my program , i use a int variable **exponent_all** to represent the final exponent of the res array and output the result **considering the relationship of exponent_all and the number of un-zero bits of res**.
 <ul>
<li>Procedure
<ul>
<li>1.For exponent integer,we can directly get their exponent(after 'e' part)<br>
Eg:1e10 the exponent is 10.
</li>
<li>2.For all numeric float form, we can get their exponent (after '.' part)<br> Eg:3.1415=31415*10^-4, the exponent is -4</li>
<li>3. For exponent form float, the exponent is added by the previous part of 'e' and the part after 'e'.<br>
Eg:3.1415e10  the exponent of 3.1415 is -4 and that of exponent part is 10, overall the exponent of 3.1415e10 is -4+10=6.</li>
<li>The overall result should consider the relationship of valid un-zero digital bits of res and exponent.<br>
Eg:3.1415*1.0e-1 the exponent_all=31415*10*10^(-4-1-1)
so res is 314150 and exponent is -6 , so the overall result is 0.31415.
</li>
</ul>
</li>
</ul>

## 3.<a name='Code'></a>Code
### 3.1<a name='Integer Input Protection'> Integer Input Protection
```
//It is used to tell whether there is non digital number in the [start,end] interval.
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
```
### 3.2<a name='Float Input Protection'> Float Input Protection
```
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
```
### 3.3<a name='Char Array Multiplication'> Char Array Multiplication
```
//The function below is used to reverse the array for example 12345 should be reversed to 54321 to calculate the right answer.
void CharArrayReverse(char a[]){
    char temp;
    int index=strlen(a);
    for(int i=0;i<index/2;i++){
            temp=a[i];
            a[i]=a[index-i-1];
            a[index-i-1]=temp;
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
```
### 3.4<a name='Output Result'> Output Result
```
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
```
## 4.<a name='Result and Verification'></a>Result and Verification
![](/result1.png)
![](/result2.png)

## 5.<a name='Difficulties and Solution'></a>Difficulties and Solution
1.The first is use which type to get the input.**Considering the big number multiplication later, we try to use char[ ] to represent the number.**<br>
2.The second is input protection.**Its solution is to test whether the input is among four kinds of valid input above**. <br>
3.The third is to find a general solution to all kinds of data like (integer* integer, integer* float, float*float).
**The solution is using an exponent_all variable to get the overall exponent(in 2.3 Overall Multiply Method Part) and output the result according to the relationship of un-zero bits of res and exponent_all.**