#pragma once
#include <iostream>
#include "Stack.h"
#include "Table.h"


class Formula{
private:
    std::string _expression;
    std::string _postfix;
    Stack <char> _calcStack;
    Table <char, int> _prior;

public:
    Formula(const std::string& exp){
        _expression=exp;
        _prior=Table<char, int>("operation", "priority");
        _prior.AppendRow('(',0);
        _prior.AppendRow(')',1);
        _prior.AppendRow('+',2);
        _prior.AppendRow('-',2);
        _prior.AppendRow('*',3);
        _prior.AppendRow('/',3);

    }
    void BuildPostfix(){
        std::string operators = "(+-*/)";
        for(size_t i=0; i<_expression.length();i++){
            if(operators.find(_expression[i])!= std::string::npos){
                if(_prior[_expression[i]].value()==0 || _prior[_expression[i]].value() > _prior[_calcStack.Check()].value() || _calcStack.IsEmpty()){
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                    std::cout<<_calcStack<<std::endl;
                }
                else{
                    while(_prior[_expression[i]].value()<=_prior[_calcStack.Check()].value() && !_calcStack.IsEmpty() ){
                        _postfix.push_back(_calcStack.Pop());
                        if(_calcStack.Check()=='(')
                            _calcStack.Pop();
                        else
                            _postfix.push_back(_calcStack.Pop());

                        std::cout<<_calcStack<<std::endl;
                    }
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                }
            }
            else
                _postfix.push_back(_expression[i]);
        }
        while(!_calcStack.IsEmpty())
            if(_calcStack.Check()!='('&&_calcStack.Check()!=')'){
                _postfix.push_back(_calcStack.Pop());
                std::cout<<_calcStack<<std::endl;
            }
            else{
                _calcStack.Pop();
                std::cout<<_calcStack<<std::endl;
            }
        std::cout<<_postfix;
    }
    double Calculate();



};