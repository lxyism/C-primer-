//本程序练习如何让一个类“行为像值”
#include<iostream>
#include<string>

using namespace std;
class HasPtr{
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) { cout<<"默认构造函数"<<endl;}
    HasPtr(const HasPtr &p): ps(new string(*p.ps)), i(p.i) { cout<<"拷贝构造函数"<<endl; } //拷贝构造函数
    HasPtr& operator=(const HasPtr&);       //拷贝赋值运算符
    HasPtr& operator=(const string&);       //赋予新string
    string& operator*();                    //解引用
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps;          //释放string内存
}

inline
HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}
string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char **argv)
{
    HasPtr h("hi mom!");  //使用默认构造函数
    HasPtr h2(h);       //行为类值，h2、h3和h指向不同string
    HasPtr h3 = h;
    cout<<"h: "<<*h<<endl;
    cout<<"h2: "<<*h2<<endl;
    cout<<"h3: "<<*h3<<endl;
    return 0;
}