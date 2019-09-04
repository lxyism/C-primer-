#include<iostream>
#include<vector>

using namespace std;
//int main()
// {
//     vector<int> vi = {0,1,2,3,4,5,5,6,7,8,9};
//     auto iter = vi.begin();
//     string tmp;
//     while (iter != vi.end()){
//         if(*iter % 2)
//             iter = vi.insert(iter, *iter);
//         ++iter;
//         for (auto begin = vi.begin();begin != vi.end(); begin++)
//             cout<<*begin<<" ";
//         cout<<endl;
//         cin>>tmp;
//     }
//     return 0;
// }
int main()
{
    vector<int> ivec;
    cout<<"size:"<<ivec.size()<<endl;
    cout<<"capacity:"<<ivec.capacity()<<endl;
    for (vector<int>::size_type ix=0;ix != 24;++ix)
        ivec.push_back(ix);
    cout<<"size:"<<ivec.size()<<endl;
    cout<<"capacity:"<<ivec.capacity()<<endl;
    system("pause");
    return 0;
}