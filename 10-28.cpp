#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    list<int> ls1,ls2,ls3;
    copy(vi.begin(), vi.end(), front_inserter(ls1));
    copy(vi.begin(), vi.end(), inserter(ls2, ls2.begin()));
    copy(vi.begin(), vi.end(), back_inserter(ls3));

    cout<<"ls1:"<<endl;
    for (auto iter=ls1.begin();iter != ls1.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    cout<<"ls2:"<<endl;
    for (auto iter=ls2.begin();iter != ls2.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    cout<<"ls3:"<<endl;
    for (auto iter=ls3.begin();iter != ls3.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;

    system("pause");
    return 0;
}
