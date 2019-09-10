#include<iostream>
#include<string>

using namespace std;
class Employee{
private:
    static int sn;
public:
    Employee () {mysn = sn++;cout<<"使用了默认构造函数"<<endl;}
    Employee (const string &s) {name = s; mysn = sn++;cout<<"构造函数初始化列表"<<endl;}
    //定义拷贝构造函数和拷贝赋值运算符
    Employee (Employee &e) {name = e.name; mysn = sn++;cout<<"使用了拷贝构造函数"<<endl;}
    Employee& operator=(Employee &rhs) {name = rhs.name; return *this;}
    const string &get_name() {return name;}
    int get_mysn() { return mysn;}
private:
    string name;
    int mysn;
};
int Employee::sn = 0;
void f(Employee &s)
{
    
    cout<<s.get_name()<<":"<<s.get_mysn()<<endl;
}

int main(int argc, char **argv)
{
    Employee a("赵"), b=a, c;
    c = b;
    // Employee a("赵");
    // Employee b("赵");
    // Employee c("赵");
    f(a);f(b);f(c);

    return 0;
}