#include<iostream>
using namespace std;
int main()
{
    unsigned int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
    char ch;
    cout<<"������һ���ı���"<<endl;
    while(cin >> ch)
    {
        switch(ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;    
        }
    }
    cout<<"Ԫ����ĸa�������ǣ�"<<aCnt<<endl;
    cout<<"Ԫ����ĸe�������ǣ�"<<eCnt<<endl;
    cout<<"Ԫ����ĸi�������ǣ�"<<iCnt<<endl;
    cout<<"Ԫ����ĸo�������ǣ�"<<oCnt<<endl;
    cout<<"Ԫ����ĸu�������ǣ�"<<uCnt<<endl;
    system("pause");
    return 0;
}