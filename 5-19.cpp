#include<iostream>
#include<cstring>

using namespace std;
int main(){
    string st1,st2;
    do
    {
        cout<<"�����������ַ��������Կո����:"<<endl;
        cin>>st1>>st2;
        if (st1.size() < st2.size())
            cout<<"���Ƚ�С���ַ�Ϊ��"<<st1<<endl;
        else if(st2.size() < st1.size())
        {
            cout<<"���Ƚ�С���ַ�Ϊ��"<<st2<<endl;
        }
        else
            cout<<"���ַ����ȳ�"<<endl;        
        /* code */
    } while (cin);
    system("pause");
    return 0;
    
}