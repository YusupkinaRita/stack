#include <iostream>
#include "Stack.h"
#include "CorrectChecker.h"
#include "Table.h"
#include "Formula.h"
#include <optional>
#include <cmath> 

std::optional<std::string> create(bool b){
    if (b)
        return "Godzilla";
    return std::nullopt;
    }

int main(){

    // Stack<int> x=Stack<int>(5);
    // //std::cout<<x<<std::endl;
    // std::cout<<"стек пуст? "<<(x.IsEmpty()?"верно":"ложь")<<std::endl;
    
    // for(int i=1;i<8;i++)
    //     x.Push(i);
    // std::cout<<x<<std::endl;
    // std::cout<<"stack size "<<x.GetLength()<<std::endl;
    // std::cout<<"стек полон? "<<(x.IsFull()?"верно":"ложь")<<std::endl;
    // try{
    //     for(int i=0;i<6;i++)
    //         x.Pop();
    // }
    // catch(const char* error_message){
    //     std::cout<< error_message<<std::endl;
    // }


    std::string sin_str="a+b";
    CorrectChecker check=CorrectChecker();
    CorrectChecker check_sin=CorrectChecker();
    check_sin.FillVariable();
    bool sinx=check.CheckFormula(sin_str);
    std::cout<<"is sin formula correct? "<<(sinx? "yes": "no")<<std::endl;
    Formula fsin(sin_str);
    double res_sin =sin(fsin.Calculate(check_sin.GetVarTable()));


    std::string str="s+1";
    //check.FillVariable();
    check.AppendVarTable("s", res_sin);
    std::cout<<check.GetVarTable()<<std::endl;
    bool x=check.CheckFormula(str);
    std::cout<<"is formula correct? "<<(x? "yes": "no")<<std::endl;
    if(x){
        Formula f(str);
        double res =f.Calculate(check.GetVarTable());
        std::cout<<"answer: "<<res<<std::endl;
    }
    
    //double res =f.Calculate(check.GetVarTable());
    
    
    //std::cout<<"answer: "<<res<<std::endl;
    
    //std::cout<<"correct? "<<"\n"<<(check.CheckBrackets(s)? "yes":"no")<<std::endl;;
    
    


                          

    return 0;
}