#include<iostream>
#include<string>

using namespace std;
class Employee{
private:
    static int sn;
public:
    Employee () {mysn = sn++;cout<<"ʹ����Ĭ�Ϲ��캯��"<<endl;}
    Employee (const string &s) {name = s; mysn = sn++;cout<<"���캯����ʼ���б�"<<endl;}
    //���忽�����캯���Ϳ�����ֵ�����
    Employee (Employee &e) {name = e.name; mysn = sn++;cout<<"ʹ���˿������캯��"<<endl;}
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
    Employee a("��"), b=a, c;
    c = b;
    // Employee a("��");
    // Employee b("��");
    // Employee c("��");
    f(a);f(b);f(c);

    return 0;
}