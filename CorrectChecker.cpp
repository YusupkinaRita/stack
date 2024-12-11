#include "CorrectChecker.h"
#include "Table.h"
#include <optional>
#include <vector>
#include <string>
#include <cstdlib>

CorrectChecker::CorrectChecker(): _bracketsTable("(", ")", 20), _brackets(), _varTable("var", "val"){
}
bool CorrectChecker::CheckBrackets (const std::string& s){
    int flag=0;
    std::vector<int> error;
    for (size_t i = 0; i < s.size(); i++){
        if(s[i]=='(')
            _brackets.Push(i);
        if(s[i]==')'){
            try{
            _bracketsTable.AppendRow(_brackets.Pop(), i);

            }
            catch(const char* error_message){
                _bracketsTable.AppendRow(std::nullopt, i);
                error.push_back(i);
                flag++;
            }
        }  
    }
    while(!_brackets.IsEmpty()){
        _bracketsTable.AppendRow(_brackets.Pop(), std::nullopt);
    }
    std::cout<<_bracketsTable<<std::endl;
    if(!error.empty())
        std::cout<<"error in brackets ";
    for (size_t i=0; i<error.size();i++)
        std::cout<< error[i]<<" ";
    std::cout<<std::endl;
    if(flag==0)
        return _brackets.IsEmpty();
    else
        return false;
    

}
void CorrectChecker::FillVariable(){
    std::string var;
    std::string var_check="0";
    double val;
    std::string val_check;
    for(size_t i=0;;i++){
        std::cout<<"enter variable no "<<i<<": ";
        std::cin>>var;
        if(var=="-1"){
            std::cout<<_varTable<<std::endl;
            break;
        }
        if(var_check==var){
            std::cout<<"wrong, try again"<<std::endl;
            i--;
            continue;
        }
        var_check=var;
        std::cout<<var<<" = ";
        std::cin>>val_check;
        if(val_check=="no")
            _varTable.AppendRow(var, std::nullopt);
        else{
            val=std::stod(val_check);
            _varTable.AppendRow(var, val);

        }

    }
}

bool CorrectChecker::CheckVariable(){
    for(size_t i=0; i<_varTable.GetCount();i++){
        if( _varTable.Get_col1()[i]==std::nullopt)
            return false;
        if(_varTable.Get_col2()[i]==std::nullopt)
            return false;
    }
    return true;
}

const Table<std::string, double>& CorrectChecker::GetVarTable() const{
    return _varTable;
}


bool CorrectChecker::CheckFormula(const std::string& s){
    if(!CheckBrackets(s)){
        _state=false;
        return false;
    }
    if(!CheckVariable()){
        _state=false;
        return false;
    }
    else{
        for (size_t i = 0; i < _bracketsTable.GetCount(); i++){
            if(_bracketsTable.Get_col2()[i].value()-_bracketsTable.Get_col1()[i].value() <=3){
                _state=false;
                return false;
            }
        }
        std::string operators = "+-*/";
        for (size_t i = 1; i < s.length(); ++i) {
            if (operators.find(s[i]) != std::string::npos && operators.find(s[i - 1]) != std::string::npos) {
                    _state=false;
                    return false; 
            }
        }
        

    }
    return true;
      
    
}
bool CorrectChecker::GetState(){
    return _state;
}
