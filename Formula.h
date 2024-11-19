#pragma once
#include <iostream>
#include "Stack.h"


class Formula{
private:
    std::string _expression;
    std::string _postfix;
    Stack <std::string> _calcStack;

public:
    Formula(std::string exp);
    bool CheckBrackets(){
        size_t open_count=0;
        size_t close_count =0;
        if (_expression.find_first_of(')')<_expression.find_first_of('(') )
            return 0;
        for(size_t i=0; i<_expression.length();i++){
            if(_expression[i]=='(')
                open_count++;
            if(_expression[i]==')'){
                close_count++;
                if(close_count<=open_count){
                    open_count--;
                    close_count--;
                }
                else
                return 0;
            }
            if(open_count!=0 && close_count!=0)
                return 0;
            
        }
    }
    bool CheckFormula();
    void EnterVariableValues();//вводим значения переменных если они есть,если есть переменная, но нет значения-ошибка. можно перевести в приват
    std::string BuildPostfix();
    double Calculate();



};