#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> iv;
    cout<<iv.at(0)<<endl;  //out_of_range
    cout<<iv[0]<<endl;     //ֱ������
    cout<<iv.front()<<endl;///ֱ������
    cout<<*(iv.begin())<<endl;//ֱ������
    system("pause");
    return 0;
}