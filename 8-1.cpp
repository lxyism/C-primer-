#include<iostream>
#include<stdexcept>

using namespace std;
istream& f(istream& in)
{
    int v;
    while (in >> v, !in.eof()){ //ֱ�������ļ���������ֹͣ��ȡ
        if(in.bad())
            throw runtime_error("IO������");
        if (in.fail()){
            cerr<<"���ݴ��������ԣ�"<<endl;
            in.clear();
            in.ignore(1024, "\n");
            continue;
        }
        cout<<v<<endl;
    }
    in.clear();
    return in; 
}

int main()
{
    cout<<"������һЩ��������סctrl+z����"<<endl;
    f(cin);
    system("pause");
    return 0;
}