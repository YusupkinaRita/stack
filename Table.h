#pragma once
#include <iostream>
#include <iomanip>
#include <optional>
#include <cstring>


template<typename T1, typename T2>


class Table{
private:
    std::string _title_col1;
    std::string _title_col2;
    size_t _table_size;
    std::optional<T1>* _col1;
    std::optional<T2>* _col2;
    size_t _count;
    void Expand_table(){
        _table_size=_table_size*2;

        std::optional<T1>* temp_arr=new std::optional<T1>[_table_size];
        std::memcpy(temp_arr, _col1, _count*sizeof(std::optional<T1>));
        delete[] _col1;
        _col1=temp_arr;

        std::optional<T2>* temp_arr2=new std::optional<T2>[_table_size];
        std::memcpy(temp_arr2, _col2, _count*sizeof(std::optional<T2>));
        delete[] _col2;
        _col2=temp_arr2;

    }
public:
    Table(std::string s1="col1", std::string s2="col2",size_t size=20){
        _title_col1=s1;
        _title_col2=s2;
        _table_size=size;
        _col1=new std::optional<T1>[_table_size];
        _col2=new std::optional<T2>[_table_size];
        _count =0;

    }
    void AppendRow(std::optional<T1> elem1, std::optional<T2> elem2){
        if(_count==_table_size) 
            Expand_table();

        _col1[_count]=elem1;
        _col2[_count]=elem2;
        _count++;

    }

    friend std::ostream& operator<<(std::ostream& os, const Table& t){
        os<<"|"<<std::setw(5)<<t._title_col1<<" | "<<std::setw(5)<<t._title_col2<<"|"<<std::endl;
        for (size_t i=0;i<15;i++){
            std::cout<<"-";
        }
        std::cout<<std::endl;
        
        for(size_t i=0; i<t._count;i++){
            if(t._col1[i]==std::nullopt){
                os<<std::setw(5)<<"no";
            }
            else
            os<<std::setw(5)<<t._col1[i].value();
            os<<"|";
            if(t._col2[i]==std::nullopt){
                os<<std::setw(5)<<"no";
            }
            else
            os<<std::setw(5)<<t._col2[i].value();
            std::cout<<std::endl;

        }
         for (size_t i=0;i<15;i++){
            std::cout<<"-";
        }
        return os;
    }
    size_t GetSize()const{
        return _table_size;
    }
    size_t GetCount()const{
        return _count;
    }
    std::optional<T2> operator[]( T1 var){
        for(size_t i=0;i<_table_size;i++){
            if(var==_col1[i]) 
                return _col2[i];
        }
        return 0;
     }
    std::optional<T1>* Get_col1(){
        return _col1;
    }
    std::optional<T2>* Get_col2(){
        return _col2;
    }



    
    

    




    





    //в формуле нужно использовать таблицу приоритетов операций, и нужно(возможно) сделать перегрузку [] для таблицы
};