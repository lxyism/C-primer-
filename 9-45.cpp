#include<iostream>
#include<vector>
#include<string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), 1,' ');
    name.insert(name.begin(), prefix.begin(), prefix.end()); //后面prefix.begin()~prefix.end()表示插入的元素
    name.append(" ");
    name.append(suffix.begin(), suffix.end());//直接在name后面插入suffix.begin()~sufix.end()
}

int main(){
    string s = "James Bond";
    name_string(s, "Mr.", "II");
    cout<<s<<endl;

    s = "M";
    name_string(s, "Mrs.", "III");
    cout<<s<<endl;

    system("pause");
    return 0;
}
