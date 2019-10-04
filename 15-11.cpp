#include<iostream>
#include<string>
using namespace std;
class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price){ }
    std::string isbn() const { return bookNo;}
    //���ظ����������鼮�������ܶ�������д��ʹ�ò�ͬ���ۿۼ��㷽��
    virtual double net_price(std::size_t n) const {return n*price;}
    virtual ~Quote() = default;     //�������������ж�̬��
    virtual void debug()
    {
        cout<<"bookNo: "<<bookNo<<" price: "<<price<<endl;
    }
private:
    std::string bookNo;     //�鼮��ISBN���
protected:
    double price = 0.0;     //������ͨ״̬�²����۵ļ۸�

};

class Bulk_quote : public Quote{
public:
    // Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc): Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(size_t cnt) const override
    {
        if(cnt <= min_qty)
            return cnt*(1 - discount )* price;
        else 
            return min_qty*(1 - discount )* price + (cnt - min_qty)* price;
    }
    virtual void debug() 
    {
       Quote::debug();
       cout<<"minqty: "<<min_qty<<" discount: "<<discount<<endl;
    }
private:
    size_t min_qty ;
    double discount ;
    // double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    //���ݴ���item�βεĶ������͵���Quote::net_price
    //����Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}


int main()
{
    
    Quote qt = {"155788", 158.50};
    Bulk_quote bqt = {"155799", 50.0, 10, 0.2};
    print_total(cout, qt, 30);
    print_total(cout, bqt, 50);
    qt.debug();
    bqt.debug();
    system("pause");
    return 0;
}