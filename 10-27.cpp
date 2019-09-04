#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vi ={1,4,2,22,6,5,3,1,4,5,2,5,6};
    auto viter = vi.begin();
    sort(viter,viter+vi.size());
    list<int> li;
    unique_copy(vi.begin(), vi.end(), back_inserter(li));

    for(auto v:li)
        cout<<v<<" ";
    cout<<endl;
    system("pause");
    return 0;
}