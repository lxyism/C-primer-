#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class StrLenIs{
public:
    StrLenIs(int len) :len(len) {}
    bool operator()(const string &str) {return str.length() == len;}
private:
    int len;
};

void readStr(istream &is, vector<string> &vec)
{
    string word;
    while(is >> word)
        vec.push_back(word);
}

class StrLenBetween{
public:
    StrLenBetween(int minLen, int maxLen) : minLen(minLen), maxLen(maxLen) {}
    bool operator()(const string &str)
    {
        return str.length() >= minLen && str.length() <= maxLen;
    }
priavte:
    int minLen;
    int maxLen;
};

class StrNotShorterThan{
public:
    StrNotShorterThan(int len):minLen(len) {}
    bool operator()(const string &str) {return str.length() >= minLen;}
private:
    int minLen;
};

extern readStr(istream &is, vector<string> &vec);
int main()
{
    vector<string> vec;
    readStr(cin, vec);

    StrLenBetween sLenBetween(1, 9);
    StrNotShorterThan sNotShorterThan(10);
    cout<<"len 1~9:"<<count_if(vec.begin(), vec.end(), sLenBetween) <<endl;
    cout<<"len >= 10:"<<count_if(vec.begin(), vec.end(), sNotShorterThan)<<endl;
    return 0;
}

// int main()
// {
//     vector<string> vec;
//     readStr(cin, vec);
//     const int minLen = 1;
//     const int maxLen = 10;
//     for(int i = minLen; i<= maxLen; i++)
//     {
//         StrLenIs slenIs(i);
//         cout<<"len:"<<i<<",cnt:"<<count_if(vec.begin(), vec.end(), slenIs)<<endl;
//     }
//     return 0;
// }