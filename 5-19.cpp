#include<iostream>
#include<cstring>

using namespace std;
int main(){
    string st1,st2;
    do
    {
        cout<<"请输入两个字符串，并以空格隔开:"<<endl;
        cin>>st1>>st2;
        if (st1.size() < st2.size())
            cout<<"长度较小的字符为："<<st1<<endl;
        else if(st2.size() < st1.size())
        {
            cout<<"长度较小的字符为："<<st2<<endl;
        }
        else
            cout<<"两字符串等长"<<endl;        
        /* code */
    } while (cin);
    system("pause");
    return 0;
    
}