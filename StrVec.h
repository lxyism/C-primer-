#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<initializer_list>

using namespace std;
class StrVec{
friend void reallocate(size_t newcapacity);
friend void resize(size_t b);
friend void resize(size_t n, const std::string &s);
public:
    StrVec(std::initializer_list il) {};
    StrVec:elements(nullptr), frist_free(nullptr), cap(nullptr) {}
    StrVec(const  StrVec&);                             //拷贝构造函数
    StrVec &operator=(const StrVec&);       //拷贝赋值运算符
    ~StrVec();                                                  //析构函数
    void push_back(const std::string&);        //拷贝元素
    size_t size() const  { return first_free - elements;}
    size_t capacity() const { return cap - elements;}
    std::string *begin() const { return elements;}
    std::string *end() const { return first_free;}
private:
    static std::allocator<std:string> alloc;    //分配元素
     //被添加元素的函数所使用
    void chk_n_alloc()
    {
        if (size() == capacity()) //当size=capacity时，使用reallocate函数进行重新分配空间
            reallocate();
    }
    //工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();    //销毁元素并释放内存
    void reallocate();    //获得更多内存并拷贝已有元素
    std::string *elements;      //指向数组首元素的指针
    std::string *frist_free;        //指向数组第一个空闲元素的指针
    std::string *cap;       //指向数组尾后位置的指针
};

void StrVec::push_back(const string& s)
{
    chk_n_alloc();      ////确保有空间容纳新元素
    //在first_free指向的元素中构造s的副本
    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    //分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    //初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
    return  { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    //不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
    if(elements)
    {
        //逆序销毁旧元素
        for(auto p = first_free; p != elements; )
            alloc.destory(--p);  //该函数会销毁string的析构函数，析构函数会释放掉string自己分配的内存空间
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    //调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free =cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    //调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline void StrVec::reallocate(size_t newcapacity)
{
    //分配新内存
    auto newdata = alloc.allocate(newcapacity);
    //将数据从就内存移动到新内存
    auto dest = newdata;     //指向新数组中下一个空闲位置
    auto elem = elements;   //指向旧数组中下一个元素
    for(size_t i = 0; i !=size(); i++)
        alloc.construct(dest++, std::move(*elem++));        //for循环遍历每个元素，并在新内存空间中construct一个对应元素。用dest指向构造新string的内存，使用elem指向原数组中的元素。用后置递增运算将dest（和elem）推进到各自数组中的下一个元素。
    free();         //一旦我们移动完元素就释放旧内存空间
    //更新我们的数据结构，执行新元素
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline void StrVec::resize(size_t n)
{
    if(n > size()){
        while (size()<n)
        push_back("");
    }
    else if(n<size())
    {
        while(size()>n)
        alloc.destory(--first_free);
    }
}

inline void StrVec::resize(size_t n, const std::string &s)
{
    if(n>size()){
        while(size()<n)
            push_back(s);
    }
}

inline StrVec::StrVec(std::initializer_list<std::string> il)
{
    //调用alloc_n_copy分配与列表il中元素数目一样多的空间
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elementes = newdata.first;
    first_free = cap = newdata.second;
}
#endif