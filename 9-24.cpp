#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> iv;
    cout<<iv.at(0)<<endl;  //out_of_range
    cout<<iv[0]<<endl;     //直接跳出
    cout<<iv.front()<<endl;///直接跳出
    cout<<*(iv.begin())<<endl;//直接跳出
    system("pause");
    return 0;
}