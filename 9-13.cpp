#include<iostream>
#include<vector>
#include<list>

using namespace std;
int main()
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec = {7, 6, 5, 4, 3, 2, 1};  //容器类型不同的时候，不能使用拷贝初始化,因为元素类型相同，可以采用范围初始化
    vector<double> dvec(ilist.begin(), ilist.end());
    vector<double> dvec1(ivec.begin(), ivec.end());
    cout<<dvec.capacity() <<" "<<dvec.size()<<" "<<dvec[0]<<" "<<dvec[dvec.size()-1]<<endl;
    cout<<dvec1.capacity() <<" "<<dvec1.size()<<" "<<dvec1[0]<<" "<<dvec1[dvec1.size()-1]<<endl;
    system("pause");
    return 0;
}