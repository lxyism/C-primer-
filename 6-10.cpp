#include<iostream>
using namespace std;
void mySWAP(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main()
{
    int a = 5,b = 10;
    int *r = &a,*s = &b;
    cout<<"����ǰ��a= "<<a<<",b= "<<b<<endl;
    mySWAP(r,s);
    cout<<"������a= "<<a<<",b="<<b<<endl;
    system("pause");
    return 0;
}