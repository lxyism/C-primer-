#include<iostream>
#include<vector>
#include<string>
using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if(!l)  //
        return ;
    auto iter = s.begin();
    while(iter <= s.end() - 1){
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        //s中iter开始的子串必须每个字符都与oldVal相同
        while (iter2 != oldVal.end() && *iter1 == *iter2){
            iter1 ++;
            iter2 ++;
        }
        if (iter2 == oldVal.end()){ //oldVal耗尽————字符串相等
            iter = s.erase(iter, iter1); //删除s中与oldVal相等部分
            if(newVal.size()){
                iter2 = newVal.end();
                do {
                    iter2--;
                    iter = s.insert(iter, *iter2);
                }while (iter2 < newVal.begin());
            }
            iter += newVal.size();
        }else iter++;
    }
}

int main()
{
    string s={"tho thru tho!"};
    replace_string(s,"thru", "through");
    cout<<s<<endl;

    replace_string(s,"tho","though");
    cout<<s<<endl;

    replace_string(s,"through","");
    cout<<s<<endl;

    system("pause");
    return 0;
}