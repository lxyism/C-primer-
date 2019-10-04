#include<iostream>
#include<string>

using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string book, double sales_price) : bookNo(book), price(sales_price) { }
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const {return n*price;}
    virtual ~Quote() = default; 
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string &book="", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) : Quote(book, sales_price), quantity(qty), discount(disc) { }
    double net_price(size_t cnt) const = 0;     //将net_price定义为纯虚函数
protected:
    size_t quantity;
    double discount;
};

class Bulk_quote: public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book="", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) : Disc_quote(book, sales_price, qty, disc) { }
    double net_price(size_t cnt) const {
        if(cnt > quantity)
            return cnt*(1-discount) * price;
        else
        {
            return cnt * price; 
        }
        
    }
};

class Limited_quote:public Disc_quote{
public:
    // Limited_quote() = default;
    Limited_quote(const string &book="", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):Disc_quote(book, sales_price, quantity, disc_rate) { }
    double net_price(size_t cnt) const {
        if(cnt <= quantity)
            return cnt*(1.0-discount)* price;
        else 
            return quantity*(1.0-discount)*price+(cnt - quantity)*price;
    }
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    //根据传入item形参的对象类型调用Quote::net_price
    //或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}

int main()
{
    
    Quote qt = {"155788", 158.50};
    Bulk_quote bqt = {"155799", 50.0, 10, 0.2};
    Limited_quote lqt = {"155800", 18.5, 50, 0.4};
    print_total(cout, qt, 30);
    print_total(cout, bqt, 50);
    print_total(cout, lqt, 51);
    system("pause");
    return 0;
}