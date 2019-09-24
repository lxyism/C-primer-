class Sales_Data{
public:
    Sales_Data& operator=(const string &isbn);

};
Sales_Data& Sales_Data::operator=(const string &isbn)
{
    bookNo = isbn;
    return *this;
}