#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include<iostream>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

//提起声明，StrBlob中的友类声明所需
class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加和删除元素
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    //元素访问
    string& front();
    const string& front() const;
    string&
}