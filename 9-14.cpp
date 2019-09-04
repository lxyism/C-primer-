#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    list<char *> slist = {"hello", "world", "!"};
    vector<string> svec;
    //容器类型不同，不能直接赋值，因为char * 和string相容，可以采用范围赋值
    svec.assign(slist.begin(), slist.end());
    cout<<svec.capacity()<<" "<<svec.size()<<" "<<svec[0]<<" "<<svec[svec.size() - 1]<<endl;
    system("pause");
    return 0;
}