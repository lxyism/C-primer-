#include<iostream>
#include<memory>

using namespace std;

struct desination{};
struct connection{};

connection connect(desination *pd)
{
    cout<<"������"<<endl;
    return connection();
}

void disconnect(connection c)
{
    cout<<"�ر�����"<<endl;
}

//δʹ��shared_ptr�İ汾
void f(desination &d)
{
    cout<<"ֱ�ӹ���connect"<<endl;
    connection c=connect(&d);
    //���ǵ���disconnect�ر�����
    cout<<endl;
}

void end_connection(connection *p) {disconnect (*p);}

//ʹ��shared_ptr�İ汾
void f1(desination &d)
{
    cout<<"��shared_ptr����connect"<<endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    //����desconnect�ر�����
    cout<<endl;
}

int main(int argc, char **argv)
{
    desination d;
    f(d);
    f1(d);
    system("pause");
    return 0;
}