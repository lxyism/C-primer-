#include<iostream>
using namespace std;
int main(){
    unsigned int voewlCnt = 0;
    char ch;
    cout<<"������һ���ı���"<<endl;
    while(cin>>ch)
    {
        if (ch == 'a')
            ++voewlCnt;
        if (ch == 'e')
            ++voewlCnt;
        if (ch == 'i')
            ++voewlCnt;
        if (ch == 'o')
            ++voewlCnt;
        if (ch == 'u')
            ++voewlCnt;
    }
    cout<<"��������ı�����"<<voewlCnt<<"��Ԫ����ĸ"<<endl;
    system("pause");
    return 0;
}
