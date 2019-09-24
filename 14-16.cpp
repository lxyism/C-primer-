#include<iostream>
#include<string>
#include<vector>
#include<initializer_list>

using namespace std;

class StrBlob{
friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
//其他成员
public:
    std::string& operator[](std::size_t n) {return data[n];}
    const std::string& operator[](std::size_t n) const
    {return data[n];}
};
bool operator==(const StrBlob &lhs, const StrBlob &rhs){
    return lhs.data == rhs.data; //所指向的vector相等
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs){
    return *lhs.data < *rhs.data; 
bool operator<=(const StrBlob &lhs, const StrBlob &rhs){
    return *lhs.data <= *rhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs){
    return *lhs.data < *rhs.data; 
bool operator>=(const StrBlob &lhs, const StrBlob &rhs){
    return *lhs.data <= *rhs.data;
}


class StrBlobPtr{
friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend StrBlobPtr operator+(int n);
friend StrBlobPtr operator-(int n);
//其他成员
public:
    std::string& operator[](std::size_t n){
        return (*wptr.lock())[n];
    }
    const std::string& operator[](std::size_t n) const
    {return (*wptr.lock())[n];}
    StrBlobPtr& operator++();// 前缀
    StrBlobPtr& operator--();

    StrBlobPtr& operator++(int);//后缀
    StrBlobPtr& operator--(int);

    std::string& operator*() const{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string* operator->() const{
        return &(this->operator*());
    }
};

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    check(curr, "increment past end of StrBlobPtr");
    --curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

StrBlobPtr& StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --(*this);
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(int n)
{
    auto ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n)
{
    auto ret = *this;
    ret.curr -= n;
    return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
    //两个指针都为空，或指向相同的vector且curr指向相同元素时，相等；否则，不等
        return (!r || lhs.curr == rhs.curr);
    else
        return false;   //指向不同的vector时，不等
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        if(!r)
            return false;
        return ( lhs.curr < rhs.curr);
    else
        return false;   
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr <= rhs.curr );
    else
        return false; 
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        if(!r)
            return false;
        return ( lhs.curr > rhs.curr);
    else
        return false;   
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr >= rhs.curr );
    else
        return false; 
}
class MyClass{
    public:
        std::string* operator->() const
        {return ptr->operator->();}
    private:
        StrBlobPtr *ptr;
};
class StrVec{
friend bool operator==(const StrVec &lhs, const StrVec &rhs);
friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
friend bool operator<(const StrVec &lhs, const StrVec &rhs);
friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
friend bool operator>(const StrVec &lhs, const StrVec &rhs);
friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec& operator=(std::initializer_list<std::string> il);
    std::string& operator[](std::size_t n){return elements[n];}
    const std::string& operator[](std::size_t n) const {return elements[n];}
//其他成员
};
StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
bool operator==(const StrVec &lhs, const StrVec &rhs){
    if(lhs.size() != rhs.size())
        return false;
    for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); iter1++, iter2++)
    {
        if(*iter1 != *iter2)
            return false;
    }
    return true;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs){
    return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs){
    for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); iter1++, iter2++)
    {
        if(*iter1 <= *iter2)
            return true;
        else if(*iter1 > *iter2)
            return false;
        if (*iter1 == lhs.end() && *iter2 != rhs.end())
        {
            return true;/* code */
        }
    }
    
    return false;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs){
    for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); iter1++, iter2++)
    {
        if(*iter1 <= *iter2)
            return true;
        else if(*iter1 > *iter2)
            return false;
        if (*iter1 == lhs.end())
            return true;
    }
    return false;
}
bool operator>(const StrVec &lhs, const StrVec &rhs){
    for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); iter1++, iter2++)
    {
        if(*iter1 < *iter2)
            return false;
        else if(*iter1 > *iter2)
            return true;
        if (iter1 == lhs.end() && iter2 != rhs.end())
        {
            return true;/* code */
        }
    }
    
    return false;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs){
    for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); iter1++, iter2++)
    {
        if(*iter1 < *iter2)
            return false;
        else if(*iter1 > *iter2)
            return true;
        if (iter1 == lhs.end())
            return true;
    }
    return false;
}

class String{
friend bool operator==(const String &lhs, const String &rhs);
friend bool operator!=(const String &lhs, const String &rhs);
friend bool operator<(const String &lhs, const String &rhs);
friend bool operator<=(const String &lhs, const String &rhs);
friend bool operator>(const String &lhs, const String &rhs);
friend bool operator>=(const String &lhs, const String &rhs);
public:
    char& operator[](std::size_t n){return (char) str[n];}
    const char& operator[](std::size_t n) const {return (char) str[n];}
//其他成员
private:
    char *str;
    const char *str;
};
bool operator==(const String &lhs, const String &rhs){
    return strcmp(lhs.str, rhs.str);
}
bool operator!=(const String &lhs, const String &rhs){
    return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs){
    return strcmp(lhs.str, rhs.str) <0;
}
bool operator<=(const String &lhs, const String &rhs){
    return strcmp(lhs.str, rhs.str) <=0;
}
bool operator>(const String &lhs, const String &rhs){
    return strcmp(lhs.str, rhs.str) >0;
}
bool operator>=(const String &lhs, const String &rhs){
    return strcmp(lhs.str, rhs.str) >=0;
}