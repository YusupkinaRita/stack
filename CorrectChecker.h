#pragma once
#include "Stack.h"
#include "Table.h"

class CorrectChecker{
private:
    Stack<int> _brackets;//индексы открывающихся
    Table<int, int> _bracketsTable;
    Table<std::string, double> _varTable;
    bool _state=false;


public:
    CorrectChecker();//+
    bool CheckBrackets(const std::string& s);//+
    bool CheckVariable();//+
    void FillVariable();//+
    bool CheckFormula(const std::string& s);//+
    bool GetState();//+
    const Table<std::string, double>& GetVarTable() const;//+
    void AppendVarTable(std::string s, double d);





};