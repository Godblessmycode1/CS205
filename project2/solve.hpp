#pragma once
#include "structure.hpp"
#include <iostream>
#include <map>
#include <set>
bool isValidStack(OperatorStack* operator_stack);
void solve(char operator_input,OperandStack* operand_stack,OperatorStack* operator_stack);
void solveRightBra(OperatorStack* operatorStack,OperandStack* operandStack);
void checkPriority(OperatorStack* operator_stack,OperandStack* operand_stack,char operator_input);
void solveRemain(OperatorStack* operator_stack,OperandStack* operand_stack);