#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class Date{
    friend bool operator==(const Date &d1, const Date &d2);
    friend bool operator!=(const Date &d1, const Date &d2);
public:
    Date& operator=(const string &date);
    explicit operator bool()
    {
        vector<vector<int>> days_per_month = {
            {31,28,31,30,31,30,31,31,30,31,30,31},
            {31,29,31,30,31,30,31,31,30,31,30,31}
        };
        return 1 <= month && month <= 12 && 1<= day && day <= days_per_month[isLeapYear() ? 1 : 0][month - 1];
    }
    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
private:
    int year,month,day;
};
bool operator==(const Date &d1, const Date &d2)
{
    return d1.year==d2.year && d1.month==d2.month &&d1.day==d2.day;
}
bool operator!=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}

Date& Date::operator=(const string &date)
{//接受“1970-1-1”形式的日期字符串
    istringstream in(date);
    char ch1, ch2;
    in>>year>>ch1>>month>>ch2>>day;
    if(!in || ch1 !='-' || ch2 !='-')
        throw std::invalid_argument("bad date");
    if(month < 1 || month >12 || day <1 || day >31)
        throw std::invalid_argument("bad date");
    return *this;
}