#include <iostream>
#include "Stack.h"


int main(){
    Stack<int> x;
    std::cout<<x<<std::endl;
    std::cout<<x.IsEmpty()<<std::endl;
    
    for(int i=1;i<11;i++)
        x.Push(i);
    //std::cout<<x<<std::endl;
    //int b=x.Pop();
    //std::cout<<b<<std::endl;
    //std::cout<<x<<std::endl;
    std::cout<<x<<std::endl;
    std::cout<<x.IsFull()<<std::endl;
    //std::cout<<x<<std::endl;
    


                          

    return 0;
}