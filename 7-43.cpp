#include<iostream>
#include<string>
using namespace std;

class NoDefault
{
    public:
        NoDefault(int i) {val = i;}
        int val;
};
class C
{
    public:
        NoDefault nd; //������ʽ����Nodefault�Ĵ��ι��캯����ʼ��nd
        C(int i=0) : nd(i) {}
};

int main()
{
    C c;//ʹ��������C��Ĭ�Ϲ��캯��
    cout<<c.nd.val<<endl;
    system("pause");
    return 0;
}
