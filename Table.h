#pragma once
#include <iostream>


template<typename T1, typename T2>


class Table{
private:
    size_t _table_size;
    T1* _col1;
    T2* _col2;
    size_t _count;
public:
    Table(size_t size=20){
        _table_size=size;
        _col1=new T1[_table_size];
        _col2=new T2[_table_size];
        _count =0;

    }
    void AppendRow(T1 elem1, T2 elem2){//std::optional(variant)прогуглить
        _col1[_count]=elem1;
        _col2[_count]=elem2;
        _count++;

    }//прописать переполнение

    friend std::ostream& operator<<(std::ostream& os, const Table& t){
        for(size_t i=0; i<t._count;i++){
            os<<t._col1[i]<<" | "<<t._col2[i]<<std::endl;
        }
        return os;
    }





    
};