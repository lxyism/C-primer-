#include<iostream>
#include<cstring>
//#include<vector>

using namespace std;
int main(){
    string st1,st2;
    bool b1 = true;
    //vector<string> st;
    cout<<"请输入一个字符串！"<<endl;
    //auto it = st.cbegin();
    while( cin>>st1 )
    {
        if(st1 == st2)
        {
            b1 = false;
            cout<<"连续出现的字符串是："<<st1<<endl;
            break;
        }
        //it != st.cend() && *it != *(it+1)
        st2 = st1;
    }
    if (b1)
        cout<<"没有出现连续的字符串"<<endl;
    system("pause");
    return 0;

}