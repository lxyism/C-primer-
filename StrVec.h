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
    StrVec(const  StrVec&);                             //�������캯��
    StrVec &operator=(const StrVec&);       //������ֵ�����
    ~StrVec();                                                  //��������
    void push_back(const std::string&);        //����Ԫ��
    size_t size() const  { return first_free - elements;}
    size_t capacity() const { return cap - elements;}
    std::string *begin() const { return elements;}
    std::string *end() const { return first_free;}
private:
    static std::allocator<std:string> alloc;    //����Ԫ��
     //�����Ԫ�صĺ�����ʹ��
    void chk_n_alloc()
    {
        if (size() == capacity()) //��size=capacityʱ��ʹ��reallocate�����������·���ռ�
            reallocate();
    }
    //���ߺ��������������캯������ֵ�����������������ʹ��
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();    //����Ԫ�ز��ͷ��ڴ�
    void reallocate();    //��ø����ڴ沢��������Ԫ��
    std::string *elements;      //ָ��������Ԫ�ص�ָ��
    std::string *frist_free;        //ָ�������һ������Ԫ�ص�ָ��
    std::string *cap;       //ָ������β��λ�õ�ָ��
};

void StrVec::push_back(const string& s)
{
    chk_n_alloc();      ////ȷ���пռ�������Ԫ��
    //��first_freeָ���Ԫ���й���s�ĸ���
    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    //����ռ䱣�������Χ�е�Ԫ��
    auto data = alloc.allocate(e - b);
    //��ʼ��������һ��pair����pair��data��uninitialized_copy�ķ���ֵ����
    return  { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    //���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ0������ʲôҲ����
    if(elements)
    {
        //�������پ�Ԫ��
        for(auto p = first_free; p != elements; )
            alloc.destory(--p);  //�ú���������string�����������������������ͷŵ�string�Լ�������ڴ�ռ�
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    //����alloc_n_copy����ռ���������s��һ�����Ԫ��
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free =cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    //����alloc_n_copy�����ڴ棬��С��rhs��Ԫ��ռ�ÿռ�һ����
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline void StrVec::reallocate(size_t newcapacity)
{
    //�������ڴ�
    auto newdata = alloc.allocate(newcapacity);
    //�����ݴӾ��ڴ��ƶ������ڴ�
    auto dest = newdata;     //ָ������������һ������λ��
    auto elem = elements;   //ָ�����������һ��Ԫ��
    for(size_t i = 0; i !=size(); i++)
        alloc.construct(dest++, std::move(*elem++));        //forѭ������ÿ��Ԫ�أ��������ڴ�ռ���constructһ����ӦԪ�ء���destָ������string���ڴ棬ʹ��elemָ��ԭ�����е�Ԫ�ء��ú��õ������㽫dest����elem���ƽ������������е���һ��Ԫ�ء�
    free();         //һ�������ƶ���Ԫ�ؾ��ͷž��ڴ�ռ�
    //�������ǵ����ݽṹ��ִ����Ԫ��
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
    //����alloc_n_copy�������б�il��Ԫ����Ŀһ����Ŀռ�
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elementes = newdata.first;
    first_free = cap = newdata.second;
}
#endif