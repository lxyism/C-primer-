//ΪSales_data��д���ص����롢������ӷ��͸��ϸ�ֵ�����������
class Sales_data
{
friend std::istream& operator>>(std::istream&, Sales_data &);
friend std::ostream& operator<<(std::ostream&, const Sales_data &);

public:
    Sales_data& operator+=(const Sales_data&);
};

Sales_data operator+(const Sales_data&, const Sales_data&);