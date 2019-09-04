//使用委托构造函数重新编写Sales_data类。
#include<iostream>
#include<string>
using namespace std;

class Sales_data{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double sellingprice = 0.0;
        double saleprice = 0.0;
        double discount = 0.0;
    public: //委托构造函数
        Sales_data(const string &book, unsigned num, double sellp, double salep)
        :bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
        {
            if (sellingprice)
                discount = saleprice / sellingprice;
            cout<<"gai构造函数接受书号、销售价、原价、实际售价4个信息"<<endl;
        }
        Sales_data() : Sales_data("", 0, 0, 0)
        {
        cout<<"该构造函数无需接受任何信息"<<endl;
        }
        Sales_data(const string &book): Sales_data(book, 0, 0, 0)
        {
            cout<<"该构造函数接受书好信息"<<endl;
        }
        Sales_data(std::istream &is) : Sales_data()
        {
            read(is, *this);
            cout<<"gai构造函数接收用户输入的信息"<<endl;
        }

};

std::istream &read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice>>item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os<< item.bookNo <<" "<<item.units_sold <<" "<<item.sellingprice<<" "<<item.saleprice<<" "<<item.discount;
    return os;
}

int main ()
{   cout<<"first:"<<endl;
    Sales_data fist("978-7-121-15535-2", 85, 128, 109);
    cout<<"second:"<<endl;
    Sales_data second;
    cout<<"third:"<<endl;
    Sales_data third("978-7-121-15535-2");
    cout<<"last:"<<endl;
    Sales_data last(cin);
    system("pause");
    return 0;
}