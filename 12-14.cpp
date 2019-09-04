#include<iostream>
#include<memory>

using namespace std;

struct desination{};
struct connection{};

connection connect(desination *pd)
{
    cout<<"打开连接"<<endl;
    return connection();
}

void disconnect(connection c)
{
    cout<<"关闭连接"<<endl;
}

//未使用shared_ptr的版本
void f(desination &d)
{
    cout<<"直接管理connect"<<endl;
    connection c=connect(&d);
    //忘记调用disconnect关闭连接
    cout<<endl;
}

void end_connection(connection *p) {disconnect (*p);}

//使用shared_ptr的版本
void f1(desination &d)
{
    cout<<"用shared_ptr管理connect"<<endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    //调用desconnect关闭连接
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