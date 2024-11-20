#pragma once
#include "Stack.h"


class CorrectChecker{
private:
    Stack<int> _brackets;//индексы открывающихся


public:
    bool CheckBrackets(const std::string& s);





};