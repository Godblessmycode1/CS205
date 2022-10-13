#pragma once
#include<string>
using namespace std;
struct Num
{
  char input_num[200]={0};
  int scale;   
};
struct OperatorStack
{
    char operator_stack[200]={0};
    int top=-1;
};
struct OperandStack
{
    Num operand_stack[200];
    int top=-1;
};
void moveArrayLeft(char value[]);
void charArrayReverse(char a[]);
void moveArrayRight(char a[],int step);
void initialNum(Num* num,char value[]);
bool isEmptyOperandStack(OperandStack* operand_stack);
bool isEmptyOperatorStack(OperatorStack* operator_stack);
void pushOperandStack(OperandStack* operatand_stack_input,Num* num);
void pushOperatorStack(OperatorStack* operator_stack_input,char operator_input);
void addArray(char res[],char input1[],char input2[]);
void addNum(Num* res,Num* num1,Num* num2);
int compareArrayByteByByte(char input1[],char  input2[]);
int compareArray(char input1[],char input2[]);
void minusArray(char res[],char input1[],char input2[]);
void mulArrays(char res[],char input1[],char input2[]);
void  minusNum(Num* res,Num* num1,Num* num2);
void mulNum(Num*res,Num* num1,Num* num2);
void moveArrayLeftOneBit(char input[]);
void divideArrays(char res[],char input1[], char input2[],int scale);
void divNum(Num* res,Num* num1,Num* num2);
void popOperandStack(OperandStack* operand_stack);
void popOperatorStack(OperatorStack* operator_stack);
Num* topOperandStack(OperandStack* operand_stack);
char topOperatorStack(OperatorStack* operator_stack);
void showNum(Num* num);