#include <iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    list<int> li = {0,1,2,3,4,5,0,6};
    auto last_z = find(li.rbegin(), li.rend(), 0);
    last_z++;
    int p=1;
    for (auto iter=li.begin(); iter != last_z.base();iter++,p++)
        ;
    if(p >= li.size())
        cout<<"������û��0"<<endl;
    else
        cout<<"���һ��0�ڵ�"<<p<<"��λ��"<<endl;
    system("pause");
    return 0;
}