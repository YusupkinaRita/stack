#include <iostream>
#include "Stack.h"
#include "CorrectChecker.h"


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
    std::string s="(a+b)+(c+(b-d))";
    CorrectChecker check;
    std::cout<<"correct? "<<(check.CheckBrackets(s)? "yes":"no")<<std::endl;;
    


                          

    return 0;
}