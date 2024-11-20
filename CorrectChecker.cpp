#include "CorrectChecker.h"
#include "Table.h"


bool CorrectChecker::CheckBrackets (const std::string& s){
    Table<int, int> t1;
    for (size_t i = 0; i < s.size(); i++){
        if(s[i]=='(')
            _brackets.Push(i);
        if(s[i]==')'){
            try{
            t1.AppendRow(_brackets.Pop(), i);

            }
            catch(const char* error_message){
                std::cout<<"error in brackets"<<std::endl;
                return false;
            }
        }  
    }
    std::cout<<t1<<std::endl;
    return _brackets.IsEmpty();
    //доделать

}
