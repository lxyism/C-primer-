//ʹ��ί�й��캯�����±�дSales_data�ࡣ
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
    public: //ί�й��캯��
        Sales_data(const string &book, unsigned num, double sellp, double salep)
        :bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
        {
            if (sellingprice)
                discount = saleprice / sellingprice;
            cout<<"gai���캯��������š����ۼۡ�ԭ�ۡ�ʵ���ۼ�4����Ϣ"<<endl;
        }
        Sales_data() : Sales_data("", 0, 0, 0)
        {
        cout<<"�ù��캯����������κ���Ϣ"<<endl;
        }
        Sales_data(const string &book): Sales_data(book, 0, 0, 0)
        {
            cout<<"�ù��캯�����������Ϣ"<<endl;
        }
        Sales_data(std::istream &is) : Sales_data()
        {
            read(is, *this);
            cout<<"gai���캯�������û��������Ϣ"<<endl;
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