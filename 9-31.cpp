//list��forward_list����������֧�ּӼ�����
 #include<iostream>
// #include<list>

// using namespace std;
// int main()
// {
//     list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
//     auto curr = ilst.begin();
//     while (curr != ilst.end()){
//         if(*curr & 1) //����
//         {
//             curr = ilst.insert(curr, *curr);//���뵽��ǰԪ��֮ǰ
//             curr++;curr++;//�ƶ�����һԪ��
//         }
//         else
//         {
//             curr = ilst.erase(curr); //earse����֮���ָ����һԪ�أ����Բ��ضԵ��������в���
//         }
//     }
//     for (curr = ilst.begin(); curr != ilst.end();curr++)
//         cout<<*curr<<" ";
//     cout<<endl;
//     system("pause");
//     return 0;
//}

#include<forward_list>

using namespace std;
int main()
{
    forward_list<int> iflst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflst.before_begin(); //ǰ�����
    auto curr = iflst.begin();
    while (curr != iflst.end()){
        if(*curr & 1) //����
        {
            curr = iflst.insert_after(curr, *curr);//���뵽��ǰԪ��֮��
            prev = curr;
            curr++;//�ƶ�����һԪ��
        }
        else
        {
            curr = iflst.erase_after(prev); //earse����֮���ָ����һԪ�أ����Բ��ضԵ��������в���
        }
    }
    for (curr = iflst.begin(); curr != iflst.end();curr++)
        cout<<*curr<<" ";
    cout<<endl;
    system("pause");
    return 0;
}