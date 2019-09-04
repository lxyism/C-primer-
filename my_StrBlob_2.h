#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include<iostream>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

//����������StrBlob�е�������������
class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //��Ӻ�ɾ��Ԫ��
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    //Ԫ�ط���
    string& front();
    const string& front() const;
    string&
}