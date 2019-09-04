#include<iostream>
#include<string>
using namespace std;

class Person{
private:
    string strName;
    string strAddress;
public:
    friend std::istream &read(std::istream &is, Person &per);
    Person() = default;
    Person(const string &name, const string &add)
    {
        strName = name;
        strAddress = add;
    }
    Person(std::istream &is) {is >> *this;}
public:
    string getName() const {return strName;}  //返回姓名
    string getAddress() const {return strAddress;} //返回地址  
};

std::istream &read(std::istream &is, Person &per)
{
    is>> per.strName >>per.strAddress;
    return is;
}

std::ostream &print(std::ostream &os, const Person &per)
{
    os <<per.getName()<<per.getAddress();
    return os;
}