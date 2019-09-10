#include<iostream>
#include"myStrBlob.h"

using namespace std;
int main(int argc, char **argv)
{
    StrBlob b1;
    {
        StrBlob b2={"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout<<"b2的大小为"<<b2.size()<<endl;
        cout<<"b2的首尾元素为"<<b2.front()<<" "<<b2.back()<<endl;
    }
    cout<<"b1的大小为"<<b1.size()<<endl;
    cout<<"b1的首尾元素为"<<b1.front()<<" "<<b1.back()<<endl;
    StrBlob b3 = b1;
    b3.push_back("next");
    cout<<"b3的大小为"<<b3.size()<<endl;
    cout<<"b3的首尾元素为"<<b3.front()<<" "<<b3.back()<<endl;

    cout<<"b1的全部元素： "<<endl;
    for(auto it=b1.begin(); neq(it, b1.end()); it.incr())
        cout<<it.deref()<<endl;
    return 0;
}