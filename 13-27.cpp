//�����Լ���ʹ�����ü����汾��HasPtr
#include<iostream>
#include<string>
using namespace std;

class HasPtr{
public:
    //���캯�������µ�string���µļ�����������������Ϊ1
    HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) { }
    HasPtr(const HasPtr &p):ps(p.ps), i(p.i), use(p.use) {++*use; } //�������캯��
    HasPtr& operator=(const HasPtr&);   //������ֵ�����
    HasPtr& operator=(const string&);   //�����µ�string
    string& operator*();    //������
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;    //������¼�ж��ٶ���Ч*ps��Ա
};

HasPtr::~HasPtr()
{
    if(--*use == 0){     //������ü�����Ϊ0
        delete ps;      //�ͷ�string�ڴ�
        delete use;     //�ͷż������ڴ�
    }        
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;     //�����Ҳ������������ü���
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;    //�����ݴ�rhs������������
    i = rhs.i;
    use = rhs.use;
    return *this;
}
HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}
string& HasPtr::operator*()
{
    return *ps;
}
int main(int argc, char **argv)
{
    HasPtr h("hi mom1");
    HasPtr h2 = h;  //δ�����µ�string��h2��hָ����ͬ��string
    h = "hi daad!";
    cout<<"h :"<<*h<<endl;
    cout<<"h2: "<<*h2<<endl;
    return 0;
}