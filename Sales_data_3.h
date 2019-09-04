#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include <string>
using namespace std;

class Sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
public:
    //构造函数的4种形式
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {}
    Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep);
    Sales_data(std::istream& is) {is>>*this;}
    // Sales_data(std::ostream& os);
    friend std::istream& operator>>(std::istream& in, Sales_data& s);
    friend std::ostream& operator<<(std::ostream& os, const Sales_data &s); 
};

Sales_data::Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep)
{
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (sellingprice != 0)
        discount = saleprice / sellingprice; //计算实际折扣
}

// Sales_data::Sales_data(std::istream& is)
// {
//     is >> *this;
// }

std::istream& 
operator>>(std::istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    // if (in)
    //     s.revenue = s.units_sold * price;
    // else 
    s = Sales_data();  // input failed: reset object to default state
    return in;
}
// Sales_data::Sales_data(std::ostream& os)
// {
//     return *this;
// }
std::ostream& 
operator<<(std::ostream& os, const Sales_data& s)
{	
    os << s.bookNo << " " << s.units_sold << " "<<s.sellingprice<<" "<<s.discount<<" "<<s.saleprice;
        // << s.revenue << " " << s.avg_price();
    return os;
}
#endif