#pragma once
#include <iostream>
#include "Stack.h"
#include "Table.h"


class Formula{
private:
    std::string _expression;
    std::string _postfix;
    Stack <std::string> _calcStack;
    Table <char, int> _prior;

public:
    Formula(const std::string& exp);
    bool CheckFormula();
    void BuildPostfix();
    double Calculate();



};