#include<iostream>
using namespace std;

class Date{
public:
    Date() {}
    Date(int y, int m, int d) {year = y; month =m;day=d;}
    friend ostream& operator<<(ostream &os, const Date &dt);
    friend istream& operator>>(istream &is, Date &dt);
private:
    int year,month,day;
};

ostream& operator<<(ostream& os, const Date& d)
{
    const char sep = '\t';
    os<<"year:"<<d.year<<sep<<"month:"<<d.month<<sep<<"day:"<<d.day<<endl;
    return os;
}

istream& operator>>(istream &is, Date &dt)
{
    is>>dt.year>>dt.month>>dt.day;
    if(!is)
        dt = Date(0, 0, 0);
    return is;
}
class Employee{

public:
    Employee() {}
    Employee(int id,int s,string n, string dm) {id=id; salary=s; name = n; department = dm;}
    friend ostream& operator<<(ostream &os, const Employee &ep);
    friend istream& operator>>(istream &is, Employee &ep);

private:
    int id,salary;
    string name,department;    
};


ostream& operator<<(ostream &os, const Employee& e)
{
    const char sep = '\t';
    os<<"id:"<<e.id<<sep<<"name:"<<e.name<<sep<<"department:"<<e.department<<sep<<"salary:"<<e.salary<<endl;
    return os;
}

istream& operator>>(istream &is, Employee& e)
{
    is>>e.id>>e.name>>e.department>>e.salary;
    if(!is)
        e = Employee();
    return is;
}

class Sales_data{
    friend ostream& operator<<(ostream &os, const Sales_data &item);
};

ostream& operator<<(ostream &os, const Sales_data &item)
{
    const char sep = ' ';
    os<<item.isbn()<<sep<<item.units_sold<<sep<<item.revenue<<sep<<item.avg_price();
    return os;
}