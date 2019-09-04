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
    friend std::istream& operator>>(std::istream& in, Sales_data& s);
    friend std::ostream& operator<<(std::ostream& out, const Sales_data& s);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    //isbn函数只有一条语句，返回bookNo
	string isbn() const {return bookNo;}
    //combine函数用于把两个ISBN相同的销售记录合并在一起
    Sales_data& combine( const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;  //累加书籍的销售量
        saleprice = (rhs.saleprice * rhs.units_sold +saleprice*units_sold) / (rhs.units_sold + units_sold); //重新计算实际销售价格
        if(sellingprice != 0)
            discount = saleprice/sellingprice; //重新计算实际折扣
        return *this;  //返回合并后的结果
    }   
    Sales_data(std::istream& is) {is>>*this;}
};
std::istream& 
operator>>(std::istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    // if (in)
    //     s.revenue = s.units_sold * price;
    // else 
    // s = Sales_data();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const Sales_data& s)
{	
    out << s.isbn() << " " << s.units_sold << " ";
        // << s.revenue << " " << s.avg_price();
    return out;
}

// Sales_data add(const Sales_data &lhs, const Sales_data &rhs )
// {
//     Sales_data sum = lhs;
//     sum.combine(rhs);
//     return sum;
// }
std::istream &read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >>item.units_sold >>item.sellingprice >>item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os<< item.isbn() <<" "<<item.units_sold<<" "<<item.sellingprice<<" "<<item.saleprice<<" "<<item.discount;
    return os;
}

#endif
