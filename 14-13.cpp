#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Sales_data{
friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
firend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
public:
    Sales_data& operator-=(const Sales_data &rhs);
    Sales_data& operator+=(const Sales_data &rhs);
    //其他成员
private:
    std::string bookNo;      // implicitly initialized to the empty string
    unsigned units_sold = 0; // explicitly initialized
    double revenue = 0.0;
};

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub =lhs;
    sub -= rhs;
    return sub;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub =lhs;
    sub += rhs;
    return sub;
}

Sales_data Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}
Sales_data Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}