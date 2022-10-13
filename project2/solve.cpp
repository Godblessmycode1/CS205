#include "structure.hpp"
#include <iostream>
#include <map>
#include <set>
using namespace std;
static const map<char, int> priority_table={{'+',0},{'-',0},{'*',1},{'/',1}};
extern  set<string>functions; //平方函数,这里支持二次开发。想自定义函数加到set里。
extern  map<string,char> function_in_stack;//main函数里的函数表于 操作符栈的函数代号对照表。 
set<char>*function_char_in_stack;//function对应的char在stack里储存格式。
bool isValidStack(OperatorStack* operator_stack){
   int temp=(*operator_stack).top;
   for(int i=0;i<=temp;i++){
    if((*operator_stack).operator_stack[i]=='('){
        return false;
    }
   }
   return true;
}
void solve(char operator_input,OperandStack* operand_stack,OperatorStack* operator_stack){
    if(!isEmptyOperatorStack(operator_stack)&&function_char_in_stack->count(operator_input)!=0){ //调用函数的话只需要一个操作数。
        Num* operand;
        Num res;
        if(operator_input=='s'){
            operand=topOperandStack(operand_stack);
            popOperandStack(operand_stack);
            mulNum(&res,operand,operand);
            pushOperandStack(operand_stack,&res);
            popOperatorStack(operator_stack);
        }
        return;
    }
    if ((*operand_stack).top<1) //加减乘除必须至少两位操作数。
    {
       return;
    }
    Num* operand1;
    Num* operand2;
    Num res;
    operand2=topOperandStack(operand_stack); //后一操作数
    popOperandStack(operand_stack);
    operand1=topOperandStack(operand_stack);//前一操作数
    popOperandStack(operand_stack);
    if(operator_input=='+'){  //开始运算。
     addNum(&res,operand1,operand2);
    }
    else if(operator_input=='-'){
    minusNum(&res,operand1,operand2);
    }
    else if(operator_input=='*'){
        mulNum(&res,operand1,operand2);
    }
    else if(operator_input=='/'){
        divNum(&res,operand1,operand2);
    }
    pushOperandStack(operand_stack,&res); //push结果
    popOperatorStack(operator_stack); //把操作符pop掉，已经计算完了。
}
void solveRightBra(OperatorStack* operator_stack,OperandStack* operand_stack){ //遇到右括号是需要计算。到左括号之后还要检验是否为函数。
    while(!isEmptyOperatorStack(operator_stack)&&topOperatorStack(operator_stack)!='('){
        solve(topOperatorStack(operator_stack),operand_stack,operator_stack);
    }
    popOperatorStack(operator_stack); //把左括号pop掉.
    if(!isEmptyOperatorStack(operator_stack)&&function_char_in_stack->count(topOperatorStack(operator_stack))!=0){//判断是否为函数调用。
        solve(topOperatorStack(operator_stack),operand_stack,operator_stack);
    }
}
void checkPriority(OperatorStack* operator_stack,OperandStack* operand_stack,char operator_input){ 
       if(operator_input=='('){
        return;
       }
       while(!isEmptyOperatorStack(operator_stack)&&topOperatorStack(operator_stack)!='('&&priority_table.at(topOperatorStack(operator_stack))>=priority_table.at(operator_input)){
            solve(topOperatorStack(operator_stack),operand_stack,operator_stack);
       }
}
void solveRemain(OperatorStack* operator_stack,OperandStack* operand_stack){
       while(!isEmptyOperatorStack(operator_stack)){
        solve(topOperatorStack(operator_stack),operand_stack,operator_stack);
       }
}