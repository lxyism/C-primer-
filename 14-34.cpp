#include<vector>
#include<iostream>
#include<string>
using namespace std;

class IfElseThen{
public:
    IfElseThen(){}
    IfElseThen(int i1, int i2, int i3):iVal1(i1), iVal2(i2), iVal3(i3) {}
    int operator()(int i1, int i2, int i3){ return i1 ? i2 : i3;}
private:
    int iVal1, iVal2, iVal3
};
//14-35
class ReadString{
public: 
    ReadString(istream &is = cin): is(is)   {}
    std::string operator()()
    {
        string line;
        if(!getline(is, line))
        {
            line=" ";
        }
        return line;
    }
private:
    istream &is;
};
//14-36
void testReadString()
{
    ReadString rs;
    vector<string> vec;
    while(true)
    {
        string line = rs();
        if(!line.empty())
            vec.push_back(line);
        else
        {
                break;
        }
        
    }

}
//14-37
