#include<iostream>
#include<cstring>
//#include<vector>

using namespace std;
int main(){
    string st1,st2;
    bool b1 = true;
    //vector<string> st;
    cout<<"������һ���ַ�����"<<endl;
    //auto it = st.cbegin();
    while( cin>>st1 )
    {
        if(st1 == st2)
        {
            b1 = false;
            cout<<"�������ֵ��ַ����ǣ�"<<st1<<endl;
            break;
        }
        //it != st.cend() && *it != *(it+1)
        st2 = st1;
    }
    if (b1)
        cout<<"û�г����������ַ���"<<endl;
    system("pause");
    return 0;

}