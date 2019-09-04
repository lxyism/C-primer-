//使用while循环实现两个vector对象的逐元素比较
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1 = {0,1,1,2};
    vector<int> v2 = {0,1,1,2,3,5,8};
    vector<int> v3 = {3,5,8};
    vector<int> v4 = {3,5,0,9,2,7};

    auto it1 = v1.cbegin();//定义迭代器
    auto it2 = v2.cbegin();
    auto it3 = v3.cbegin();
    auto it4 = v4.cbegin();

    while(it1 != v1.cend() && it2 != v2.cend())
    {
        //如果当前位置都不相等，肯定没有前缀关系
        if(*it1 != *it2)
        {
            cout<<"v1与v2没有关系。"<<endl;
            break;
        }
        ++it1;
        ++it2;
    }
    if(it1 == v1.cend())
        {
            cout<<"v1是v2的前缀！"<<endl;
        }
    if( it2 == v2.cend()){
        cout<<"v2是v1的前缀"<<endl;
    }
    system("pause");
    return 0;
}