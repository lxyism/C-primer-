#include<iostream>
using namespace std;
int main(){
    unsigned int voewlCnt = 0;
    char ch;
    cout<<"请输入一段文本："<<endl;
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
    cout<<"您输入的文本中有"<<voewlCnt<<"个元音字母"<<endl;
    system("pause");
    return 0;
}
