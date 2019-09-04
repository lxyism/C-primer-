#include<iostream>
#include<forward_list>
using namespace std;

void test_and_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
    auto prev = sflst.before_begin();
    auto curr = sflst.begin();
    bool inserted = false;
    while (curr != sflst.end()){
        if (*curr == s1){
            curr = sflst.insert_after(curr, s2); //�������ַ���currָ����
            inserted = true;
        }
        prev =curr;
        curr++;
    }
    if (!inserted)
        sflst.insert_after(prev, s2); //δ�ҵ������ַ���������β��
}
int main()
{
    forward_list<string> sflst = {"Hello", "!", "world", "!"};
    test_and_insert(sflst, "Hello", "���");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout<<*curr<<" ";
    cout<<endl;

    test_and_insert(sflst, "!", "?");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout<<*curr<<" ";
    cout<<endl;

    test_and_insert(sflst, "Bye", "�ټ�");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout<<*curr<<" ";
    cout<<endl;
    system("pause");
    return 0;
}