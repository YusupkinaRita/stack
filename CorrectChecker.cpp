#include "CorrectChecker.h"
#include "Table.h"
#include <optional>


bool CorrectChecker::CheckBrackets (const std::string& s){
    Table<int, int> t1("(", ")");
    for (size_t i = 0; i < s.size(); i++){
        if(s[i]=='(')
            _brackets.Push(i);
        if(s[i]==')'){
            try{
            t1.AppendRow(_brackets.Pop(), i);

            }
            catch(const char* error_message){
                t1.AppendRow(std::nullopt, i);
                std::cout<<"error in brackets "<<i<<std::endl;
                std::cout<<t1<<std::endl;
                return false;
            }
        }  
    }
    std::cout<<std::endl;
    std::cout<<t1<<std::endl;
    return _brackets.IsEmpty();
    

}
