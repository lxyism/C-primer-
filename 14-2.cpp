//为Sales_data编写重载的输入、输出、加法和复合赋值运算符的声明
class Sales_data
{
friend std::istream& operator>>(std::istream&, Sales_data &);
friend std::ostream& operator<<(std::ostream&, const Sales_data &);

public:
    Sales_data& operator+=(const Sales_data&);
};

Sales_data operator+(const Sales_data&, const Sales_data&);