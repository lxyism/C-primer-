#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Foo{
public:
    Foo sorted() &&;        //���� �ɸı����ֵ
    Foo sorted() const &;   //�������κ����͵�Foo
    //Foo��������Ա
private:
    vector<int> data;
};

//������Ϊ��ֵ����˿���ԭַ����
Foo Foo::sorted() &&
{
    cout<<"��ֵ���ð汾"<<endl;
    sort(data.begin(), data.end());
    return *this;
}

//��������const����һ����ֵ���ã�����������Ƕ����ܶ������ԭַ����
Foo Foo::sorted() const &
{
    cout<<"��ֵ���ð汾"<<endl;
    //Foo ret(*this);         //����һ������
    //return ret.sorted();
    return Foo(*this).sorted();
}

int main()
{
    Foo f;
    f.sorted();
    return 0;
}