#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;

map<string, function<int (int, int)>> binOps = {
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
    {"%", modulus<int>()}
};

int main()
{
    int a, b;
    string op;
    cin>>a>>op>>b;
    cout<<binOps[op](a,b)<<endl;
    system("pause");
    return 0;
}
