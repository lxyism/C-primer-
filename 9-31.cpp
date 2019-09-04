//list和forward_list，迭代器不支持加减运算
 #include<iostream>
// #include<list>

// using namespace std;
// int main()
// {
//     list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
//     auto curr = ilst.begin();
//     while (curr != ilst.end()){
//         if(*curr & 1) //奇数
//         {
//             curr = ilst.insert(curr, *curr);//插入到当前元素之前
//             curr++;curr++;//移动到下一元素
//         }
//         else
//         {
//             curr = ilst.erase(curr); //earse操作之后会指向下一元素，所以不必对迭代器进行操作
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
    auto prev = iflst.before_begin(); //前驱结点
    auto curr = iflst.begin();
    while (curr != iflst.end()){
        if(*curr & 1) //奇数
        {
            curr = iflst.insert_after(curr, *curr);//插入到当前元素之后
            prev = curr;
            curr++;//移动到下一元素
        }
        else
        {
            curr = iflst.erase_after(prev); //earse操作之后会指向下一元素，所以不必对迭代器进行操作
        }
    }
    for (curr = iflst.begin(); curr != iflst.end();curr++)
        cout<<*curr<<" ";
    cout<<endl;
    system("pause");
    return 0;
}