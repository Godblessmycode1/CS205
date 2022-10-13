#include<iostream>
#include<regex>
#include <map>

#include"string.h"
#include <string>
#include<set>
#include "solve.hpp"
using namespace std;
extern bool negative;
extern set<char>* function_char_in_stack;//function对应的char储存在栈里的允许形式集合。

#include"structure.hpp"


regex variableOrNot("[a-z](\\w+)*['=']([-])*[0-9](\\d+)*(.)*([0-9](\\d+)*)*");//这里是正则表达式来判断是否是变量，此程序只支持（小写字母开头后面跟着整数或字母）当做变量名。
regex isAllNumericInteger("([-])*[0-9]([0-9](\\d+)*)*");
regex isAllNumericFloat("([-])*[0-9]([0-9](\\d+)*)*[.][0-9]([0-9](\\d+)*)*");
static set<char>operaters {'+','-','*','/','(',')'}; //operator集合
int main(){
    OperandStack  operand_stack;
    OperatorStack operator_stack;
    map<string,Num> variable_list;//used to stored the variable already input
    cmatch m;
    set<char> tmp{'s'};//function对应的char储存在栈里的允许形式集合。
    function_char_in_stack = &tmp;
    const map<string,char> function_in_stack={{"sqr",'s'}};//因为operator_stack 里只能存char,那么应该有个对应表
    const set<string>functions{"sqr"}; //函数表，储存函数名字
    negative=false;
    char input[200]={0}; // the input length can be changed
    char name[200]={0};//used to store the name of variable
    char value[200]={0};//used to store the value eg:200,0.2,3
    cout<<"Please enter the expressions or variables."<<endl;
    cout<<"Press q to quit"<<endl;
    while(1){
        memset(input,0,sizeof(input));
        memset(name,0,sizeof(name));
        memset(value,0,sizeof(value));
        negative=false;
        int interval_begin=0; //used to split the interval of variable or value.
        int interval_end=0;
        cin.getline(input,200);
        if(strlen(input)==1&&input[0]=='q'){//if the input is q, then quit the program
            break;
        }
        int len=strlen(input);
        if(regex_match(input,m,variableOrNot)){
            Num tempVariable;
            while(input[interval_end]!='='){
                interval_end++;
            }
            strncpy(name,input+interval_begin,interval_end-interval_begin);
            strncpy(value,input+interval_end+1,len-interval_end-1);
            initialNum(&tempVariable,value);
            string name_convert(name);
            variable_list[name_convert]=tempVariable;
        }
        else{
            bool valid=true;
            while(interval_begin<len&&valid){
                memset(name,0,sizeof(name));  //清空之前
                memset(value,0,sizeof(value)); //清空之前
                if(operaters.count(input[interval_begin])==0){//不能是操作符。
                    while(interval_end<len&&operaters.count(input[interval_end])==0){//找到操作符或者到结束
                        interval_end++;
                    }
                    strncpy(name,input+interval_begin,interval_end-interval_begin);
                    if(!regex_match(name,m,isAllNumericInteger)&&!regex_match(name,m,isAllNumericFloat)){ //如果是variable去变量里找,如果是函数去函数set里找。
                        string name_convert(name);
                        if (variable_list.count(name_convert)!=0) //如果变量之前已赋值。
                        {
                           pushOperandStack(&operand_stack,&variable_list[name_convert]);
                           interval_begin++;
                           interval_end=interval_begin;
                        }
                        else{//无这个变量,检查是否为function
                            if(functions.count(name_convert)!=0){
                                pushOperatorStack(&operator_stack,function_in_stack.at(name_convert));
                                interval_begin=interval_end;
                            }
                            else{ //找不到函数，寄了!
                                valid=false;
                                break;
                            }
                        }
                    }
                    else { //证明是浮点数或者整数。
                        strncpy(value,input+interval_begin,interval_end-interval_begin);
                        Num temp;
                        initialNum(&temp,value);
                        pushOperandStack(&operand_stack,&temp);
                        interval_begin=interval_end;
                    }
                }
                else{ //证明是operator '+','-','*','/','(',')'
                    if(input[interval_begin]=='-'&&isEmptyOperandStack(&operand_stack)&&isEmptyOperatorStack(&operator_stack)){
                        negative=true;

                    }
                    else if(input[interval_begin]==')'){
                        solveRightBra(&operator_stack,&operand_stack);
                    }
                    else{
                        checkPriority(&operator_stack,&operand_stack,input[interval_begin]);
                        pushOperatorStack(&operator_stack,input[interval_begin]);
                    }
                    interval_begin++;
                    interval_end=interval_begin;
                }
            }
             valid=valid&&isValidStack(&operator_stack);//括号对不上也是问题入1+(1+3*4 少右括号，判断为错。
            if(valid){
                solveRemain(&operator_stack,&operand_stack);
                showNum(topOperandStack(&operand_stack));
                cout<<"Solve complete!"<<endl;
                variable_list.clear();
            }
            else{
               cout<<"There is an invalid input."<<endl;
               cout<<"The input has been already cleared"<<endl;
               variable_list.clear();
            }
        }
         operand_stack.top=-1;
         operator_stack.top=-1;
    }
    cout<<"Quit already"<<endl;
}